#ifndef _GETDATA_H_
#define _GETDATA_H_

#include <vector>
#include "AllStruct.h"

using std::vector;

class GetData {
public:
    GetData();
    ~GetData();
    void get(unordered_map<int,bool>&fire_data);
    bool close();
    bool fire;
private:
};

#endif  //_GETDATA_H_