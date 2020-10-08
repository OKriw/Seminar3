//
// Created by Olga on 22/09/2020.
//

#include "Mgr.h"

static Mgr* me = NULL;
Mgr::Mgr() {
    curr=NULL;
};
Mgr& Mgr::get_instance() {
    if(!me)
        me = new Mgr();
    return *me;
};
Task* Mgr:: create(string &name){
    if(!me->curr)
        me->curr = new Task(name);
    return me->curr;
};
void Mgr:: start(string name){
    if(me->curr) {
        if ((me->curr->name == name) && (me->curr->isStopped()))
            me->curr->start();
    }
    else{
        create(name);
        start(name);
    }
};
void Mgr:: stop(string name){
    if((me->curr->name==name)&&(me->curr->isRunning()))
        me->curr->stop();
};
void Mgr:: mdelete(string name){
};
void Mgr:: print(){
    me->curr->print();
};