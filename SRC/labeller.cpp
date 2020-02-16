#include "image_editor.h"
#include "labeller.h"
#include "labeller_model.h"
#include "ui_labeller.h"

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
    ui->graphicsView->show();

    // Hide connect button
    ui->connectButton->setVisible(false);
    ui->clearPoints->setVisible(false);

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
    QStringList imageFiles;

    const LabellerModel::SortingType sortingOption = labellerModel->getImageFilesSorting();

    if (sortingOption == LabellerModel::SortingType::NameAsc)
    {
        imageFiles = labellerModel->getImageFiles()->sortByKeyAsc();
    }
    else if (sortingOption == LabellerModel::SortingType::NameDesc)
    {
        imageFiles = labellerModel->getImageFiles()->sortByKeyDesc();
    }
    else if (sortingOption == LabellerModel::SortingType::DateAsc)
    {
        imageFiles = labellerModel->getImageFiles()->sortByDateAsc();
    }
    else if (sortingOption == LabellerModel::SortingType::DateDesc)
    {
        imageFiles = labellerModel->getImageFiles()->sortByDateDesc();
    }
    else
    {
        imageFiles = labellerModel->getImageFiles()->getKeys();
    }

    model->setStringList(imageFiles);

    ui->imageList->setModel(model);
}

void Labeller::setImageListToResult()
{
    auto model = new QStringListModel;
    model->setStringList({labellerModel->getImageFileResult()});

    ui->imageList->setModel(model);
}

void Labeller::setClassList()
{
    auto model = new QStringListModel;

    QStringList classes = labellerModel->getClassNames();
    const LabellerModel::SortingType sorting = labellerModel->getClassListSorting();

    QStringList dscClasses;

    if (sorting == LabellerModel::NameAsc)
    {
        classes.sort();
    }
    else if (sorting == LabellerModel::NameDesc)
    {
        // Reverse Order class
        classes.sort();
        for (int i = classes.size() - 1; i >= 0; i--)
        {
            dscClasses.append(classes.at(i));
        }
    }

    sorting == LabellerModel::NameDesc ? model->setStringList(dscClasses) : model->setStringList(classes);
    ui->classList->setModel(model);
}

void Labeller::setImageDir() { ui->imageDirLabel->setText(labellerModel->getImageDir()); }

void Labeller::setClassFile() { ui->classFileLabel->setText(labellerModel->getNameFile()); }

void Labeller::setAnnotationFile() { ui->annotationDirLabel->setText(labellerModel->getAnnotationFile()); }

void Labeller::setSelectedImageFile() { imageEditor->setImage(labellerModel->getSelectedImageFile()); }

void Labeller::setCursorTypeLabel()
{
    const ImageEditor::CursorType cursorType = imageEditor->getCursorType();

    if (cursorType == ImageEditor::CursorType::Draw)
    {
        ui->cursorLabel->setText("Drawing");
    }
    else if (cursorType == ImageEditor::CursorType::Text)
    {
        ui->cursorLabel->setText("Adding Text");
    }
    else if (cursorType == ImageEditor::CursorType::Select)
    {
        ui->cursorLabel->setText("Select Mode");
    }
    else
    {
        ui->cursorLabel->setText("None");
    }
}

void Labeller::setShapeTypeLabel()
{
    const ImageEditor::AnnotationShapeType annotationShapeType = imageEditor->getAnnotationShapeType();

    if (annotationShapeType == ImageEditor::AnnotationShapeType::FreeHand)
    {
        ui->shapeLabel->setText("Smart Annotate");
        ui->connectButton->setVisible(false);
        ui->clearPoints->setVisible(false);
    }
    else if (annotationShapeType == ImageEditor::AnnotationShapeType::Points)
    {
        ui->shapeLabel->setText("Smart Click");
        ui->connectButton->setVisible(true);
        ui->clearPoints->setVisible(true);
    }
    else
    {
        ui->shapeLabel->setText("Reactangle");
        ui->connectButton->setVisible(false);
        ui->clearPoints->setVisible(false);
    }
}

void Labeller::clearClassItemLineEdit() { ui->classItemLineEdit->clear(); }

void Labeller::setCursorToCross() { ui->graphicsView->viewport()->setCursor(Qt::CrossCursor); }

void Labeller::setCursorToArrow() { ui->graphicsView->viewport()->setCursor(Qt::ArrowCursor); }

