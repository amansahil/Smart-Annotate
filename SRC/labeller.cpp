#include "labeller.h"
#include "ui_labeller.h"
#include "labeller_model.h"
#include "image_editor.h"

// Listeners & UI

Labeller::Labeller(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Labeller)
{
    ui->setupUi(this);

    // Making both list view uneditable by user
    ui->imageList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->classList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Model
    labellerModel = new LabellerModel;

    // Custom image editor component
    imageEditor = new ImageEditor;

    // Graphics view config
    ui->graphicsView->setScene(imageEditor);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setSceneRect(0, 0, 781, 651);
    ui->graphicsView->show();

    createListeners();
}

Labeller::~Labeller()
{
    delete ui;
    delete labellerModel;
    delete imageEditor;
}

void Labeller::setImageList()
{
    auto model = new QStringListModel;
    model->setStringList(labellerModel->getImageFiles());
    ui->imageList->setModel(model);
}

void Labeller::setClassList()
{
    auto model = new QStringListModel;

    QStringList classes = labellerModel->getClassNames();
    const QString sorting = labellerModel->getClassListSorting();

    QStringList dscClasses;

    if (sorting == "asc")
    {
        classes.sort();
    }
    else if (sorting == "dsc")
    {
        // Reverse Order class
        classes.sort();
        for (int i = classes.size() - 1; i >= 0; i--)
        {
            dscClasses.append(classes.at(i));
        }
    }

    sorting == "dsc" ? model->setStringList(dscClasses) : model->setStringList(classes);
    ui->classList->setModel(model);
}

void Labeller::setImageDir()
{
    ui->imageDirLabel->setText(labellerModel->getImageDir());
}

void Labeller::setClassFile()
{
    ui->classFileLabel->setText(labellerModel->getNameFile());
}

void Labeller::setAnnotationFile()
{
    ui->annotationDirLabel->setText(labellerModel->getAnnotationFile());
}

void Labeller::setSelectedImageFile()
{
    imageEditor->setImage(labellerModel->getSelectedImageFile());
}

void Labeller::clearClassItemLineEdit() {
    ui->classItemLineEdit->clear();
}

void Labeller::setCursorTypeLabel() {
    const QString cursorType = imageEditor->getCursorType();

    if(cursorType == "draw") 
    {
        ui->cursorLabel->setText("Drawing");
    } 
    else if(cursorType == "addText") 
    {
        ui->cursorLabel->setText("Adding Text");
    } 
    else if(cursorType == "none") 
    {
        ui->cursorLabel->setText("Select Mode");
    } 
    else 
    {
        ui->cursorLabel->setText("None");
    }
}

void Labeller::on_actionMark_Object_triggered()
{
    imageEditor->updateCursorType("draw");
}

void Labeller::on_actionAdd_Text_triggered()
{
    imageEditor->updateCursorType("addText");
}

void Labeller::on_classList_clicked(const QModelIndex &index)
{
    imageEditor->updateClassLabel(ui->classList->currentIndex().data().toString());
}

void Labeller::on_actionSelect_triggered()
{
    imageEditor->updateCursorType("none");
}

void Labeller::on_actionDelete_triggered()
{
    imageEditor->deleteSelectedItem();
}

void Labeller::on_actionCopy_triggered()
{
    imageEditor->copySelectedItem();
}

void Labeller::on_actionPaste_triggered()
{
    imageEditor->pasteSelectedItem();
}

void Labeller::on_clearButton_clicked()
{
    imageEditor->clear();
    imageEditor->setImageToFalse();
    imageEditor->update();
}

void Labeller::createListeners()
{
    connect(labellerModel, SIGNAL(imageFilesChanged()), this, SLOT(setImageList()));
    connect(labellerModel, SIGNAL(classNamesChanged()), this, SLOT(setClassList()));
    connect(labellerModel, SIGNAL(annotationFileChanged()), this, SLOT(setAnnotationFile()));
    connect(labellerModel, SIGNAL(imageDirChanged()), this, SLOT(setImageDir()));
    connect(labellerModel, SIGNAL(classFileChanged()), this, SLOT(setClassFile()));
    connect(labellerModel, SIGNAL(classListChangedSorted()), this, SLOT(setClassList()));
    connect(labellerModel, SIGNAL(selectedImageFileChanged()), this, SLOT(setSelectedImageFile()));
    connect(labellerModel, SIGNAL(clearClassItemLineEdit()), this, SLOT(clearClassItemLineEdit()));
    connect(imageEditor, SIGNAL(cursorTypeChanged()), this, SLOT(setCursorTypeLabel()));
}

// Controller methods

void Labeller::on_imageBrowseButton_clicked()
{
    const QString imageDirectory = QFileDialog::getExistingDirectory(this, "Select Directory");

    labellerModel->updateimageDir(imageDirectory);

    const QDir directory(imageDirectory);

    QStringList filters;
    filters << "*.png"
            << "*.jpg"
            << "*.bmp";

    const QStringList images = directory.entryList(filters);
    labellerModel->updateImageFiles(images);
}

void Labeller::on_classBrowseButton_clicked()
{
    const QString nameFile = QFileDialog::getOpenFileName(this, "Select a Names file", nullptr, "Name Files (*.names)");
    QFile file(nameFile);

    QStringList classes;

    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }

    labellerModel->updateNameFile(nameFile);

    QTextStream textStream(&file);
    while (true)
    {
        QString line = textStream.readLine();
        if (line.isNull())
            break;
        else if (line != "")
            classes.append(line);
    }

    labellerModel->updateClassNames(classes);

    file.close();
}

void Labeller::on_annotationBrowseButton_clicked()
{
    const QString annotationFile = QFileDialog::getOpenFileName(this, "Select an annotation file", nullptr, "Annotation files (*.annotations)");
    labellerModel->updateAnnotationFile(annotationFile);
}

void Labeller::on_addNameItemButton_clicked()
{
    const QString fileName = labellerModel->getNameFile();
    if (fileName == "")
    {
        QMessageBox::warning(this, "Warning", "No file selected");
        return;
    }

    QString itemToAdd = ui->classItemLineEdit->text();
    labellerModel->addClassName(itemToAdd);

    QFile file(fileName);
    if (!file.open(QIODevice::Append | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Could not add to file : " + file.errorString());
        return;
    }

    file.write("\n" + itemToAdd.toUtf8());
    file.close();
}

void Labeller::on_deleteClassItemButton_clicked()
{
    const QString fileName = labellerModel->getNameFile();
    if (fileName == "")
    {
        QMessageBox::warning(this, "Warning", "No file selected");
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Could not delete item from file : " + file.errorString());
        return;
    }

    const int selectedItemIndex = ui->classList->currentIndex().row();

    QStringList classes = labellerModel->getClassNames();
    classes.removeAt(selectedItemIndex);

    file.resize(0);

    QString s;
    QTextStream textStream(&file);
    for (const auto &i : classes)
    {
        s.append(i + "\n");
    }
    textStream << s;

    labellerModel->updateClassNames(classes);

    file.close();
}

void Labeller::on_sortClassAscButton_clicked()
{
    labellerModel->updateClassListSorting("asc");
}

void Labeller::on_sortClassDscButton_clicked()
{
    labellerModel->updateClassListSorting("dsc");
}

void Labeller::on_imageList_clicked(const QModelIndex &index)
{
    const QString imageName = ui->imageList->currentIndex().data().toString();
    const QString fileName = labellerModel->getImageDir() + "/" + imageName;

    labellerModel->updateSelectedImageFile(fileName);
}
