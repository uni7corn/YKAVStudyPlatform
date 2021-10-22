//
// Created by ���� on 2021/7/19.
//

#ifndef QTFFPLAYER_ITHREAD_H
#define QTFFPLAYER_ITHREAD_H

#include <thread>
#include <vector>
#include <chrono>
#include "log4z.h"
#include <mutex>

using namespace zsummer::log4z;
using namespace std;

//sleep ����
void Sleep(int mis);

void *Main(void *p);

/**
 * ͳһ�����߳�
 */
class IThread {
public:
    //�����߳�
    virtual bool start();

    //�߳��ͷ�
    virtual void release();

    //���߳����
    virtual void *run() = 0;

private:
    pthread_t tid;

    mutex thread_mutex;
};


#endif //QTFFPLAYER_ITHREAD_H
