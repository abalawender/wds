#include "dmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DMainWindow w;
    w.show();

    return a.exec();
}
