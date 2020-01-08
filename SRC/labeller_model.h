#ifndef LABELLER_MODEL_H
#define LABELLER_MODEL_H

#include <QFileInfoList>
#include <QStringList>
#include <QObject>

#include <string_date_hash.h>

class LabellerModel : public QObject
{

    Q_OBJECT

public:
    enum SortingType
    {
        NameAsc,
        NameDesc,
        DateAsc,
        DateDesc,
        None
    };

    explicit LabellerModel(QObject *parent = 0);

    StringDateHash* getImageFiles();
    QStringList getClassNames();

    QString getAnnotationFile();
    QString getImageDir();
    QString getNameFile();
    QString getSelectedImageFile();

    SortingType getClassListSorting();
    SortingType getImageFilesSorting();

    void updateImageFiles(QFileInfoList newImageFiles);
    void updateClassNames(QStringList newClassNames);

    void addClassName(QString newClassName);

    void updateAnnotationFile(QString newAnnotationFile);
    void updateimageDir(QString newImageDir);
    void updateNameFile(QString newNameFile);
    void updateSelectedImageFile(QString newSelectedImageFile);
    void updateClassListSorting(SortingType newClassListSorting);
    void updateImageFilesSorting(SortingType newImageFilesSorting);

signals:
    void imageFilesChanged();
    void classNamesChanged();
    void annotationFileChanged();
    void imageDirChanged();
    void classFileChanged();
    void classListChangedSorted();
    void imageFilesChangedSorted();
    void selectedImageFileChanged();
    void clearClassItemLineEdit();

private:
    StringDateHash* imageFiles;
    QStringList classNames;

    QString annotationFile;
    QString nameFile;
    QString imageDir;
    QString selectedImageFile;

    SortingType imageFilesSorting;
    SortingType classListSorting;

};

#endif // LABELLER_MODEL_H
