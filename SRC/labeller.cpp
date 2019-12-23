#include "labeller.h"
#include "ui_labeller.h"
#include "labeller_model.h"

#include <QtWidgets>
#include <QAbstractItemView>

// Listeners & UI

Labeller::Labeller(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Labeller)
{
    ui->setupUi(this);

    // Making both list view uneditable by user
    ui->imageList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->classList->setEditTriggers(QAbstractItemView::NoEditTriggers);

   // Model
   labellerModel = new LabellerModel;

   createListeners();
}

Labeller::~Labeller()
{
    delete ui;
}

void Labeller::setImageList() {
    auto model = new QStringListModel;
    model->setStringList(labellerModel->getImageFiles());
    ui->imageList->setModel(model);
}

void Labeller::setClassList() {
    auto model = new QStringListModel;
    model->setStringList(labellerModel->getClassNames());
    ui->classList->setModel(model);
}

void Labeller::setImageDir() {
    ui->imageDirLabel->setText(labellerModel->getImageDir());
}

void Labeller::setClassFile() {
    ui->classFileLabel->setText(labellerModel->getNameFile());
}

void Labeller::setAnnotationFile() {
    ui->annotationDirLabel->setText(labellerModel->getAnnotationFile());
}

void Labeller::createListeners() {
       connect(labellerModel, SIGNAL(imageFilesChanged()), this, SLOT(setImageList()));
       connect(labellerModel, SIGNAL(classNamesChanged()), this, SLOT(setClassList()));
       connect(labellerModel, SIGNAL(annotationFileChanged()), this, SLOT(setAnnotationFile()));
       connect(labellerModel, SIGNAL(imageDirChanged()), this, SLOT(setImageDir()));
       connect(labellerModel, SIGNAL(classFileChanged()), this, SLOT(setClassFile()));

}

// Controller methods

void Labeller::on_imageBrowseButton_clicked()
{
    QString imageDirectory = QFileDialog::getExistingDirectory(this, "Select Directory");

    labellerModel->updateimageDir(imageDirectory);

    QDir directory(imageDirectory);

    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.bmp";

    QStringList images = directory.entryList(filters);

    labellerModel->updateImageFiles(images);
}

void Labeller::on_classBrowseButton_clicked()
{
    QString nameFile = QFileDialog::getOpenFileName(this, "Select a Names file", nullptr, "Name Files (*.names)");
    QFile file(nameFile);

    QStringList classes;

    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }

    labellerModel->updateNameFile(nameFile);

    QTextStream textStream(&file);

    while(true)
    {
        QString line = textStream.readLine();
        if (line.isNull())
            break;
        else
            classes.append(line);
    }

    labellerModel->updateClassNames(classes);

    file.close();
}

void Labeller::on_annotationBrowseButton_clicked()
{
    QString annotationFile = QFileDialog::getOpenFileName(this, "Select an annotation file", nullptr, "Annotation files (*.annotations)");

    labellerModel->updateAnnotationFile(annotationFile);
}
