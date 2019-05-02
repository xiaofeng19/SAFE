#ifndef _ALLSTRUCT_H_
#define _ALLSTRUCT_H_

struct Edge {   //作为链式前向星的基本结构
    int to,nxt,dir,dist;
    Edge(int _t,int _d,int _n,int _di):to(_t),dist(_d),nxt(_n),dir(_di) {}
    Edge(){}
};

struct One {
    int x,y;
    int h;
};

#endif  //_ALLSTRUCT_H_