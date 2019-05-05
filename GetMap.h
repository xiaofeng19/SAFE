#ifndef _GETMAP_H_
#define _GETMAP_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "AllStruct.h"

using std::string;
using std::vector;
using std::unordered_map;

class GetMap {
public:
    GetMap();
    ~GetMap();
    void get_map(unordered_map<int,int>&map_table,vector<Edge>&m,vector<int>&leave,unordered_map<int,One>&table);
    void get_data(unordered_map<string,int>&sti,unordered_map<int,string>&its);
private:
};

#endif  //_GETMAP_H_
