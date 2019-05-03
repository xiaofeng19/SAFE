#include <fstream>
#include <string>
#include "GetData.h"

using std::string;

GetData::GetData(){}

GetData::~GetData(){}

void get(unordered_map<int,bool>&fire_data){}

bool close(){
    std::ifstream Input("./InputData/close.txt");
    string s="";
    while (Input>>s);
    if (s!="")
        return true;
    return false;
}