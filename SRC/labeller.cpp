#include "labeller.h"
#include "ui_labeller.h"
#include <QAbstractItemView>

Labeller::Labeller(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Labeller)
{
    ui->setupUi(this);

    // Making both list view uneditable by user
    ui->imageList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->classList->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Labeller::~Labeller()
{
    delete ui;
}


void Labeller::on_imageBrowseButton_clicked()
{
    QString imageDirectory = QFileDialog::getExistingDirectory(this, "Select Directory");
    ui->imageDirLabel->setText(imageDirectory);

    QDir directory(imageDirectory);

    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.bmp";

    QStringList images = directory.entryList(filters);

    auto model = new QStringListModel;
    model->setStringList(images);
    ui->imageList->setModel(model);
}

void Labeller::on_classBrowseButton_clicked()
{
    QString classFile = QFileDialog::getOpenFileName(this, "Select a Class file", nullptr, "Class Files (*.classes)");
    QFile file(classFile);

    QStringList classes;

    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }

    ui->classFileLabel->setText(classFile);

    QTextStream textStream(&file);

    while(true)
    {
        QString line = textStream.readLine();
        if (line.isNull())
            break;
        else
            classes.append(line);
    }

    auto model = new QStringListModel;
    model->setStringList(classes);
    ui->classList->setModel(model);

    file.close();
}
