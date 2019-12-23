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
namespace Ui { class Labeller; }
QT_END_NAMESPACE

class LabellerModel;

class Labeller : public QMainWindow
{
    Q_OBJECT

// Listeners & UI

public:
    Labeller(QWidget *parent = nullptr);
    ~Labeller();

private:
    Ui::Labeller *ui;
    LabellerModel *labellerModel;

    void createListeners();

private slots:
    void setImageList();
    void setClassList();
    void setImageDir();
    void setClassFile();
    void setAnnotationFile();

// Controller methods

private slots:
    void on_imageBrowseButton_clicked();
    void on_classBrowseButton_clicked();

    void on_annotationBrowseButton_clicked();
};
#endif // LABELLER_H
