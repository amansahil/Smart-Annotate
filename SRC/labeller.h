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

class Labeller : public QMainWindow
{
    Q_OBJECT

public:
    Labeller(QWidget *parent = nullptr);
    ~Labeller();

private slots:
    void on_imageBrowseButton_clicked();

    void on_classBrowseButton_clicked();

private:
    Ui::Labeller *ui;
};
#endif // LABELLER_H
