#include <iostream>
#include <windows.h>
#include "Control.h"

using std::cout;
using std::endl;

Control::Control(){
    map_manager=new GetMap;
    get_data=new GetData;
    safe=new Safe;
}

Control::~Control(){
    delete map_manager;
    delete get_data;
    delete safe;
}

void Control::StringToInt(){
    fire.clear();
    for (auto k:fire_data_string)
        fire[sti[k.first]]=k.second;
}

void Control::Run(){
    map_manager->get_map(map_table,building_map,leave,table);
    map_manager->get_data(sti,its);
    while (true){
        get_data->get(fire_data_string);
        StringToInt();
        if (get_data->fire){
            safe->calc(map_table,building_map,fire,leave,go_to,its);
        }
        if (get_data->close())
            break;
        Sleep(500);
    }
}
