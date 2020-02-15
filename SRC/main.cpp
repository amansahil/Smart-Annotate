#include "labeller.h"
#include "dark_style.h"

#include <QApplication>
#include <QScrollArea>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Labeller w;

    a.setStyle(new DarkStyle);
    QScrollArea area;
    area.setWidget(&w);
    area.show();

    return a.exec();
}
