//
// Created by Olga on 16/09/2020.
//

#include "Task.h"

Task::Task(string tname) {
    name = tname;
    timer = new Timer;
    state = stopped;
};
Task::~Task(){
    delete timer;
};

states Task::getState() {
    return state;
};
bool Task::isRunning() {
    return state==running;
};
bool Task::isDeleted() {
    return state==deleted;
};
bool Task::isStopped() {
    return state==stopped;
};
void Task::start(){
    state = running;
    timer->start_timer();
};
void Task::stop(){
    timer->stop_timer();
    state=stopped;
    time_spent = timer->format_elapsed_time();
};
void Task::delete_t() {
};
void Task::statistics() {
};
void Task::clear() {
    timer->clear_timer();
    time_spent = timer->format_elapsed_time();
};
int Task::time_spend(){
    return timer->get_elapsed_time('s');
};
void Task::print() {
    timer->print_time();
}

