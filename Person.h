#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "AllStruct.h"

using std::string;
using std::vector;
using std::unordered_map;

class Person {
public:
    Person();
    ~Person();
    void Action(unordered_map<int,int>map_table,vector<Edge>building_map,unordered_map<int,int>to,unordered_map<int,One>table);
private:
    void WriteLog();
    vector<One>person;
    int dx[4],dy[4];
};

#endif  //_PERSON_H_
