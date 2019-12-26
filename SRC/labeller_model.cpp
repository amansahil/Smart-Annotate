#include "labeller_model.h"

LabellerModel::LabellerModel(QObject *parent) : QObject(parent), imageFiles(""), classNames(""), classListSorting("none")
{
}

QStringList LabellerModel::getClassNames()
{
    return classNames;
}

QStringList LabellerModel::getImageFiles()
{
    return imageFiles;
}

QString LabellerModel::getAnnotationFile()
{
    return annotationFile;
}

QString LabellerModel::getNameFile()
{
    return nameFile;
}

QString LabellerModel::getImageDir()
{
    return imageDir;
}

QString LabellerModel::getClassListSorting()
{
    return classListSorting;
}

QString LabellerModel::getSelectedImageFile()
{
    return selectedImageFile;
}

void LabellerModel::updateImageFiles(QStringList newImageFiles)
{
    if (imageFiles != newImageFiles)
    {
        imageFiles = newImageFiles;
        emit imageFilesChanged();
    }
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

void LabellerModel::updateClassListSorting(QString newClassListSorting)
{
    if (classListSorting != newClassListSorting)
    {
        classListSorting = newClassListSorting;
        emit classListChangedSorted();
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
}
