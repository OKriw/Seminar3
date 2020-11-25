//
// Created by Olga on 22/09/2020.
//

#ifndef TTIMER_MGR_H
#define TTIMER_MGR_H

#include "Task.h"
#include "Storage.h"
#include <string>
#include <fstream>

using std::string;

class Mgr {
    Task *curr = NULL;
    Mgr();
    Storage *storage;
public:
    static Mgr& get_instance(Storage* storage); //only one instance - look at singleton pattern
    Task* create(string &name);
    /* получить текущую задачу */
    Task* get_curr();
    /* обаботать команду start*/

    void start(string name);

    void stop();

    void mdelete(string name);

    void print(string name);

    void ren(string new_name, string old_name);

    void clear(string name);

    void dump();
};

#endif //TTIMER_MGR_H
