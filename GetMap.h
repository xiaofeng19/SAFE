#ifndef _GETMAP_H_
#define _GETMAP_H_

#include <vector>
#include <map>
#include "AllStruct.h"

using std::vector;
using std::unordered_map;

class GetMap {
public:
    GetMap();
    ~GetMap();
    void get_map(unordered_map<int,int>&map_table,vector<Edge>&m,vecotr<int>&leave,unordered_map<int,One>&table);
private:
};

#endif  //_GETMAP_H_