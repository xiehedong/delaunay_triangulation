#pragma once

#include "TrianglationWidget.h"
#include "ui_QtMainWindow.h"
#include<QMainWindow>
#include<QWidget>

class QtMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	QtMainWindow(QWidget *parent = nullptr);
	~QtMainWindow();

private:
	Ui::QtMainWindow ui;

	TrianglationWidget* m_triWidget;
};
