#ifndef _GETDATA_H_
#define _GETDATA_H_

#include <string>
#include <vector>
#include "AllStruct.h"

using std::string;
using std::vector;

class GetData {
public:
    GetData();
    ~GetData();
    void get(unordered_map<string,bool>&fire_data);
    bool close();
    bool fire;
private:
};

#endif  //_GETDATA_H_