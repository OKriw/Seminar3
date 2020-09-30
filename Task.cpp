//
// Created by Olga on 16/09/2020.
//

#include "Task.h"

Task::Task(string tname) {
    state = stopped;
    timer = new Timer();
    name = tname;
    time_spent = "00:00:00";

}
states Task::getState() {
    return state;
};
bool Task::isRunning() {
    if(state == running)
        return true;
    else
        return false;
}
bool Task::isDeleted() {
    if(state == deleted)
        return true;
    else
        return false;
}
bool Task::isStopped() {
    if(state == stopped)
        return true;
    else
        return false;
}
void Task::start(){
    if(state == running)
        cout<<"Error: Task "<<name<<" is already running!"<<"\n";

    if(state == deleted)
        cout<<"Error: Task "<<name<<" is deleted"<<"\n";
    if(state == stopped){
        timer->start_timer();
        state = running;
    }

};
void Task::stop(){
    if(state == stopped)
        cout<<"Error: Task "<<name<<" is already stopped!"<<"\n";

    if(state == deleted)
        cout<<"Error: Task "<<name<<" is deleted"<<"\n";
    if(state == running){
        state = stopped;
        timer->stop_timer();
        time_spent = timer->format_elapsed_time();
    }
};
void Task::delete_t() {
    if(state == running)
        cout<<"Error: Task "<<name<<" is running! You should stop it first"<<"\n";

    if(state == deleted)
        cout<<"Error: Task "<<name<<" is already deleted"<<"\n";
    if(state == stopped){
        state = deleted;
    }
}
void Task::statistics() {
    cout<<"Task "<<name<<" was running for "<<time_spent<<
    "\n"<<"Current status: "<<getState()<<"\n";
}
void Task::clear() {
    timer->clear_timer();
    time_spent = "00:00:00";

}
int Task::time_spend(){
    return timer->get_elapsed_time('s');
};

