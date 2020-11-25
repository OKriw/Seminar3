//
// Created by Olga on 22/09/2020.
//

#ifndef TTIMER_CLIENT_H
#define TTIMER_CLIENT_H

#include "Mgr.h"

/*
 * I want you to implement the easiest version - console client.
 * However, it is not the only option.
 * How the code will differ if the client is remote?
 * Is it actually possible for current realization?*/
class Client {
public:
    Mgr *mgr;

    Client(Mgr *manager);

    /* The single method of our client is run.
     * Yhis is the main loop of out project. We keep spinning and
     * processing requests till Exit command.
     * Today I want you to write command line parser.
     * Olgas-MacBook-Pro:TTimer olga$ ./cmake-build-debug/TTimer -s=storage
     * help - displays this message
     * start task_name - starts given task
     * stop task_name - stops given task
     * stat - task_name/all - display statistics for given task or for all tasks
     * rename new_name old_name - renames the given task. Make sure task is not running.
     * clear task_name  - clears the timer of the given task
     * dump - dumps all tasks info into tasks_dump.txt Make sure that if task is running its timer will be updated.
     * quit - exiting timer
     * */
    void run();
};

#endif //TTIMER_CLIENT_H
