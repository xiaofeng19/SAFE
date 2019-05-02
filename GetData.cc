#include <fstream>
#include <string>
#include "GetData.h"

using std::string;

GetData::GetData(){}

GetData::~GetData(){}

void get(unordered_map<int,bool>&fire_data){}

bool close(){
    std::ifstream Input("./close.safe");
    string s="";
    while (Input>>s);
    if (s!="")
        return true;
    return false;
}