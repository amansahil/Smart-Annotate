#ifndef LABELLER_H
#define LABELLER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Labeller; }
QT_END_NAMESPACE

class Labeller : public QMainWindow
{
    Q_OBJECT

public:
    Labeller(QWidget *parent = nullptr);
    ~Labeller();

private:
    Ui::Labeller *ui;
};
#endif // LABELLER_H
