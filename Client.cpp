//
// Created by Olga on 22/09/2020.
//

#include "Client.h"
#include "Mgr.h"

Client::Client(Mgr* manager) {
    mgr = manager;
}
void Client::run() {
    string command,tn;
    while(true){
        cin>>command;
        if(command=="help")
            cout<<"ha-ha";
        if(command=="quit")
            break;
        if(command=="start"){
            cin>>tn;
            mgr->start(tn);
        }
        if(command=="stop"){
            cin>>tn;
            mgr->stop(tn);
            mgr->print();
        }
    }
}