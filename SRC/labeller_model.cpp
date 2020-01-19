#include "labeller_model.h"

LabellerModel::LabellerModel(QObject *parent) : QObject(parent), imageFiles(new StringDateHash), classNames(""), imageFilesSorting(None), classListSorting(None)
{
}

QStringList LabellerModel::getClassNames() const { return classNames; }

StringDateHash *LabellerModel::getImageFiles() const { return imageFiles; }

QString LabellerModel::getImageFileResult() const { return imageFileResult; }

QString LabellerModel::getAnnotationFile() const { return annotationFile; }

QString LabellerModel::getNameFile() const { return nameFile; }

QString LabellerModel::getImageDir() const { return imageDir; }

QString LabellerModel::getSelectedImageFile() const { return selectedImageFile; }

LabellerModel::SortingType LabellerModel::getClassListSorting() const { return classListSorting; }

LabellerModel::SortingType LabellerModel::getImageFilesSorting() const { return imageFilesSorting; }

void LabellerModel::updateImageFiles(const QFileInfoList newImageFiles)
{
    delete imageFiles;
    imageFiles = new StringDateHash;

    for (const auto &i : newImageFiles)
    {
        imageFiles->put(i.fileName(), i.lastModified());
    }
    emit imageFilesChanged();
}

void LabellerModel::updateImageFiles(const QString newImageFileResult)
{
    if (imageFileResult != newImageFileResult)
    {
        imageFileResult = newImageFileResult;
        emit imageFileResultChanged();
    }
}

void LabellerModel::updateClassNames(const QStringList newClassNames)
{
    if (classNames != newClassNames)
    {
        classNames = newClassNames;
        emit classNamesChanged();
    }
}

void LabellerModel::updateimageDir(const QString newImageDir)
{
    if (imageDir != newImageDir)
    {
        imageDir = newImageDir;
        emit imageDirChanged();
    }
}

void LabellerModel::updateNameFile(const QString newNameFile)
{
    if (nameFile != newNameFile)
    {
        nameFile = newNameFile;
        emit classFileChanged();
    }
}

void LabellerModel::updateAnnotationFile(const QString newAnnotationFile)
{
    if (annotationFile != newAnnotationFile)
    {
        annotationFile = newAnnotationFile;
        emit annotationFileChanged();
    }
}

void LabellerModel::updateClassListSorting(const SortingType newClassListSorting)
{
    if (classListSorting != newClassListSorting)
    {
        classListSorting = newClassListSorting;
        emit classListChangedSorted();
    }
}

void LabellerModel::updateImageFilesSorting(const SortingType newImageFilesSorting)
{
    if (imageFilesSorting != newImageFilesSorting)
    {
        imageFilesSorting = newImageFilesSorting;
        emit imageFilesChangedSorted();
    }
}

void LabellerModel::updateSelectedImageFile(const QString newSelectedImageFile)
{
    if (selectedImageFile != newSelectedImageFile)
    {
        selectedImageFile = newSelectedImageFile;
        emit selectedImageFileChanged();
    }
}

void LabellerModel::addClassName(const QString newClassName)
{
    classNames.append(newClassName);
    emit classNamesChanged();
    emit clearClassItemLineEdit();
}
