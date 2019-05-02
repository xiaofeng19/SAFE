#ifndef _CONTROL_H_
#define _CONTROL_H_

#include <vector>
#include <map>
#include "AllStruct.h"
#include "MapManager.h"
#include "GetData.h"
#include "Person.h"
#include "Safe.h"

using std::vector;
using std::unordered_map;

class Control {
public:
    Control();
    ~Control();
    void Run();
private:
    MapManager *map_manager;
    GetData *get_data;
    Person *person;
    Safe *safe;

    vector<Edge>building_map;
    vector<int>leave;
    unordered_map<int,bool>fire_data;
    unordered_map<int,One>table;
    unordered_map<int,int>go_to;
    unordered_map<int,int>map_table;
};

#endif  //_CONTROL_H_