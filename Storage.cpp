//
// Created by Olga on 07/10/2020.
//

#include "Storage.h"

StorageMap::StorageMap() {
    cout << "Creating storage" << endl;
}

bool StorageMap :: create_t(Task *task) {
    if (storage[task->name] != nullptr) return false;
    storage[task->name] = task;
    return true;
};
void StorageMap :: update_t(Task *task) {
    storage[task->name] = task;
};
bool StorageMap :: delete_t(Task *task) {
    if (storage[task->name] == nullptr) return false;
    storage[task->name] = nullptr;
    return true;
};
Task* StorageMap :: get_t(string name) {
    return storage[name];
};
vector<Task*> StorageMap :: get_all_tasks_t() {
    vector<Task*> task_v;
    for (const auto& i : storage) {
        if (i.second != nullptr) task_v.push_back(i.second);
    }
    return task_v;
};

StorageMap::~StorageMap() {};