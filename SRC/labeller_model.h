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

    void updateImageFiles(QStringList newImageFiles);
    void updateClassNames(QStringList newClassNames);

    void updateAnnotationFile(QString newAnnotationFile);
    void updateimageDir(QString newImageDir);
    void updateNameFile(QString newNameFile);

signals:
    void imageFilesChanged();
    void classNamesChanged();
    void annotationFileChanged();
    void imageDirChanged();
    void classFileChanged();

private:
    QStringList imageFiles;
    QStringList classNames;

    QString annotationFile;
    QString nameFile;
    QString imageDir;
};

#endif // LABELLER_MODEL_H
