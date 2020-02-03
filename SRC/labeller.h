#ifndef LABELLER_H
#define LABELLER_H

#include <QAbstractItemView>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QStringListModel>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui
{
class Labeller;
}
QT_END_NAMESPACE

class LabellerModel;
class ImageEditor;

//! Class for UI and controller methods for the main page

class Labeller : public QMainWindow
{
    Q_OBJECT

    // Listeners & UI Methods

public:
    Labeller(QWidget *parent = nullptr);
    ~Labeller();

private:
    Ui::Labeller *ui;

    LabellerModel *labellerModel;

    ImageEditor *imageEditor;

    /*!
     *  Initiates all listeners
     */
    void createListeners();

private slots:

    /*!
     *  Populates `imageList`
     */
    void setImageList();

    /*!
     *  Populates `imageList` with the search result
     */
    void setImageListToResult();

    /*!
     *  Populates `classList`
     */
    void setClassList();

    /*!
     *  Sets text for `imageDirLabel`
     */
    void setImageDir();

    /*!
     *  Sets text for `classFileLabel`
     */
    void setClassFile();

    /*!
     *  Sets text for `annotationDirLabel`
     */
    void setAnnotationFile();

    /*!
     *  Sets text for `annotationDirLabel`
     */
    void setSelectedImageFile();

    /*!
     *  Sets text for `cursorLabel`
     */
    void setCursorTypeLabel();

    /*!
     *  Clears value of `classItemLineEdit`
     */
    void clearClassItemLineEdit();

    /*!
     *  Triggered when the mark object option is selected from menu
     */
    void on_actionMark_Object_triggered();

    /*!
     *  Triggered when the add text option is selected from menu
     */
    void on_actionAdd_Text_triggered();

    /*!
     *  Triggered when `classList` is clicked
     */
    void on_classList_clicked();

    /*!
     *  Triggered when the select option is selected from menu
     */
    void on_actionSelect_triggered();

    /*!
     *  Triggered when the delete option is selected from menu
     */
    void on_actionDelete_triggered();

    /*!
     *  Triggered when the copy option is selected from menu
     */
    void on_actionCopy_triggered();

    /*!
     *  Triggered when the paste option is selected from menu
     */
    void on_actionPaste_triggered();

    /*!
     *  Triggered when the `clearButton` is clicked
     */
    void on_clearButton_clicked();

    // Controller methods

private slots
    :
    /*!
     *  Triggered when the `imageBrowseButton` is clicked
     */
    void on_imageBrowseButton_clicked();

    /*!
     *  Triggered when the `classBrowseButton` is clicked
     */
    void on_classBrowseButton_clicked();

    /*!
     *  Triggered when the `annotationBrowseButton` is clicked
     */
    void on_annotationBrowseButton_clicked();

    /*!
     *  Triggered when the `addNameItemButton` is clicked
     */
    void on_addNameItemButton_clicked();

    /*!
     *  Triggered when the `deleteClassItemButton` is clicked
     */
    void on_deleteClassItemButton_clicked();

    /*!
     *  Triggered when the `sortClassAscButton` is clicked
     */
    void on_sortClassAscButton_clicked();

    /*!
     *  Triggered when the `sortClassDscButton` is clicked
     */
    void on_sortClassDscButton_clicked();

    /*!
     *  Triggered when the `imageList` is clicked
     */
    void on_imageList_clicked();

    /*!
     *  Triggered when the `sortImagesAsc` is clicked
     */
    void on_sortImagesAsc_clicked();

    /*!
     *  Triggered when the `sortImagesDsc` is clicked
     */
    void on_sortImagesDsc_clicked();

    /*!
     *  Triggered when the `sortImagesdateAsc` is clicked
     */
    void on_sortImagesdateAsc_clicked();

    /*!
     *  Triggered when the `sortImagesDateDsc` is clicked
     */
    void on_sortImagesDateDsc_clicked();

    /*!
     *  Triggered when the `searchImages` is clicked
     */
    void on_searchImages_clicked();

    /*!
     *  Triggered when the `restoreImages` is clicked
     */
    void on_restoreImages_clicked();

    /*!
     *  Triggered when the `saveButton` is clicked
     */
    void on_saveButton_clicked();
};
#endif // LABELLER_H
