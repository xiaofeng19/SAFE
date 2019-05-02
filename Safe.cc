#include "Safe.h"

Safe::Safe(){}

Safe::~Safe(){}

void Safe::calc(unordered_map<int,int>map_table,vector<Edge>building_map,unordered_map<int,bool>data,vector<int>leave,unordered_map<int,int>&ans){
    m=building_map;
    fire.clear();
    for (auto k:data)
        fire[k.first]=k.second;
    for (int e:leave)
        Dijkstra(e);
    ans.clear();
    for (auto k:dir)
        ans[k.first]=k.second;
}

void Safe::Dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > qq;
    qq.push(make_pair(dis[s],s));
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
                qq.push(make_pair(dis[m[i].to],m[i].to));
            }
        }
    }
}