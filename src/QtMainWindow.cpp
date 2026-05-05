#include "QtMainWindow.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>

QtMainWindow::QtMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	resize(800, 600);
	auto* central = new QWidget(this);
	auto* layout = new QHBoxLayout(central);
	auto* layoutButton = new QVBoxLayout(central);

	m_triWidget = new TrianglationWidget(this);
	auto* btn_generatePoints = new QPushButton("生成随机点", this);
	auto* btn_clear = new QPushButton("清空屏幕", this);
	auto* btn_trianglation = new QPushButton("德劳内三角化", this);
	layoutButton->addWidget(btn_generatePoints);
	layoutButton->addWidget(btn_trianglation);
	layoutButton->addWidget(btn_clear);
	layout->addItem(layoutButton);
	layout->addStretch();
	layout->addWidget(m_triWidget);
	setCentralWidget(central);

	connect(btn_generatePoints, &QPushButton::clicked, this, [this]() {
		m_triWidget->generateRadomPoints();
		});
	connect(btn_trianglation, &QPushButton::clicked, this, [this]() {
		m_triWidget->doTrianglation();
		});
	connect(btn_clear, &QPushButton::clicked, this, [this]() {
		m_triWidget->clearScreen();
		});

	m_triWidget->clearScreen();
}

QtMainWindow::~QtMainWindow()
{
}
