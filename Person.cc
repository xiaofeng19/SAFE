#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
#include "Person.h"

using std::unordered_map;
using std::string;
using std::vector;
using std::cout;
using std::endl;

Person::Person(){
    dx[0]=0,dy[0]=-5;
    dx[1]=5,dy[1]=0;
    dx[2]=0,dy[2]=5;
    dx[3]=-5,dy[3]=0;
    dx[4]=0,dy[4]=0;
}

Person::~Person(){}

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
            one.x=tmp+10;
            person.push_back(one);
            tmp=0;
        }
        else
            tmp=tmp*10+X[i]-'0';
    }
    for (int i=0,o=0;i<=Y.size();i++){
        if (i==Y.size()||Y[i]=='A'){
            person[o++].y=tmp+10;
            tmp=0;
        }
        else
            tmp=tmp*10+Y[i]-'0';
    }
}

bool Person::judge(One &p){
    if (p.x==1205&&(p.y==105||p.y==555))
        p.x=655;
    else if (p.x==1655&&(p.y==105||p.y==555))
        p.x=1105;
    else if (p.x==655&&(p.y==105||p.y==555))
        p.x=105;
    else if (p.x==1105&&(p.y==105||p.y==555))
        p.x=555;
    else
        return false;
    return true;
}
//245A795A1495
//95A245A245
void Person::Action(unordered_map<int,int>to,unordered_map<int,One>table){
    for (One &p:person){
        if (judge(p))
            continue;
        if (p.x<=80||(p.x>=580&&p.x<=630))
            continue;
        if (p.x<=105&&(p.y<=405&&p.y>=255)){
            p.x+=dx[3];
            p.y+=dy[3];
            continue;
        }
        else if (p.x>=555&&p.x<=580&&p.y<=405&&p.y>=255){
            p.x+=dx[1];
            p.y+=dy[1];
            continue;
        }
        for (auto k:table){
            int t=abs(k.second.x-p.x)+abs(k.second.y-p.y);
            if (t==0){
                p.a=to[k.first];
                p.l=k.first;
                break;
            }
            else if (k.first==p.l&&p.a!=to[k.first]){
                if (k.second.x>p.x)
                    p.a=1;
                else if (k.second.x<p.x)
                    p.a=3;
                else if (k.second.y>p.y)
                    p.a=2;
                else
                    p.a=0;
            }
        }
        p.x+=dx[p.a];
        p.y+=dy[p.a];
    }
    WriteLog();
}

void Person::WriteLog(){
    std::ofstream OutputX("./OutputData/x.txt");
    std::ofstream OutputY("./OutputData/y.txt");
    for (int i=0;i<person.size();i++){
        OutputX<<person[i].x-10;
        OutputY<<person[i].y-10;
        cout<<person[i].x<<" "<<person[i].y;
        if (i!=person.size()-1){
            OutputX<<"A";
            OutputY<<"A";
        }
    }
    OutputX.close();
    OutputY.close();
}
