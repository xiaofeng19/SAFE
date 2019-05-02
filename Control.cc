#include <unistd.h>
#include "Control.h"

Control::Control(){
    map_manager=new MapManager;
    get_data=new GetData;
    person=new Person;
    safe=new Safe;
    output_data=new OutputData;
}

Control::~Control(){
    delete map_manager;
    delete get_data;
    delete person;
    delete safe;
    delete output_data;
}

void Control::Run(){
    map_manager->get_map(map_table,building_map,leave,table);
    while (true){
        get_data->get(fire_data);
        if (get_data->fire){
            safe->calc(map_table,building_map,fire_data,leave,go_to);
            person->action(go_to,table);
        }
        else if (get_data->close())
            break;
        sleep(0.5);
    }
}