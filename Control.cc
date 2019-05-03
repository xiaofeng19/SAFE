#include <windows.h>
#include "Control.h"

Control::Control(){
    map_manager=new GetMap;
    get_data=new GetData;
    person=new Person;
    safe=new Safe;
}

Control::~Control(){
    delete map_manager;
    delete get_data;
    delete person;
    delete safe;
}

void Control::StringToInt(){
    int_to_string.clear();
    for (auto k:string_to_int)
        int_to_string[k.second]=k.first;
}

void Control::Run(){
    map_manager->get_map(map_table,building_map,leave,table);
    map_manager->get_data(string_to_int);
    StringToInt();
    while (true){
        get_data->get(fire_data);
        if (get_data->fire){
            safe->calc(map_table,building_map,fire_data,leave,go_to);
            person->Action(go_to,table);
        }
        else if (get_data->close())
            break;
        Sleep(500);
    }
}
