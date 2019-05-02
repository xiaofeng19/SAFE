#include <fstream>
#include "MapManager.h"

MapManager::MapManager(){}

MapManager::~MapManager(){}

void MapManager::get_map(unordered_map<int,int>&map_table,vector<Edge>&m,vecotr<int>&leave,unordered_map<int,One>&table){
    map_table.clear();
    m.clear();
    leave.clear();
    table.clear();
    std::fstream Input("./input.safe");
    int n,m;
    Input>>n;
    for (int i=1;i<=n;i++){
        map_table[i]=-1;
        int h,x,y;
        Input>>h>>x>>y;
        table[i]=One(x,y,h);
        int m;
        Input>>m;
        for (int j=0;j<m;j++){
            int to,dir,dist;
            Input>>to>>dir>>dist;
            m.push_back(Edge(to,dist,map_table[i],dir));
            map_table[i]=m.size()-1;
        }
    }
    Input>>n;
    for (int i=0;i<n;i++){
        int m;
        Input>>m;
        leave.push_back(m);
    }
    Input.close();
}