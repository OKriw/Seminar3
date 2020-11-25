//
// Created by Olga on 07/10/2020.
//

#ifndef TTIMER_STORAGE_H
#define TTIMER_STORAGE_H

#include <string>
#include <map>
#include <vector>
#include "sqlite3.h"
#include "Task.h"

using std::map;
using std::string;
using std::vector;

class Storage {
    // T *storage;
public:
    virtual  ~Storage() = default;
    virtual bool create_t(Task *task) = 0;
    virtual void update_t(Task *task) = 0;
    virtual bool delete_t(Task *task) = 0;
    virtual Task* get_t(string name) = 0;
    virtual vector<Task*> get_all_tasks_t() = 0;
};

class Creator{
public:
    virtual ~Creator() {};
    virtual Storage *FactoryMethod(string name) const = 0;
};

//class Laptop: public Device
class StorageMap: public Storage {
    map<string, Task*> storage;
public:
    StorageMap();
    bool create_t(Task *task);
    void update_t(Task *task);
    bool delete_t(Task *task);
    Task* get_t(string name);
    vector<Task*> get_all_tasks_t();
    ~StorageMap();
};

class StorageMapCreator : public Creator {
public:
    Storage* FactoryMethod(string name) const override {
        return new StorageMap();
    }
};

class StorageSql: public Storage {
    sqlite3 *storage; //handle for our db
    string dbname;
public:
    StorageSql(string name);
    bool create_t(Task *task);
    void update_t(Task *task);
    bool delete_t(Task *task);
    Task* get_t(string name);
    vector<Task*> get_all_tasks_t();
    ~StorageSql();
};

class StorageSqlCreator : public Creator {
public:
    Storage* FactoryMethod(string name) const override {
        return new StorageSql(name);
    }
};
#endif //TTIMER_STORAGE_H
