//
// Created by Olga on 22/09/2020.
//

#include "Mgr.h"
Mgr::Mgr() {
    curr = nullptr;
}
Mgr& Mgr::get_instance(Storage *storage) {
    static Mgr* inst = new Mgr();
    inst->storage = storage;
    return *inst;
}
Task* Mgr:: create(string &name){
    if(curr == nullptr){
        curr = new Task(name);
        storage->create_t(curr);
    }
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
    if(curr->isStopped()){
        curr->start();
    }
}
void Mgr:: stop(){
    if(curr->isStopped())
        cout<<"Task"<< curr->name <<" is already stopped"<<"\n";
    if(curr->isDeleted())
        cout<<"Task"<< curr->name <<" is deleted"<<"\n";
    if(curr->isRunning())
        curr->stop();

}
void Mgr:: mdelete(string name){
    Task* curr_task = storage->get_t(name);
    if(curr_task->isStopped()){
        curr_task->delete_t();
        storage->delete_t(curr);
    }
    if(curr_task->isDeleted())
        cout<<"Task"<< curr_task->name <<" is deleted"<<"\n";

}
void Mgr:: print(string name){
    Task* curr_task = storage->get_t(name);
    if(curr_task == nullptr){
        cout<<"No current task";
    }
    curr_task->statistics();
}



void Mgr::clear(string name) {}
void Mgr::ren(string new_name, string old_name) {}
void Mgr::dump() {}