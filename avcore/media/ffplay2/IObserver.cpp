//
// Created by ���� on 2021/7/19.
//

#include "IObserver.h"

/**
 * ����
 * @param obs
 */
void IObserver::addRegister(IObserver *obs) {
    if (!obs) {
        LOGE("register error !");
        return;
    }
    mux.lock();
    id = obs->id;
    obss.insert(std::pair<int, IObserver *>(id, obs));
    mux.unlock();
    LOGFMTD("register success ! id=%d", id);
}

/**
 * ֪ͨ�����߽�������
 * @param data
 */
void IObserver::sendAMessage(AMessage data) {
    mux.lock();
    notifyAll(data);
    mux.unlock();
}

void IObserver::delRegister(IObserver *obs) {
    if (!obs) {
        LOGE("unRegister error !");
        return;
    }
    LOGFMTD("unRegister IObserver id=%d", obs->id);
    mux.lock();
    obss.erase(obs->id);
    id = -0;
    obs = NULL;
    mux.unlock();
}

void IObserver::notifyAll(AMessage data) {
    mux.lock();
    map<int, IObserver *>::iterator iter;
    iter = obss.begin();
    while (iter != obss.end()) {
        obss[iter->first]->update(data);//����ʵ�֣����������
        iter++;
    }
    mux.unlock();
}

void IObserver::delAllRegister() {
    LOGFMTD("delAllRegister IObserver start");
    obss.erase(obss.begin(), obss.end());
    LOGFMTD("delAllRegister IObserver end");
}



