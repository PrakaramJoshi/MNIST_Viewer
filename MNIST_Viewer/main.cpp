#include "mnist_viewer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MNIST_Viewer w;
	w.show();
	return a.exec();
}
