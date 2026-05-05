#pragma once

#include "ui_TrianglationWidget.h"
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <QPainter>
#include <QWidget>
#include <vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Delaunay;
typedef K::Point_2 Point;

class TrianglationWidget : public QWidget
{
    Q_OBJECT

public:
    TrianglationWidget(QWidget* parent = nullptr);
    ~TrianglationWidget();

    /// <summary>
    /// 生成随机点
    /// </summary>
    /// <param name="count">随机点数量，默认100</param>
    void generateRadomPoints(int count = 20);

    /// <summary>
    /// 执行三角剖分
    /// </summary>
    void doTrianglation();

    /// <summary>
    /// 清空屏幕
    /// </summary>
    void clearScreen();

protected:
    void paintEvent(QPaintEvent* event);

private:
    void drawPoints(QPainter& painter);
    void drawDelaunay(QPainter& painter);

private:
    Ui::TrianglationWidget ui;

    enum class PaintType
    {
        Invalid,
        Point,
        Delaunay,
        Clear
    };
    PaintType m_paintType;

    Delaunay m_triangulation;
    std::vector<Point> m_points;
};
