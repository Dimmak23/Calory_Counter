#include "calculus.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	calculus w;
	w.show();
	return a.exec();
}
