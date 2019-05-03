#include <fstream>
#include "Person.h"

Person::Person(){}

Person::~Person(){}

void Person::action(unordered_map<int,int>map_table,vector<Edge>building_map,unordered_map<int,int>to;,unordered_map<int,One>table){
    for (One &p:person){
        for (auto k:table){
            if (p.x==k.second.x&&p.y==k.second.y){
                p.x+=dx[to[k.first]];
                p.y+=dy[to[k.first]];
                break;
            }
        }
    }
    WriteLog();
}

void Person::WriteLog(){
    std::ofstream OutputX("./OutputData/x.txt");
    std::ofstream OutputY("./OutputData/y.txt");
    for (int i=0;i<person.size();i++){
        OutputX<<person[i].x;
        OutputY<<person[i].y;
        if (i!=person.size()-1){
            OutputX<<"A";
            OutputY<<"A";
        }
    }
    OutputX.close();
    OutputY.close();
    std::ofstream OutputA("./OutputData/arrow.txt");
}