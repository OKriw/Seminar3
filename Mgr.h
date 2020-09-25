//
// Created by Olga on 22/09/2020.
//

#ifndef TTIMER_MGR_H
#define TTIMER_MGR_H
#include "Task.h"
#include <string>

using std::string;

class Mgr {
    /*Указатель на текущую задачу*/
    Task* curr;
    Mgr();
public:
    /* получить экземпляр класса*/
    static Mgr& get_instance();
    /* обаботать команду create*/
    Task* create(string &name);
    /* обаботать команду start*/
    void start(string name);
    /* обаботать команду stop*/
    void stop(string name);
    /* обаботать команду mdelete*/
    void mdelete(string name);
    /* обаботать команду print*/
    void print();
};
#endif //TTIMER_MGR_H
