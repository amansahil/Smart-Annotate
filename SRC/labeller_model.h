#ifndef LABELLER_MODEL_H
#define LABELLER_MODEL_H

#include <string_date_hash.h>

#include <QFileInfoList>
#include <QObject>
#include <QStringList>

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

    StringDateHash *getImageFiles() const;

    QStringList getClassNames() const;

    QString getAnnotationFile() const;
    QString getImageDir() const;
    QString getNameFile() const;
    QString getSelectedImageFile() const;
    QString getImageFileResult() const;

    SortingType getClassListSorting() const;
    SortingType getImageFilesSorting() const;

    void updateImageFiles(const QFileInfoList newImageFiles);
    void updateImageFiles(const QString newImageFileResult);
    void updateClassNames(const QStringList newClassNames);

    void addClassName(const QString newClassName);

    void updateAnnotationFile(const QString newAnnotationFile);
    void updateimageDir(const QString newImageDir);
    void updateNameFile(const QString newNameFile);
    void updateSelectedImageFile(const QString newSelectedImageFile);
    void updateClassListSorting(const SortingType newClassListSorting);
    void updateImageFilesSorting(const SortingType newImageFilesSorting);

signals:
    void imageFilesChanged();
    void imageFileResultChanged();
    void classNamesChanged();
    void annotationFileChanged();
    void imageDirChanged();
    void classFileChanged();
    void classListChangedSorted();
    void imageFilesChangedSorted();
    void selectedImageFileChanged();
    void clearClassItemLineEdit();

private:
    StringDateHash *imageFiles;

    QStringList classNames;

    QString annotationFile;
    QString nameFile;
    QString imageDir;
    QString selectedImageFile;
    QString imageFileResult;

    SortingType imageFilesSorting;
    SortingType classListSorting;
};

#endif // LABELLER_MODEL_H
