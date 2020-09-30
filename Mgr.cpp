//
// Created by Olga on 22/09/2020.
//

#include "Mgr.h"
Mgr::Mgr() {
    curr = nullptr;
};
Mgr& Mgr::get_instance() {
    static Mgr* inst = new Mgr();
    return *inst;
}
Task* Mgr:: create(string &name){
    if(curr == nullptr)
        curr = new Task(name);
    else
        std::cout<<"You have already started another task, named "<<curr->name<<"\n";
    return curr;
}


Task* Mgr:: get_curr() {
    return curr;
}

void Mgr:: start(string name){
    if(curr->isRunning())
        cout<<"Task"<< curr->name <<" is already running"<<"\n";
    if(curr->isDeleted())
        cout<<"Task"<< curr->name <<" is deleted"<<"\n";
    if(curr->isStopped())
        curr->start();
};
void Mgr:: stop(string name){
    if(curr->isStopped())
        cout<<"Task"<< curr->name <<" is already stopped"<<"\n";
    if(curr->isDeleted())
        cout<<"Task"<< curr->name <<" is deleted"<<"\n";
    if(curr->isRunning())
        curr->stop();

};
void Mgr:: mdelete(string name){
    if(curr->isStopped())
        cout<<"Task"<< curr->name <<" is already stopped"<<"\n";
    if(curr->isDeleted())
        cout<<"Task"<< curr->name <<" is deleted"<<"\n";
    if(curr->isDeleted())
        curr->delete_t();

};
void Mgr:: print(){
    curr->statistics();
};