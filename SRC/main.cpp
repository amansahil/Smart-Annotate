#include "labeller.h"

#include <QApplication>
#include <QScrollArea>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Labeller w;

    QScrollArea area;
    area.setWidget(&w);
    area.show();

    return a.exec();
}
