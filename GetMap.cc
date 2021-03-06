#include <iostream>
#include <fstream>
#include <string>
#include "GetMap.h"

using std::string;
using std::cout;
using std::endl;

GetMap::GetMap(){}

GetMap::~GetMap(){}

void GetMap::get_map(unordered_map<int,int>&map_table,vector<Edge>&m,vector<int>&leave,unordered_map<int,One>&table){
    map_table.clear();
    m.clear();
    leave.clear();
    table.clear();
    std::ifstream Input("./InputData/map.txt");
    int n;
    Input>>n;
    for (int i=1;i<=n;i++){
        map_table[i]=-1;
        int fr,x,y;
        Input>>fr>>x>>y;
        table[fr]=One(x,y);
        int t;
        Input>>t;
        for (int j=0;j<t;j++){
            int dir,dist,to;
            Input>>to>>dir>>dist;
            m.push_back(Edge(fr,to,dist,map_table[fr],dir));
            map_table[fr]=m.size()-1;
        }
    }
    Input>>n;
    for (int i=0;i<n;i++){
        int t;
        Input>>t;
        leave.push_back(t);
    }
    Input.close();
}

void GetMap::get_data(unordered_map<string,int>&sti,unordered_map<int,string>&its){
    std::ifstream Input("./InputData/station_table.txt");
    sti.clear();
    its.clear();
    string s;
    int n;
    while (Input>>s>>n){
        sti[s]=n;
        its[n]=s;
        //cout<<s<<endl;
    }
    Input.close();
}
