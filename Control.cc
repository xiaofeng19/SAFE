#include <iostream>
#include <fstream>
#include <windows.h>
#include "Control.h"

using std::cout;
using std::endl;

Control::Control(){
    map_manager=new GetMap;
    get_data=new GetData;
    safe=new Safe;
    person=new Person;
}

Control::~Control(){
    delete map_manager;
    delete get_data;
    delete safe;
    delete person;
}

void Control::StringToInt(){
    fire.clear();
    for (auto k:fire_data_string)
        fire[sti[k.first]]=k.second;
    if (fire[1]||fire[15]||fire[31]){
        fire[1]=true;
        fire[15]=true;
        fire[31]=true;
    }
    if (fire[4]||fire[18]||fire[34]){
        fire[4]=true;
        fire[18]=true;
        fire[34]=true;
    }
    if (fire[11]||fire[27]||fire[43]){
        fire[11]=true;
        fire[27]=true;
        fire[43]=true;
    }
    if (fire[14]||fire[30]||fire[46]){
        fire[14]=true;
        fire[30]=true;
        fire[46]=true;
    }
}

void Control::OutputFire(){
    std::ofstream FX("./OutputData/fx.txt");
    std::ofstream FY("./OutputData/fy.txt");
    for (auto k:fire){
        if (k.second){
            FX<<table[k.first].x-25<<"A";
            FY<<table[k.first].y-25<<"A";
        }
    }
    FX.close();
    FY.close();
}

void Control::Run(){
    map_manager->get_map(map_table,building_map,leave,table);
    map_manager->get_data(sti,its);
    person->GetPerson();
    while (true){
        cout<<"run"<<endl;
        get_data->get(fire_data_string);
        StringToInt();
        cout<<1<<endl;
        if (get_data->fire){
            OutputFire();
            safe->calc(map_table,building_map,fire,leave,go_to,its);
            person->Action(go_to,table);
        }
        if (get_data->close())
            break;
        Sleep(500);
    }
}
