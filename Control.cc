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
    fire.clear();
    for (auto k:fire_data_string)
        fire[string_to_int[k.first]]=k.second;
}

void Control::Run(){
    map_manager->get_map(map_table,building_map,leave,table);
    map_manager->get_data(string_to_int);
    int_to_string.clear();
    for (auto k:string_to_int)
        int_to_string[k.second]=k.first;
    while (true){
        get_data->get(fire_data_string);
        StringToInt();
        if (get_data->fire){
            safe->calc(map_table,building_map,fire,leave,go_to,int_to_string);
            person->Action(go_to,table);
        }
        else if (get_data->close())
            break;
        Sleep(500);
    }
}
