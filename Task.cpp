//
// Created by Olga on 16/09/2020.
//

#include "Task.h"

Task::Task(string tname) {
    timer = new Timer ();
    name = tname;
    time_spent = "00:00:00";
    state = stopped;
}
states Task::getState() {
    return state;
};
bool Task::isRunning() {
    return state == running;
}
bool Task::isDeleted() {
    return state == deleted;
}
bool Task::isStopped() {
    return state == stopped;
}
void Task::start(){
    timer->start_timer();
    state = running;
};
void Task::stop(){
    timer->stop_timer();
    state = stopped;
    time_spent = timer->format_elapsed_time();
};
void Task::delete_t() {
    state = deleted;
}
void Task::statistics() {
    cout << name << " " << time_spent << endl;
};
void Task::clear() {
    time_spent = "00:00:00";
    timer->clear_timer();
    state = stopped;
};
int Task::time_spend(){
    return timer->get_elapsed_time('s');
};

