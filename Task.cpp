//
// Created by Olga on 16/09/2020.
//

#include "Task.h"

Task::Task(string tname) {
}
states Task::getState() {
    return (states)0;
};
bool Task::isRunning() {
    return true;
}
bool Task::isDeleted() {
    return true;
}
bool Task::isStopped() {
    return true;
}
void Task::start(){
};
void Task::stop(){
};
void Task::delete_t() {
}
void Task::statistics() {
};
void Task::clear() {
}
int Task::time_spend(){
    return 1;
};

