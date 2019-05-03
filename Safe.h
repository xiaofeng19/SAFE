#ifndef _SAFE_H_
#define _SAFE_H_

#include <string>
#include <vector>
#include <map>
#include "AllStruct.h"

using std::string;
using std::vector;
using std::unordered_map;

class Safe {
public:
    Safe();
    ~Safe();
    void calc(vector<Edge>building_map,unordered_map<string,bool>data,vector<string>leave,unordered_map<string,int>&ans);
private:
    void Dijkstra();
    vector<Edge>m;
    unordered_map<string,int>dir;
    unordered_map<string,int>table;
    unordered_map<string,bool>fire;
    int dis[100005];
};

#endif //_SAFE_H_