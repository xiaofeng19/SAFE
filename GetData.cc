#include <iostream>
#include <fstream>
#include "GetData.h"

using std::unordered_map;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

GetData::GetData(){
    fire=false;
}

GetData::~GetData(){}

void GetData::get(unordered_map<string,bool>&fire_data){
    ifstream Input("./InputData/fire.txt");
    string s;
    fire_data.clear();
    for (int k=1;k<=3;k++){
        getline(Input,s);
        for (int i=1;i+1<s.size();i+=4){
            string f=s.substr(i,2);
            fire_data[f]=(s[i+2]=='1');
            fire|=fire_data[f];
            cout<<s<<" "<<fire_data[f]<<endl;
        }
    }
    Input.close();
}

bool GetData::close(){
    ifstream Input("./InputData/close.txt");
    string s;
    getline(Input,s);
    Input.close();
    if (s=="close")
        return true;
    return false;
}
