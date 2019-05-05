#include <iostream>
#include <cstring>
#include <fstream>
#include <queue>
#include "Safe.h"

using std::string;
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::pair;
using std::ofstream;
using std::cout;
using std::endl;

Safe::Safe(){}

Safe::~Safe(){}

void Safe::calc(unordered_map<int,int>map_table,vector<Edge>building_map,unordered_map<int,bool>data,vector<int>leave,unordered_map<int,int>&ans,unordered_map<int,string>its){
    //cout<<"calc"<<endl;
    m=building_map;
    table=map_table;
    fire.clear();
    for (auto k:data)
        fire[k.first]=k.second;
    for (int e:leave)
        Dijkstra(e);
    ans.clear();
    for (auto k:dir)
        ans[k.first]=k.second;
    Output(its);
}

void Safe::Dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >, std::greater<pair<int,int> > > qq;
    qq.push(std::make_pair(dis[s],s));
    while (!qq.empty()){
        int preval=qq.top().first;
        int x=qq.top().second;
        qq.pop();
        if (dis[x]<preval)
            continue;
        for (int i=table[x];i!=-1;i=m[i].nxt){
            if (dis[m[i].to]>dis[x]+m[i].dist){
                dir[m[i].to]=m[i].dir;
                dis[m[i].to]=dis[x]+m[i].dist;
                qq.push(std::make_pair(dis[m[i].to],m[i].to));
            }
        }
    }
}

void Safe::Output(unordered_map<int,string>its){
    ofstream fout("./OutputData/GiveData.txt");
    for (auto k:dir){
        for (int i=0;i<4;i++){
            fout<<"S";
            fout<<its[k.first]<<i;
            //cout<<its[k.first]<<i;
            if (i==k.second)
                fout<<1;
            else
                fout<<0;
        }
    }
    fout<<"E";
    fout.close();
    ofstream OutputA("./OutputData/arrow.txt");
    OutputA.close();
}
