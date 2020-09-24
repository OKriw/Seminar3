//
// Created by Olga on 22/09/2020.
//

#include "Mgr.h"
Mgr::Mgr() {curr = nullptr;};
Mgr& Mgr::get_instance() {
    static Mgr *instance = new Mgr();
    return *instance;
};
Task* Mgr:: create(string &name){
    if (curr == nullptr) curr = new Task(name);
};
void Mgr:: start(string name){
    if (curr->isStopped()) curr->start();
    else cout << "Task is not stopped, can't start it" << endl;
};
void Mgr:: stop(string name){
    if (curr->isRunning()) curr->stop();
    else cout << "Task is not running, can't stop it" << endl;
};
void Mgr:: mdelete(string name){
    if (curr->isStopped()) curr->delete_t();
    else cout << "Task is not stopped, can't delete it" << endl;
};
void Mgr:: print(){
    curr->statistics();
};