#ifndef AUTO_SAVE_THREAD_H
#define AUTO_SAVE_THREAD_H

#include "labeller.h"

#include <QObject>
#include <QTimer>

//! A thread worker class that calls save function of label class every 30 seconds
class AutoSaveThread : public QObject
{
    Q_OBJECT

public:
    AutoSaveThread(Labeller *newLabeller);

private:
    Labeller *labeller;

private slots:

    /*!
     *  A slot that calls `doAutoSave` function from the labller class
     */
    void process();
};

#endif // AUTO_SAVE_THREAD_H