void Labeller::createListeners()
{
    connect(labellerModel, SIGNAL(imageFilesChanged()), this, SLOT(setImageList()));
    connect(labellerModel, SIGNAL(imageFileResultChanged()), this, SLOT(setImageListToResult()));
    connect(labellerModel, SIGNAL(classNamesChanged()), this, SLOT(setClassList()));
    connect(labellerModel, SIGNAL(annotationFileChanged()), this, SLOT(setAnnotationFile()));
    connect(labellerModel, SIGNAL(imageDirChanged()), this, SLOT(setImageDir()));
    connect(labellerModel, SIGNAL(classFileChanged()), this, SLOT(setClassFile()));
    connect(labellerModel, SIGNAL(classListChangedSorted()), this, SLOT(setClassList()));
    connect(labellerModel, SIGNAL(imageFilesChangedSorted()), this, SLOT(setImageList()));
    connect(labellerModel, SIGNAL(selectedImageFileChanged()), this, SLOT(setSelectedImageFile()));
    connect(labellerModel, SIGNAL(clearClassItemLineEdit()), this, SLOT(clearClassItemLineEdit()));
    connect(imageEditor, SIGNAL(cursorTypeChanged()), this, SLOT(setCursorTypeLabel()));
    connect(imageEditor, SIGNAL(annotationShapeChanged()), this, SLOT(setShapeTypeLabel()));
    connect(imageEditor, SIGNAL(drawingRectangle()), this, SLOT(setCursorToCross()));
    connect(imageEditor, SIGNAL(finishedDrawingRectangle()), this, SLOT(setCursorToArrow()));
}

QPointF Labeller::parsePoint(QString point)
{
    point.remove(QRegularExpression("[()*]"));

    QStringList points = point.split(",");

    return points.size() == 2 ? QPointF(points[0].toInt(), points[1].toInt()) : QPointF(0,0);
}

// Controller methods

