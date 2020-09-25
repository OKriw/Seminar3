//
// Created by Olga on 22/09/2020.
//

#ifndef TTIMER_CLIENT_H
#define TTIMER_CLIENT_H

#include "Mgr.h"
class Client {
public:
    Mgr *mgr;
    Client(Mgr* manager);
    /* Единственный метод этого класса метод run.
     * Он взаимодействует с пользователем -  принимает команды, пасит их и
     * передает менеджеру.
     * help - displays this message
     * start task_name - starts given task
     * stop task_name - stops given task
     * stat - displays statistics
     * stat name - displays stat for given task or error if task with such name does not exists
     * quit - exiting timer
     * */
    void run();
};
#endif //TTIMER_CLIENT_H
