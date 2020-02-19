#ifndef LABELLER_MODEL_H
#define LABELLER_MODEL_H

#include "string_date_hash.h"

#include <QFileInfoList>
#include <QObject>
#include <QStringList>

//! Class for model methods for the main page
class LabellerModel : public QObject
{

    Q_OBJECT

public:
    explicit LabellerModel(QObject *parent = 0);

    //! Sorting type enum to identify type of sorting
    enum SortingType
    {
        NameAsc,  /*!< Sort by name ascended */
        NameDesc, /*!< Sort by name descended */
        DateAsc,  /*!< Sort by date ascended */
        DateDesc, /*!< Sort by date descended */
        None      /*!< No sorting */
    };

    /*!
     *  Returns `imageFiles`
    */
    StringDateHash *getImageFiles() const;

    /*!
     *  Returns `selectedImageFile`
    */
    QString getSelectedImageFile() const;

    /*!
     *  Returns `imageFileResult`
    */
    QString getImageFileResult() const;

    /*!
     *  Returns `annotationFile`
    */
    QString getAnnotationFile() const;

    /*!
     *  Returns `imageDir`
    */
    QString getImageDir() const;

    /*!
     *  Returns `nameFile`
    */
    QString getNameFile() const;

    /*!
     *  Returns `classNames`
    */
    QStringList getClassNames() const;

    /*!
     *  Returns `imageFilesSorting`
    */
    SortingType getClassListSorting() const;

    /*!
     *  Returns `classListSorting`
    */
    SortingType getImageFilesSorting() const;

    /*!
     *  Upadtes `imageFiles`
     *  @param newImageFiles
    */
    void updateImageFiles(const QFileInfoList newImageFiles);

    /*!
     *  Updates `imageFiles`
    */
    void updateImageFiles(const QString newImageFileResult);

    /*!
     *  Updates `selectedImageFile`
     *  @param newSelectedImageFile
    */
    void updateSelectedImageFile(const QString newSelectedImageFile);

    /*!
     *  Updates `annotationFile`
     *  @param newAnnotationFile
    */
    void updateAnnotationFile(const QString newAnnotationFile);

    /*!
     *  Updates `imageDir`
     *  @param newImageDir
    */
    void updateImageDir(const QString newImageDir);

    /*!
     *  Updates `nameFile`
     *  @param newNameFile
    */
    void updateNameFile(const QString newNameFile);

    /*!
     *  Updates `classNames`
     *  @param newClassNames
    */
    void updateClassNames(const QStringList newClassNames);

    /*!
     *  Adds item to `classNames`
     *  @param newClassName
    */
    void addClassName(const QString newClassName);

    /*!
     *  Updates `classListSorting`
     *  @param newClassListSorting
    */
    void updateClassListSorting(const SortingType newClassListSorting);

    /*!
     *  Updates `imageFileResult`
     *  @param newImageFilesSorting
    */
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
    //! Container for the image files from selected directory
    StringDateHash *imageFiles;

    //! Container for the class names from selected class file
    QStringList classNames;

    //! Container for the annotation file path
    QString annotationFile;

    //! Container for the class file path
    QString nameFile;

    //! Container for the image directory path
    QString imageDir;

    //! Container for the selected image file path
    QString selectedImageFile;

    //! Container for the image search list
    QString imageFileResult;

    //! Container for the selected image file sorting
    SortingType imageFilesSorting;

    //! Container for the selected class list sorting
    SortingType classListSorting;
};

#endif // LABELLER_MODEL_H
