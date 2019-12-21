#include "labeller.h"
#include "ui_labeller.h"

Labeller::Labeller(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Labeller)
{
    ui->setupUi(this);
}

Labeller::~Labeller()
{
    delete ui;
}

