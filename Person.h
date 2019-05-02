#ifndef _PERSON_H_
#define _PERSON_H_

#include <vector>
#include "AllStruct.h"

using std::vector;

class Person {
public:
    Person();
    ~Person();
    void action(nordered_map<int,int>to,unordered_map<int,One>table);
private:
    void WriteLog();
    vector<One>person;
    int dx[4],dy[4];
};

#endif  //_PERSON_H_