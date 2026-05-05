#include"QtMainWindow.h"
#include <qapplication.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QtMainWindow window;
	window.show();
	return app.exec();
}