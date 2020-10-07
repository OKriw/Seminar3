//
// Created by Olga on 22/09/2020.
//

#include "Mgr.h"

Mgr::Mgr() {};

Mgr &Mgr::get_instance(Storage *storage) {
    static Mgr *manager = new Mgr();
    return *manager;
};

Task *Mgr::create(string &name) {
    return nullptr;
};

void Mgr::start(string name) {};

void Mgr::stop() {};

void Mgr::mdelete(string name) {};

void Mgr::print(string name) {};

void Mgr::clear(string name) {};

void Mgr::ren(string new_name, string old_name) {};

void Mgr::dump() {};