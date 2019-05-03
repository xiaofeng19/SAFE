#include <fstream>
#include <string>
#include "GetMap.h"

using std::string;

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
        int x,y;
        Input>>x>>y;
        table[i]=One(x,y);
        int t;
        Input>>t;
        for (int j=0;j<t;j++){
            int dir,dist,to;
            Input>>to>>dir>>dist;
            m.push_back(Edge(to,dist,map_table[i],dir));
            map_table[i]=m.size()-1;
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

void GetMap::get_data(unordered_map<string,int>&num){
    std::ifstream Input("./InputData/table.txt");
    num.clear();
    int n=1;
    string s;
    while (Input>>s)
        num[s]=n++;
}
