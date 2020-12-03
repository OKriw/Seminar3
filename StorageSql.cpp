//
// Created by Olga on 18/11/2020.
//
#include <string>
#include <map>
#include <stdio.h>
#include "Storage.h"

// Оставляю callback нетронутым.
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


// Конструктор - открыть/моздать базу создать таблицу если нет
StorageSql ::StorageSql(string name) {
    char* err;
    dbname = name;
    sqlite3_open("storage.db", &storage);
    string c = "CREATE TABLE IF NOT EXISTS tasks(task_name TEXT, time INT)";
    int rc = sqlite3_exec(storage, c.c_str(), callback, nullptr, &err);
    if(rc != SQLITE_OK){
        cout<<err;
    }

}

//INSERT INTO tablename (field1, field2, field3) VALUES (value1, value2, value3);
bool StorageSql :: create_t(Task *task) {
    char* err;
    string name = task -> name;
    int time = task -> time_spend();
    string c = "insert into tasks VALUES('"+name+"', "+to_string(time)+")";
    int rc = sqlite3_exec( storage, c.c_str(), callback, nullptr, &err );
    if(rc != SQLITE_OK){
        cout <<sqlite3_errmsg( storage )<<endl;
        return false;
    }
    else
        return true;
};

void StorageSql :: update_t(Task *task) {
    char* err;
    string name = task -> name;
    int time = task -> time_spend();
    string c = "UPDATE tasks SET time = "+to_string(time)+" WHERE task_name = ' "+ name + " ' ";
    int rc = sqlite3_exec( storage, c.c_str(), callback, nullptr, &err );
    if(rc != SQLITE_OK){
        cout<<err;
    }

}
bool StorageSql :: delete_t(Task *task) {
    char* err;
    string name = task->name;
    string c = "DELETE FROM tasks WHERE task_name = '" +name+"'";
    int rc = sqlite3_exec( storage, c.c_str(), callback, nullptr, &err );
    if( rc != SQLITE_OK ){
        cout << err;
        return false;
    }
    else
        return true;

};
Task* StorageSql :: get_t(string name) {
    char* err;
    Task* task;
    string c = "SELECT * FROM tasks WHERE task_name = '"+name+"'";
    int rc = sqlite3_exec( storage, c.c_str(), callback, &task, &err );
    if(rc != SQLITE_OK){
        cout << err;
        return nullptr;
    }
    else
        return task;

};

vector<Task*> StorageSql :: get_all_tasks_t() {
    vector <Task*> tasks;
    char* err;
    string c = " SELECT * FROM tasks";
    int rc = sqlite3_exec(storage, c.c_str(), callback, &tasks, &err);
    return tasks;
};
//закрыть базу
StorageSql ::~StorageSql() {
    sqlite3_close(storage);
};