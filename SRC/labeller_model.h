#ifndef LABELLER_MODEL_H
#define LABELLER_MODEL_H

#include <QStringList>
#include <QObject>

class LabellerModel: public QObject
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

    void updateImageFiles(QStringList newImageFiles);
    void updateClassNames(QStringList newClassNames);

    void addClassName(QString newClassName);
    void updateAnnotationFile(QString newAnnotationFile);
    void updateimageDir(QString newImageDir);
    void updateNameFile(QString newNameFile);
    void updateClassListSorting(QString newClassListSorting);

signals:
    void imageFilesChanged();
    void classNamesChanged();
    void annotationFileChanged();
    void imageDirChanged();
    void classFileChanged();
    void classListChangedSorted();

private:
    QStringList imageFiles;
    QStringList classNames;

    QString annotationFile;
    QString nameFile;
    QString imageDir;
    QString classListSorting;
};

#endif // LABELLER_MODEL_H
