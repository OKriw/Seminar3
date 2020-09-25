#include <iostream>
#include "Mgr.h"
#include "Client.h"
int main() {
    /*Если вы все сделаете верно - ваш таймер начнет работать*/
    Mgr* manager = &manager->get_instance();
    Client *client = new Client(manager);
    client->run();
    return 0;
}
