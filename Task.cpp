//
// Created by Olga on 16/09/2020.
//

#include "Task.h"

Task::Task(string tname) {
    timer = new Timer ();
    name = tname;
    time_spent = "00:00:00";
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
    timer->start_timer();
    time_spent = timer->format_elapsed_time();
};
void Task::stop(){
    timer->stop_timer();
    time_spent = timer->format_elapsed_time();
};
void Task::delete_t() {
}
void Task::statistics() {
    cout << name << " " << time_spent << endl;
};
void Task::clear() {
};
int Task::time_spend(){
    return timer->get_elapsed_time('s');
};

