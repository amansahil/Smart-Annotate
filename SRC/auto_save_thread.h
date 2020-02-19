#ifndef AUTO_SAVE_THREAD_H
#define AUTO_SAVE_THREAD_H

#include <QObject>
#include <QTimer>

class Labeller;

class AutoSaveThread : public QObject
{
    Q_OBJECT

public:
    AutoSaveThread(Labeller* newLabeller);

private:
    Labeller* labeller;

private slots:
    void process();
};

#endif // AUTO_SAVE_THREAD_H
