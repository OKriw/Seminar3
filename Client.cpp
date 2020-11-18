//
// Created by Olga on 22/09/2020.
//

#include "Client.h"
#include "Mgr.h"

Client::Client(Mgr* manager) {
    mgr = manager;
}
void Client::run() {
    string op=" ";
    while(op != "quit") {
        cin >> op;
        if (op == "help") {
            cout << "* help - displays this message\n"
                    "* start_name - starts given task\n"
                    "* stop_name - stops given task\n"
                    "* stat_name - displays stat for given task or error if task with such name does not exists\n"
                    "* quit - exiting timer\n"
                    "* */";
        }
        else if (op.find("start_", 0, 5) != string::npos) {
            string part = op.substr(6, op.length());
            mgr->create(part);
            mgr->start(op.substr(6, op.length()));
        }


        else if (op.find("stop_", 0, 4) != string::npos) {
            if (mgr->get_curr()->name == op.substr(5, op.length())) {
                mgr->stop();
            } else
                cout << "There is no task with name " << op.substr(5, op.length());
        }
        else if (op.find("stat_", 0, 4) != string::npos) {
            if (mgr->get_curr()->name == op.substr(5, op.length()))
                mgr->print(op.substr(5, op.length()));
            else
                cout << "There is no task with name " << op.substr(5, op.length());
        }
        else if(op != "quit")
            cout << "Unknown command. Use help for more information";

    }

}