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
    void Action(unordered_map<int,int>to,unordered_map<int,One>table);
private:
    bool judge(int x,int y);
    void calc(unordered_map<int,int>to,unordered_map<int,One>table);
    void GetPerson();
    void WriteLog();
    vector<One>person;
    int dx[5],dy[5];
    int m[1700][600];
};

#endif  //_PERSON_H_
