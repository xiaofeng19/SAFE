#ifndef _SAFE_H_
#define _SAFE_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "AllStruct.h"

using std::string;
using std::vector;
using std::unordered_map;

class Safe {
public:
    Safe();
    ~Safe();
    void calc(unordered_map<int,int>map_table,vector<Edge>building_map,unordered_map<int,bool>data,vector<int>leave,unordered_map<int,int>&ans,unordered_map<int,string>num);
private:
    void Dijkstra(int s);
    void Output(unordered_map<int,string>num);
    vector<Edge>m;
    unordered_map<int,int>dir;
    unordered_map<int,int>table;
    unordered_map<int,bool>fire;
    int dis[100005];
};

#endif //_SAFE_H_
