#include "TrianglationWidget.h"
#include <QRandomGenerator>
#include <QVector>
#include <algorithm>
#include <stdexcept>

TrianglationWidget::TrianglationWidget(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    setMinimumSize(700, 600);

    m_paintType = PaintType::Invalid;
}

TrianglationWidget::~TrianglationWidget()
{
}

void TrianglationWidget::generateRadomPoints(int count)
{
    m_points.clear();
    //生成不重复的随机点
    auto curWidgetWidth = size().width();
    auto curWidgetHeight = size().height();
    if (curWidgetWidth <= 20 || curWidgetHeight <= 20)
    {
        return;
    }
    //QVector<int> candidatesX(curWidgetWidth - 20 + 1);
    //QVector<int> candidatesY(curWidgetHeight - 20 + 1);
    //std::iota(candidatesX.begin(), candidatesX.end(), 10);
    //std::iota(candidatesY.begin(), candidatesY.end(), 10);
    //QRandomGenerator generator = QRandomGenerator::securelySeeded();
    //std::shuffle(candidatesX.begin(), candidatesX.end(), generator);
    //std::shuffle(candidatesY.begin(), candidatesY.end(), generator);
    //auto vecX = QVector<int>(candidatesX.begin(), candidatesX.begin() + count);
    //auto vecY = QVector<int>(candidatesY.begin(), candidatesY.begin() + count);
    //
    //for (size_t i = 0; i < count; i++)
    //{
    //    m_points.emplace_back(Point(vecX[i], vecY[i]));
    //}
    auto* gen = QRandomGenerator::global();
    for (int i = 0; i < count; ++i) {
        double x = gen->bounded(50, curWidgetWidth - 50);
        double y = gen->bounded(50, curWidgetHeight - 50);
        m_points.emplace_back(x, y);
    }

    m_paintType = PaintType::Point;
    update();
}

void TrianglationWidget::doTrianglation()
{
    m_triangulation.clear();
    m_triangulation.insert(m_points.begin(), m_points.end());

    m_paintType = PaintType::Delaunay;
    update();
}

void TrianglationWidget::clearScreen()
{
    m_paintType = PaintType::Clear;
    update();
}

void TrianglationWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), Qt::white);
    switch (m_paintType)
    {
    case PaintType::Clear:
        break;
    case PaintType::Point:
        drawPoints(painter);
        break;
    case PaintType::Delaunay:
        drawDelaunay(painter);
        drawPoints(painter);
        break;
    default:
        break;
    }
}

void TrianglationWidget::drawPoints(QPainter& painter)
{
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    for (const auto& p : m_points)
    {
        painter.drawEllipse(QPointF(p.x(), p.y()), 3, 3);
    }
}

void TrianglationWidget::drawDelaunay(QPainter& painter)
{
    painter.setPen(QPen(Qt::green, 2));

    if (m_points.empty())
    {
        return;
    }
    for (auto it = m_triangulation.finite_edges_begin(); it != m_triangulation.finite_edges_end(); ++it)
    {
        auto segment = m_triangulation.segment(*it);
        auto p1 = segment.point(0);
        auto p2 = segment.point(1);
        painter.drawLine(QPointF(p1.x(), p1.y()), QPointF(p2.x(), p2.y()));
    }
}
