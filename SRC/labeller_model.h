#ifndef LABELLER_MODEL_H
#define LABELLER_MODEL_H

#include <QStringList>
#include <QObject>

class LabellerModel : public QObject
{

    Q_OBJECT

public:
    explicit LabellerModel(QObject *parent = 0);

    QStringList getImageFiles();
    QStringList getClassNames();

    QString getAnnotationFile();
    QString getImageDir();
    QString getNameFile();
    QString getClassListSorting();
    QString getSelectedImageFile();

    void updateImageFiles(QStringList newImageFiles);
    void updateClassNames(QStringList newClassNames);

    void addClassName(QString newClassName);

    void updateAnnotationFile(QString newAnnotationFile);
    void updateimageDir(QString newImageDir);
    void updateNameFile(QString newNameFile);
    void updateClassListSorting(QString newClassListSorting);
    void updateSelectedImageFile(QString newSelectedImageFile);

signals:
    void imageFilesChanged();
    void classNamesChanged();
    void annotationFileChanged();
    void imageDirChanged();
    void classFileChanged();
    void classListChangedSorted();
    void selectedImageFileChanged();
    void clearClassItemLineEdit();

private:
    QStringList imageFiles;
    QStringList classNames;

    QString annotationFile;
    QString nameFile;
    QString imageDir;
    QString classListSorting;
    QString selectedImageFile;
};

#endif // LABELLER_MODEL_H
