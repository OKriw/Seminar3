//
// Created by Olga on 22/09/2020.
//

#include "Mgr.h"
Mgr::Mgr() {
    curr = NULL;
};
Mgr& Mgr::get_instance() {
    static Mgr* instance = new Mgr();
    return *instance;
};
Task* Mgr:: create(std::string &name){
    if (curr == NULL) {
        curr = new Task(name);
    } else {
        std::cout << "ERROR";
    }
    return curr;
};
void Mgr:: start(std::string name){
    if(curr->isStopped()) {
        curr->start();
    } else {
        std::cout << "ERROR";
    }
};
void Mgr:: stop(std::string name){
    if(curr->isRunning()) {
        curr->stop();
    } else {
        std::cout << "ERROR";
    }
};
void Mgr:: mdelete(std::string name){
    if(curr->isStopped()) {
        curr->delete_t();
    } else {
        std::cout << "ERROR";
    }
};
void Mgr:: print(){
    curr->statistics();
};