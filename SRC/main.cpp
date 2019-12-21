#include "labeller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Labeller w;
    w.show();
    return a.exec();
}
