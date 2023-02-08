#ifndef _WORKER_THREAD_H
#define _WORKER_THREAD_H

#include <QThread>

class WorkerThread : public QThread {
	Q_OBJECT

public:
		WorkerThread(QObject *parent);
		virtual ~WorkerThread();

public:
		virtual void run();
};

#endif // _WORKER_THREAD_H

