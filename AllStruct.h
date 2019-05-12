#ifndef _ALLSTRUCT_H_
#define _ALLSTRUCT_H_

#include <string>

using std::string;

struct Edge {   //作为链式前向星的基本结构
    int fr,nxt,dir,dist,to;
    Edge(int _f,int _t,int _d,int _n,int _di):fr(_f),to(_t),dist(_d),nxt(_n),dir(_di) {}
    Edge(){}
};

struct One {
    int x,y;
    int a;
    One(int _x,int _y):x(_x),y(_y) {}
    One(){}
};

#endif  //_ALLSTRUCT_H_