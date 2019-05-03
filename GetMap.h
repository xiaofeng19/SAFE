#ifndef _GETMAP_H_
#define _GETMAP_H_

#include <string>
#include <vector>
#include <map>
#include "AllStruct.h"

using std::string;
using std::vector;
using std::unordered_map;

class GetMap {
public:
    GetMap();
    ~GetMap();
    void get_map(unordered_map<string,int>&map_table,vector<Edge>&m,vecotr<string>&leave,unordered_map<int,One>&table);
    void get_data(unordered_map<string,int>&num);
private:
};

#endif  //_GETMAP_H_