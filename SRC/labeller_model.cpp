#include "labeller_model.h"

LabellerModel::LabellerModel(QObject *parent) : QObject(parent), classNames(""), imageFiles(new StringDateHash), classListSorting(None), imageFilesSorting(None)
{
}

QStringList LabellerModel::getClassNames() { return classNames; }

StringDateHash* LabellerModel::getImageFiles() { return imageFiles; }

QString LabellerModel::getAnnotationFile() { return annotationFile; }

QString LabellerModel::getNameFile() { return nameFile; }

QString LabellerModel::getImageDir() { return imageDir; }

QString LabellerModel::getSelectedImageFile() { return selectedImageFile; }

LabellerModel::SortingType LabellerModel::getClassListSorting() { return classListSorting; }

LabellerModel::SortingType LabellerModel::getImageFilesSorting() { return imageFilesSorting; }

void LabellerModel::updateImageFiles(QFileInfoList newImageFiles)
{
        delete imageFiles;
        imageFiles = new StringDateHash;

        for ( const auto& i : newImageFiles  )
        {
            imageFiles->put(i.fileName(), i.lastModified());
        }
        emit imageFilesChanged();
}

void LabellerModel::updateClassNames(QStringList newClassNames)
{
    if (classNames != newClassNames)
    {
        classNames = newClassNames;
        emit classNamesChanged();
    }
}

void LabellerModel::updateimageDir(QString newImageDir)
{
    if (imageDir != newImageDir)
    {
        imageDir = newImageDir;
        emit imageDirChanged();
    }
}

void LabellerModel::updateNameFile(QString newNameFile)
{
    if (nameFile != newNameFile)
    {
        nameFile = newNameFile;
        emit classFileChanged();
    }
}

void LabellerModel::updateAnnotationFile(QString newAnnotationFile)
{
    if (annotationFile != newAnnotationFile)
    {
        annotationFile = newAnnotationFile;
        emit annotationFileChanged();
    }
}

void LabellerModel::updateClassListSorting(SortingType newClassListSorting)
{
    if (classListSorting != newClassListSorting)
    {
        classListSorting = newClassListSorting;
        emit classListChangedSorted();
    }
}

void LabellerModel::updateImageFilesSorting(SortingType newImageFilesSorting)
{
    if(imageFilesSorting != newImageFilesSorting)
    {
        imageFilesSorting = newImageFilesSorting;
        emit imageFilesChangedSorted();
    }
}

void LabellerModel::updateSelectedImageFile(QString newSelectedImageFile)
{
    if (selectedImageFile != newSelectedImageFile)
    {
        selectedImageFile = newSelectedImageFile;
        emit selectedImageFileChanged();
    }
}

void LabellerModel::addClassName(QString newClassName)
{
    classNames.append(newClassName);
    emit classNamesChanged();
    emit clearClassItemLineEdit();
}
