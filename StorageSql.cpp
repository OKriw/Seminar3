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
StorageSql ::StorageSql(string name) {}

//INSERT INTO tablename (field1, field2, field3) VALUES (value1, value2, value3);
bool StorageSql :: create_t(Task *task) {
    return true;
};

void StorageSql :: update_t(Task *task) {

}
bool StorageSql :: delete_t(Task *task) {
    return false;
};
Task* StorageSql :: get_t(string name) {
    return nullptr;
};

vector<Task*> StorageSql :: get_all_tasks_t() {
    vector<Task*> task_v;
    return task_v;
};
//закрыть базу
StorageSql ::~StorageSql() {
    sqlite3_close(storage);
};