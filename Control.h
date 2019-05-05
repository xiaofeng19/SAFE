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

//using std::string;
//using std::vector;
//using std::unordered_map;

class Control {
public:
    Control();
    ~Control();
    void Run();
private:
    void StringToInt();

    GetMap *map_manager;
    GetData *get_data;
    Person *person;
    Safe *safe;

    vector<Edge>building_map;
    vector<int>leave;
    unordered_map<string,bool>fire_data_string;
    unordered_map<int,bool>fire;
    unordered_map<int,One>table;
    unordered_map<int,int>go_to;
    unordered_map<int,int>map_table;
    unordered_map<string,int>sti;
    unordered_map<int,string>its;
};

#endif  //_CONTROL_H_
