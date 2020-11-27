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
    cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    cout << "\n";
    return 0;
}

static int callback_for_select (void *used, int argc, char **argv, char **azColName) {
    int i;
    Task** task = (Task **) used;
    string col1 = "task_name";
    string buffer;
    for(i = 0; i < argc; i++) {
        buffer = string(azColName[i]);
        if (buffer == col1) {
            (*task) = new Task((string)argv[i]);
            (*task)->set_time(atoi(argv[i + 1]));
            break;
        }
    }
    return 0;

}

static int callback_for_getting_tasks (void *used, int argc, char **argv, char **azColName) {
    int i;
    vector<Task*>* tasks = (vector<Task*>*) used;
    Task * task;
    string col1 = "task_name";
    string buffer;
    for(i = 0; i < argc; i++) {
        buffer = string(azColName[i]);
        if (buffer == col1) {
            task = new Task(string(argv[i]));
            task->set_time(atoi(argv[i + 1]));
            break;
        }
    }
    tasks->push_back(task);
    return 0;

}

// Конструктор - открыть/моздать базу создать таблицу если нет
StorageSql ::StorageSql(string name) {
    dbname = name;
    int result = sqlite3_open_v2(name.c_str(), &storage, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
    if (result) {
        cout << "ERROR in opening or creating database\n";
        cout << sqlite3_errmsg(storage) << " " << result << "\n";
    }
    else {
        cout << "Database created or opened successfully\n";
    }
    string command = "create table if not exists tasks (id integer primary key autoincrement, task_name text not null"
                     ", time int not null)";
    char * errmsg = nullptr;
    result = sqlite3_exec(storage, command.c_str(), callback, 0, &errmsg);
    if (result) {
        cout << "ERROR in creating table\n";
        cout << sqlite3_errmsg(storage) << " " << result << "\n";
        sqlite3_free(errmsg);
    }
    else {
        cout << "Table created successfully\n";
    }
}

//INSERT INTO tablename (field1, field2, field3) VALUES (value1, value2, value3);
bool StorageSql :: create_t(Task *task) {
    string name = task->name;
    int time = task->time_spend();
    string command = "insert into tasks values (NULL, '" + name + "', " + to_string(time) + ")";
    char * errmsg = nullptr;
    int result = sqlite3_exec(storage, command.c_str(), callback, 0, &errmsg);
    if (result) {
        cout << "ERROR in inserting task\n";
        cout << sqlite3_errmsg(storage) << " " << result << "\n";
        sqlite3_free(errmsg);
        return false;
    }
    return true;
};

void StorageSql :: update_t(Task *task) {
    string name = task->name;
    int time = task->time_spend();
    string command = "update tasks set time = " + to_string(time) + " where task_name = '" + name + "'";
    char * errmsg = nullptr;
    int result = sqlite3_exec(storage, command.c_str(), callback, 0, &errmsg);
    if (result) {
        cout << "ERROR in updating task\n";
        cout << sqlite3_errmsg(storage) << " " << result << "\n";
        sqlite3_free(errmsg);
    }
}

bool StorageSql :: delete_t(Task *task) {
    string name = task->name;
    string command = "delete from tasks where task_name = '" + name + "'";
    char * errmsg = nullptr;
    int result = sqlite3_exec(storage, command.c_str(), callback, 0, &errmsg);
    if (result) {
        cout << "ERROR in deleting task\n";
        cout << sqlite3_errmsg(storage) << " " << result << "\n";
        sqlite3_free(errmsg);
        return false;
    }
    return true;
};

Task* StorageSql :: get_t(string name) {
    Task* task = nullptr;
    char * errmsg = nullptr;
    string command = "select * from tasks where task_name = '" + name + "'";
    int result = sqlite3_exec(storage, command.c_str(), callback_for_select, &task, &errmsg);
    if (result) {
        cout << "ERROR in getting task\n";
        cout << sqlite3_errmsg(storage) << " " << result << "\n";
        sqlite3_free(errmsg);
    }
    return task;
};

vector<Task*> StorageSql :: get_all_tasks_t() {
    vector<Task*> task_v;
    char * errmsg = nullptr;
    string command = "select * from tasks";
    int result = sqlite3_exec(storage, command.c_str(), callback_for_getting_tasks, &task_v, &errmsg);
    if (result) {
        cout << "ERROR in getting vector of tasks\n";
        cout << sqlite3_errmsg(storage) << " " << result << "\n";
        sqlite3_free(errmsg);
    }
    return task_v;
};
//закрыть базу
StorageSql ::~StorageSql() {
    sqlite3_close(storage);
};