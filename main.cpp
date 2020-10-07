#include "Timer.h"
#include "Task.h"
#include "Mgr.h"
#include "Client.h"
#include "Storage.h"

#include <thread>
#include <fstream>
#include <unistd.h>
#include <map>
#include <string>

int main(int argc, char *argv[]) {
    int *k = new int();
    cout<<"gg "  <<k<<endl;
    //Checkin options storage: mem/db client local/remote output console/file
    int c;
    while ((c = getopt(argc, argv, "s:c:o:")) != -1) {
        switch (c) {
            case 's':
                /*Possible args mem or db*/
                cout <<"Found argument "<<optarg <<endl;
                break;
            case 'c':
                cout <<"Found argument "<<optarg <<endl;
                break;
            case 'o' :
                /*possible args filename*/
                cout <<"Found argument "<<optarg <<endl;
                break;
            default:
                cout<<"Unrecognised option" <<endl;
                break;
        }
    }

    /*Create storage according to flags*/
    /*Storage*/
    Storage *storage = new StorageMap();
    /*Initialization of our task timer*/
    Mgr* manager = &manager->get_instance(storage);
    Client *client = new Client(manager);
    client->run();
    return 0;
}
