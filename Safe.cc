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
using std::ifstream;
using std::cout;
using std::endl;

Safe::Safe(){}

Safe::~Safe(){}

void Safe::calc(unordered_map<int,int>map_table,vector<Edge>building_map,unordered_map<int,bool>data,vector<int>leave,unordered_map<int,int>&ans,unordered_map<int,string>its){
    //cout<<"calc"<<endl;
    dir.clear();
    m=building_map;
    table=map_table;
    fire.clear();
    for (auto k:data)
        fire[k.first]=k.second;
    //cout<<1<<endl;
    memset(dis,0x3f,sizeof(dis));
    for (int e:leave){
        if (fire[e])
            continue;
        Dijkstra(e);
    }

    //cout<<2<<endl;
    ans.clear();
    for (auto k:dir)
        ans[k.first]=k.second;
    Output(its,leave);
    //cout<<3<<endl;
}

void Safe::Dijkstra(int s){
    //cout<<1<<" "<<s<<endl;
    dis[s]=0;
    //cout<<3<<endl;
    priority_queue<pair<int,int>,vector<pair<int,int> >, std::greater<pair<int,int> > > qq;
    qq.push(std::make_pair(dis[s],s));
    while (!qq.empty()){
        int preval=qq.top().first;
        int x=qq.top().second;
        qq.pop();
        if (dis[x]<preval)
            continue;
        for (int i=table[x];i!=-1;i=m[i].nxt){
            if (!fire[m[i].to]&&dis[m[i].to]>dis[x]+m[i].dist){
                dir[m[i].to]=(m[i].dir+2)%4;
                dis[m[i].to]=dis[x]+m[i].dist;
                qq.push(std::make_pair(dis[m[i].to],m[i].to));
            }
        }
    }
}

void Safe::Output(unordered_map<int,string>its,vector<int>leave){
    ifstream InputA("./InputData/T.txt");
    unordered_map<string,vector<int> >tmp;
    tmp.clear();
    for (int i=0;i<42;i++){
        string s;
        InputA>>s;
        //cout<<s<<endl;
        tmp[s].clear();
        for (int j=0;j<4;j++){
            int a;
            InputA>>a;
            tmp[s].push_back(a);
        }
    }
    InputA.close();

    ofstream fout("./OutputData/GiveData.txt");
    ofstream OutputA("./OutputData/arrow.txt");
    int ans[200];
    memset(ans,0,sizeof(ans));
    for (auto k:dir){
        if (its.find(k.first)==its.end())
            continue;
        //cout<<k.first<<" "<<its[k.first]<<" "<<k.second<<endl;
        /*
        if (k.first==44||k.first==45){
                cout<<k.first<<" "<<its[k.first]<<" "<<k.second<<" "<<tmp[its[k.first]][k.second]<<endl;
        }
        */
        for (int i=0;i<4;i++){
            fout<<"S";
            fout<<its[k.first]<<i;
            //cout<<its[k.first]<<i;
            bool flag=true;
            for (int e:leave){
                if (e==k.first){
                    flag=false;
                    break;
                }
            }
            if (flag&&i==k.second){
                fout<<1;
                ans[tmp[its[k.first]][i]]=1;
            }
            else
                fout<<0;
        }
    }
    fout<<"E";
    OutputA<<0;
    for (int i=2;i<=107;i++)
        OutputA<<ans[i];
    OutputA<<endl;
    fout.close();
    OutputA.close();
}
