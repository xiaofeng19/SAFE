#include <fstream>
#include <string>
#include "GetData.h"

using std::string;

GetData::GetData(){}

GetData::~GetData(){}

void get(unordered_map<int,bool>&fire_data){
    std::ifstream Input("./InputData/fire.txt");
    int f;
    fire_data.clear();
    while (Input>>f)
        fire_data[f]=true;
    fire=(fire_data.size()!=0);
}

bool close(){
    std::ifstream Input("./InputData/close.txt");
    string s="";
    while (Input>>s);
    if (s!="")
        return true;
    return false;
}