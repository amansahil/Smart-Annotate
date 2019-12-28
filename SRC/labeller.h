#ifndef LABELLER_H
#define LABELLER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringListModel>
#include <QAbstractItemView>

QT_BEGIN_NAMESPACE
namespace Ui
{
class Labeller;
}
QT_END_NAMESPACE

class LabellerModel;
class ImageEditor;

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

    void createListeners();

private slots:
    void setImageList();
    void setClassList();
    void setImageDir();
    void setClassFile();
    void setAnnotationFile();
    void setSelectedImageFile();
    void setCursorTypeLabel();
    void clearClassItemLineEdit();
    void on_actionMark_Object_triggered();
    void on_actionAdd_Text_triggered();
    void on_classList_clicked();
    void on_actionSelect_triggered();
    void on_actionDelete_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_clearButton_clicked();

    // Controller methods

private slots:
    void on_imageBrowseButton_clicked();
    void on_classBrowseButton_clicked();
    void on_annotationBrowseButton_clicked();
    void on_addNameItemButton_clicked();
    void on_deleteClassItemButton_clicked();
    void on_sortClassAscButton_clicked();
    void on_sortClassDscButton_clicked();
    void on_imageList_clicked();
};
#endif // LABELLER_H