void Labeller::on_imageBrowseButton_clicked()
{
    const QString imageDirectory = QFileDialog::getExistingDirectory(this, "Select Directory");

    labellerModel->updateImageDir(imageDirectory);

    const QDir directory(imageDirectory);

    QStringList filters;
    filters << "*.png"
            << "*.jpg"
            << "*.bmp"
            << "*.jpeg";

    const QFileInfoList images = directory.entryInfoList(filters);
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


    // Open and load file conents
    QFile file(annotationFile);
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }

    QString values = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(values.toUtf8());
    QJsonObject jsonObject = document.object();

    QJsonArray imagesArray = jsonObject["Images"].toArray();

    for(const QJsonValue &image: imagesArray)
    {
        QList<QRectF> rectItems;
        QList<QPolygonF> polygonItems;
        QList<QPair<QString, QPointF>> textItems;

        QString fileName = image["File Name"].toString();
        QJsonArray shapesArray = image["Shapes"].toArray();

        for(const QJsonValue &shape: shapesArray)
        {
            QString shapeType = shape["Shape Type"].toString();

            if(shapeType == "Rectangle")
            {
                const QPointF topLeft = parsePoint(shape["Point_1"].toString());
                const QPointF bottomRight = parsePoint(shape["Point_4"].toString());

                const QRectF newRectItem(topLeft, bottomRight);
                rectItems.append(newRectItem);
            }
            else if(shapeType == "Text")
            {
                QPair<QString, QPointF> newTextItem;

                newTextItem.first = shape["Text"].toString();
                newTextItem.second = parsePoint(shape["Point"].toString());

                textItems.append(newTextItem);
            }
            else if(shapeType == "Polygon")
            {
                QPolygonF newPolygonItem;

                QJsonArray pointsArray = shape["Points"].toArray();

                for(const QJsonValue &point: pointsArray)
                {
                    newPolygonItem << parsePoint(point.toString());
                }

                polygonItems.append(newPolygonItem);
            }

            imageEditor->updateApplicationRectState(fileName, rectItems);
            imageEditor->updateApplicationTextState(fileName, textItems);
            imageEditor->updateApplicationPolygonState(fileName, polygonItems);
        }

        imageEditor->forceReload();
    }
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

    if (!itemToAdd.trimmed().isEmpty())
    {
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

    QStringList classes = labellerModel->getClassNames();

    for (int i = 0; i <= classes.length() - 1; i++)
    {
        if (classes.at(i) == ui->classList->currentIndex().data().toString())
            classes.removeAt(i);
    }

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

void Labeller::on_sortClassAscButton_clicked() { labellerModel->updateClassListSorting(LabellerModel::SortingType::NameAsc); }

void Labeller::on_sortClassDscButton_clicked() { labellerModel->updateClassListSorting(LabellerModel::SortingType::NameDesc); }

void Labeller::on_imageList_clicked()
{
    const QString imageName = ui->imageList->currentIndex().data().toString();
    const QString fileName = labellerModel->getImageDir() + "/" + imageName;

    labellerModel->updateSelectedImageFile(fileName);
}

void Labeller::on_sortImagesAsc_clicked() { labellerModel->updateImageFilesSorting(LabellerModel::SortingType::NameAsc); }

void Labeller::on_sortImagesDsc_clicked() { labellerModel->updateImageFilesSorting(LabellerModel::SortingType::NameDesc); }

void Labeller::on_sortImagesdateAsc_clicked() { labellerModel->updateImageFilesSorting(LabellerModel::SortingType::DateAsc); }

void Labeller::on_sortImagesDateDsc_clicked() { labellerModel->updateImageFilesSorting(LabellerModel::SortingType::DateDesc); }

void Labeller::on_restoreImages_clicked()
{
    labellerModel->updateImageFilesSorting(LabellerModel::SortingType::None);
    labellerModel->updateImageFiles("");

    // Force update image list
    setImageList();
}

void Labeller::on_searchImages_clicked()
{
    const QString imageToSearch = ui->imageLineEdit->text();

    QDateTime dateTime;

    const bool exist = labellerModel->getImageFiles()->get(imageToSearch, dateTime);

    if (exist)
    {
        labellerModel->updateImageFiles(imageToSearch);
    }
    else
    {
        QMessageBox::warning(this, "Oops", "Could not find a file named: \"" + imageToSearch + "\"");
    }
}

void Labeller::on_saveButton_clicked()
{
    imageEditor->saveImageState();

    QHash<QString, QList<QRectF>> applicationRectState = imageEditor->getApplicationRectState();

    QHash<QString, QList<QPolygonF>> applicationPolygonState = imageEditor->getApplicationPolygonState();

    QHash<QString, QList<QPair<QString, QPointF>>> applicationTextState = imageEditor->getApplicationTextState();

    QList<QString> allNames;

    // Get all files names
    allNames.append(applicationRectState.keys());
    allNames.append(applicationPolygonState.keys());
    allNames.append(applicationTextState.keys());

    QSet<QString> uniqueNames;

    // Populates container with only unique filenames to avoid overlap
    for(const QString &e: allNames) {
        uniqueNames.insert(e);
    }

    QJsonObject annotationsRecord;
    annotationsRecord.insert("Number of annotated image", QJsonValue::fromVariant(uniqueNames.size()));

    QJsonArray imagesArray;

    for(const QString &fileName: uniqueNames) {
        QJsonObject imageObject;
        const int numberOfObjects = applicationRectState.value(fileName).count() + applicationTextState.value(fileName).count() + applicationPolygonState.value(fileName).count();

        imageObject.insert("File Name", QJsonValue::fromVariant(fileName));
        imageObject.insert("Number of shapes", QJsonValue::fromVariant(numberOfObjects));

        QJsonArray shapesArray;

        for (int i = 0; i < applicationRectState.value(fileName).count(); i++)
        {

            QJsonObject shapeObject;
            QRectF currRect = applicationRectState.value(fileName).at(i);

            QString topLeft = "(" + QString::number(currRect.topLeft().x()) + ","+ QString::number(currRect.topLeft().y()) + ")";
            QString topRight = "(" + QString::number(currRect.topRight().x()) + ","+ QString::number(currRect.topRight().y()) + ")";
            QString bottomLeft = "(" + QString::number(currRect.bottomLeft().x()) + ","+ QString::number(currRect.bottomLeft().y()) + ")";
            QString bottomRight = "(" + QString::number(currRect.bottomRight().x()) + ","+ QString::number(currRect.bottomRight().y()) + ")";

            shapeObject.insert("Shape Type", QJsonValue::fromVariant("Rectangle"));
            shapeObject.insert("Point_1", QJsonValue::fromVariant(topLeft));
            shapeObject.insert("Point_2", QJsonValue::fromVariant(topRight));
            shapeObject.insert("Point_3", QJsonValue::fromVariant(bottomLeft));
            shapeObject.insert("Point_4", QJsonValue::fromVariant(bottomRight));

            shapesArray.push_back(shapeObject);
        }

        for (int i = 0; i < applicationTextState.value(fileName).count(); i++)
        {
            QJsonObject shapeObject;
            QPair<QString, QPointF> currText = applicationTextState.value(fileName).at(i);

            QString pos = "(" + QString::number(currText.second.x()) + ","+ QString::number(currText.second.y()) + ")";

            shapeObject.insert("Shape Type", QJsonValue::fromVariant("Text"));
            shapeObject.insert("Text", QJsonValue::fromVariant(currText.first));
            shapeObject.insert("Point", QJsonValue::fromVariant(pos));

            shapesArray.push_back(shapeObject);
        }

        for (int i = 0; i < applicationPolygonState.value(fileName).count(); i++)
        {
            QJsonObject shapeObject;
            QPolygonF currPoly = applicationPolygonState.value(fileName).at(i);

            shapeObject.insert("Shape Type", QJsonValue::fromVariant("Polygon"));

            QJsonArray pointArray;


            int j = 1;
            for(const QPointF &point: currPoly)
            {
                QJsonObject pointObject;
                QString pos = "(" + QString::number(point.x()) + ","+ QString::number(point.y()) + ")";

                pointArray.push_back(pos);
                shapeObject.insert("Points", pointArray);

                j++;
            }

            shapesArray.push_back(shapeObject);
        }

        imageObject.insert("Shapes", shapesArray);
        imagesArray.push_back(imageObject);
    }

    annotationsRecord.insert("Images", imagesArray);

    QJsonDocument document(annotationsRecord);

    QString fileName;

    if(!labellerModel->getAnnotationFile().isEmpty() && !labellerModel->getAnnotationFile().isNull())
    {
        fileName = labellerModel->getAnnotationFile();
    }
    else
    {
        // Define path, name and default file type
        QString initialPath = QDir::currentPath() + "/untitled.annotations";

        fileName = QFileDialog::getSaveFileName(this, tr("Save As"), initialPath);

        labellerModel->updateAnnotationFile(fileName);
    }

    if(fileName.isEmpty())
    {
        return;
    }
    else
    {
        QFile jsonFile(fileName);
        if(!jsonFile.open(QIODevice::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this, "Warning", "Cannot save to file : " + jsonFile.errorString());
            return;
        }
        jsonFile.write(document.toJson());
        jsonFile.close();
    }
}

void Labeller::on_actionMark_Object_triggered() { imageEditor->updateCursorType(ImageEditor::CursorType::Draw); }

void Labeller::on_actionAdd_Text_triggered() { imageEditor->updateCursorType(ImageEditor::CursorType::Text); }

void Labeller::on_classList_clicked()
{
    imageEditor->updateCursorType(ImageEditor::CursorType::Text);
    imageEditor->updateClassLabel(ui->classList->currentIndex().data().toString());
}

void Labeller::on_actionSelect_triggered() { imageEditor->updateCursorType(ImageEditor::CursorType::Select); }

void Labeller::on_actionDelete_triggered() { imageEditor->deleteSelectedItem(); }

void Labeller::on_actionCopy_triggered() { imageEditor->copySelectedItem(); }

void Labeller::on_actionPaste_triggered() { imageEditor->pasteSelectedItem(); }

void Labeller::on_clearButton_clicked() { imageEditor->clearItems(); }

void Labeller::on_actionRectangle_triggered() { imageEditor->updateAnnotationShapeType(ImageEditor::AnnotationShapeType::Rectangle); }

void Labeller::on_actionSmart_annotate_triggered() { imageEditor->updateAnnotationShapeType(ImageEditor::AnnotationShapeType::FreeHand); }

void Labeller::on_actionSmart_Click_triggered() { imageEditor->updateAnnotationShapeType(ImageEditor::AnnotationShapeType::Points); }

void Labeller::on_connectButton_clicked() { imageEditor->connectClickElipses(); }

void Labeller::on_clearPoints_clicked() { imageEditor->deleteClickElipses(); }
