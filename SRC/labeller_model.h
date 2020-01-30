#ifndef LABELLER_MODEL_H
#define LABELLER_MODEL_H

#include <string_date_hash.h>

#include <QFileInfoList>
#include <QObject>
#include <QStringList>

//! Class for model methods for the main page

class LabellerModel : public QObject
{

    Q_OBJECT

public:

    //! Sorting type enum
    enum SortingType
    {
        NameAsc, /*!< Sort by name ascended */
        NameDesc, /*!< Sort by name descended */
        DateAsc, /*!< Sort by date ascended */
        DateDesc, /*!< Sort by date descended */
        None /*!< No sorting */
    };

    explicit LabellerModel(QObject *parent = 0);

    /*!
     *  Returns `imageFiles`
    */
    StringDateHash *getImageFiles() const;

    /*!
     *  Returns `classNames`
    */
    QStringList getClassNames() const;

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
     *  Returns `selectedImageFile`
    */
    QString getSelectedImageFile() const;

    /*!
     *  Returns `imageFileResult`
    */
    QString getImageFileResult() const;

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
     *  Updates `annotationFile`
     *  @param newAnnotationFile
    */
    void updateAnnotationFile(const QString newAnnotationFile);

    /*!
     *  Updates `imageDir`
     *  @param newImageDir
    */
    void updateimageDir(const QString newImageDir);

    /*!
     *  Updates `nameFile`
     *  @param newNameFile
    */
    void updateNameFile(const QString newNameFile);

    /*!
     *  Updates `selectedImageFile`
     *  @param newSelectedImageFile
    */
    void updateSelectedImageFile(const QString newSelectedImageFile);

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
    //! Container for image files from selected directory
    StringDateHash *imageFiles;

    //! Container for class names from selected class file
    QStringList classNames;

    //! Container for annotation file path
    QString annotationFile;

    //! Container for class file path
    QString nameFile;

    //! Container for image directory path
    QString imageDir;

    //! Container for selected image file path
    QString selectedImageFile;

    //! Container for image search list
    QString imageFileResult;

    //! Container for selected image file sorting
    SortingType imageFilesSorting;

    //! Container for selected class list sorting
    SortingType classListSorting;
};

#endif // LABELLER_MODEL_H
