#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
#include "Person.h"

using std::unordered_map;
using std::string;
using std::vector;

Person::Person(){
    dx[0]=0,dy[0]=-5;
    dx[1]=-5,dy[1]=0;
    dx[2]=0,dy[2]=5;
    dx[3]=5,dy[3]=0;
    dx[4]=0,dy[4]=0;
}

Person::~Person(){}

bool Person::judge(int x,int y){
    bool flag=true;
    if (x>=280&&x<=380&&(y<=230||(y>=280&&y<=380)||y>=430))
        flag=false;
    if (x>=130&&x<=230&&((y>=130&&y<=230)||(y>=430&&y<=530)))
        flag=false;
    if (x>=430&&x<=530&&((y>=130&&y<=230)||(y>=430&&y<=530)))
        flag=false;
}

void Person::calc(unordered_map<int,int>to,unordered_map<int,One>table){
    for (int i=80;i<=1680;i++){
        for (int j=80;j<=580;j++){
            int o=0,len=0x3f;
            for (auto k:table){
                int t=abs(k.second.x-i)+abs(k.second.y-j);
                if (t<len){
                    len=t;
                    o=k.first;
                }
            }

        }
    }
}

void Person::GetPerson(){
    person.clear();
    std::ifstream InputX("./OutputData/x.txt");
    std::ifstream InputY("./OutputData/y.txt");
    string X,Y;
    getline(InputX,X);
    getline(InputY,Y);
    InputX.close();
    InputY.close();
    int tmp=0;
    for (int i=0;i<=X.size();i++){
        if (i==X.size()||X[i]=='A'){
            One one;
            one.x=tmp;
            person.push_back(one);
            tmp=0;
        }
        else
            tmp=tmp*10+X[i]-'0';
    }
    for (int i=0,o=0;i<=Y.size();i++){
        if (i==Y.size()||Y[i]=='A'){
            person[o++].y=tmp;
            tmp=0;
        }
        else
            tmp=tmp*10+Y[i]-'0';
    }
}

void Person::Action(unordered_map<int,int>to,unordered_map<int,One>table){
    calc();
    GetPerson();
    for (One &p:person){
        int o=0,len=0x3f;
        for (auto k:table){
            int t=abs(k.second.x-p.x)+abs(k.second.y-p.y);
            if (t<len){
                len=t;
                o=k.first;
            }
        }
        p.x+=dx[to[o]];
        p.y+=dy[to[o]];
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
}
