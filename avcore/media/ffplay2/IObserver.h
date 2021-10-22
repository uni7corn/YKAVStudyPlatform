//
// Created by ���� on 2021/7/19.
//

#ifndef QTFFPLAYER_IOBSERVER_H
#define QTFFPLAYER_IOBSERVER_H

#include "IThread.h"

//https://github.com/imalimin/FilmKilns/tree/master/src/al_common/thread
struct AMessage {

};

/**
 * �۲���
 * ��Ҫ�ǹ۲� ���������
 */
class IObserver : public IThread {

public:
    int id = 0;
    /**
     * �������ݸ�������
     * ����ʵ��
     * @param data
     */
    virtual void update(AMessage data) {};

    /**
     * ������Ϣ�������ݸ��¾�֪ͨ
     * @param obs
     */
    void addRegister(IObserver *obs = 0);

    /**
     * ȡ������
     * @param obs
     */
    void delRegister(IObserver *obs = 0);

    /**
    * ȡ�����ж���
    * @param obs
    */
    void delAllRegister();

    /**
     * ������Ϣ
     * @param data
     */
    void sendAMessage(AMessage data);

private:
    /**
      * ֪ͨ���еĶ����ߣ����µ����ݲ������߸��¡�
      * @param data
      */
    void notifyAll(AMessage data);

public:
    char *TAG = (char *) ("UnKnown %s");//�۲��� TAG

protected:
    std::map<int,IObserver*> obss;
    mutex mux;//������
};


#endif //QTFFPLAYER_IOBSERVER_H
