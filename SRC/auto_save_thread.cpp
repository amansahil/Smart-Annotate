#include "auto_save_thread.h"

AutoSaveThread::AutoSaveThread(Labeller *newLabeller)
{
    labeller = newLabeller;

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(process()));
    timer->start(30000);
}

void AutoSaveThread::process()
{
    labeller->doAutoSave();
}
