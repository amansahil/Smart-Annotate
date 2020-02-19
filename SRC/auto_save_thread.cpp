#include "auto_save_thread.h"
#include "labeller.h"

AutoSaveThread::AutoSaveThread(Labeller* newLabeller)
{
    labeller = newLabeller;

    // Starts autosave thread
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(process()));
    timer->start(30000); //time specified in ms
}

void AutoSaveThread::process() {
    labeller->doAutoSave();
}
