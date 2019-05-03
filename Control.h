#ifndef _CONTROL_H_
#define _CONTROL_H_

#include <string>
#include <vector>
#include <map>
#include "AllStruct.h"
#include "GetMap.h"
#include "GetData.h"
#include "Person.h"
#include "Safe.h"

using std::string;
using std::vector;
using std::unordered_map;

class Control {
public:
    Control();
    ~Control();
    void Run();
private:
    GetMap *map_manager;
    GetData *get_data;
    Person *person;
    Safe *safe;

    vector<Edge>building_map;
    vector<string>leave;
    unordered_map<string,bool>fire_data;
    unordered_map<string,One>table;
    unordered_map<string,int>go_to;
    unordered_map<string,int>map_table;
    unordered_map<string,int>string_to_num;
};

#endif  //_CONTROL_H_