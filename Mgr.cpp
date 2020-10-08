//
// Created by Olga on 22/09/2020.
//

#include "Mgr.h"

Mgr::Mgr() {
    curr = nullptr;
};

Mgr& Mgr::get_instance(Storage *storage) {
    static Mgr *manager = new Mgr();
    manager->storage = storage;
    return *manager;
};
Task* Mgr:: create(string &name){
    if (curr != nullptr && curr->isRunning()) {
        curr->stop();
    }
    if (storage->get_t(name) != nullptr) {
        curr = storage->get_t(name);
        return curr;
    }
    curr = new Task(name);
    storage->create_t(curr);
    return curr;
};
void Mgr:: start(string name){
    if (curr->isStopped()) curr->start();
    else cout << "Task is not stopped, can't start it" << endl;
};
void Mgr:: stop(){
    if (curr->isRunning()) curr->stop();
    else cout << "Task is not running, can't stop it" << endl;
};
void Mgr:: mdelete(string name){
    Task* cur_task = storage->get_t(name);
    if (cur_task == nullptr) {
        cout << "Can't delete a task which is not exist\n";
        return;
    }
    if (cur_task->isStopped()) {
        cur_task->delete_t();
        storage->delete_t(curr);
    }
    else cout << "Task is not stopped, can't delete it" << endl;
};
void Mgr:: print(string name){
    if (name == "all") {
        vector<Task*> tasks = storage->get_all_tasks_t();
        for (auto i : tasks) {
            i->statistics();
        }
        return;
    }
    Task* cur_task = storage->get_t(name);
    if (cur_task == nullptr) {
        cout << "Can't give stat of a task which is not exist \n";
        return;
    }
    cur_task->statistics();
};
void Mgr::clear(string name) {
    Task* cur_task = storage->get_t(name);
    if (cur_task != nullptr) cur_task->clear();
    if (cur_task == nullptr) cout << "Can't clear a task which is exist :) \n";
};
void Mgr::ren(string new_name, string old_name) {
    Task* task_old = storage->get_t(old_name);
    if (task_old == nullptr) {
        cout << "Can't rename task which is not exist \n";
        return;
    }
    storage->delete_t(task_old);
    task_old->name = new_name;
    storage->create_t(task_old);
};
void Mgr::dump() {
    ofstream file_out("tasks_dump.txt");
    vector<Task*> tasks = storage->get_all_tasks_t();
    for (auto i : tasks) {
        file_out << i->name << " " << i->time_spent << "\n";
    }
    file_out.close();
};
