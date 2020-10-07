//
// Created by Olga on 16/09/2020.
//

#ifndef TTIMER_TASK_H
#define TTIMER_TASK_H

#include "Timer.h"

enum states {
    stopped, //initial state
    running,
    deleted //when we want to delete from the storage
};

class Task {
private:
    class Timer *timer;

    bool isValid(states new_state);

    /*states for state machine*/
    states state;
public:
    string name;
    string time_spent;

    Task(string tname);

    /*вернуть true если задача исполняется*/
    bool isRunning();

    /*вернуть true если задачу остановили*/
    bool isStopped();

    /*вернуть true если задачу удалили*/
    bool isDeleted();

    /* вернуть состояние текущей задачи*/
    states getState();

    // states setState();
    void start();

    void stop();

    void clear();

    void delete_t();

    void statistics();

    int time_spend();

};

#endif //TTIMER_TASK_H
