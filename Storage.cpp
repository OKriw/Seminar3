//
// Created by Olga on 07/10/2020.
//

#include "Storage.h"
StorageMap ::StorageMap() {
    cout << "Creating storage" <<endl;
}
bool StorageMap :: create_t(Task *task) {
    return false;
};
void StorageMap :: update_t(Task *task) {};
bool StorageMap :: delete_t(Task *task) {
    return false;
};
Task* StorageMap :: get_t(string name) {
    return nullptr;
};
vector<Task*> StorageMap :: get_all_tasks_t() {
    vector<Task*> task_v;
    return task_v;
};
StorageMap ::~StorageMap() {};