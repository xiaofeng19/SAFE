#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Person.h"

using std::unordered_map;
using std::string;
using std::vector;

Person::Person(){
    dx[0]=0,dy[0]=1;
    dx[1]=1,dy[1]=0;
    dx[2]=0,dy[2]=-1;
    dx[3]=-1,dy[3]=0;
}

Person::~Person(){}

void Person::Action(unordered_map<int,int>to,unordered_map<int,One>table){
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
    OutputA.close();
}
