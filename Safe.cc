#include "Safe.h"

Safe::Safe(){}

Safe::~Safe(){}

void Safe::calc(unordered_map<int,int>map_table,vector<Edge>building_map,unordered_map<int,bool>data,vector<int>leave,unordered_map<int,int>&ans){
    m=building_map;
    fire.clear();
    for (auto k:data)
        fire[k.first]=k.second;
    for (int e:leave)
        Dijkstra(e);
    ans.clear();
    for (auto k:dir)
        ans[k.first]=k.second;
}

void Safe::Dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > qq;
    //堆顶是最小元素，按pair的first排序，所以把dis值放first（当年T到怀疑人生。。）
    qq.push(make_pair(dis[s],s));//源点入堆
    while (!qq.empty()){
        int preval=qq.top().first;
        int x=qq.top().second;
        //和未优化的版本一样找最小元素
        qq.pop();
        if (dis[x]<preval)//如果目前的值已经比进堆时小了，就没必要再过一遍了，有的题会卡这个时间
            continue;
        for (int i=table[x];i!=-1;i=m[i].nxt){
            if (dis[m[i].to]>dis[x]+m[i].dist){//一样的松弛操作，但是没有松驰过的点就没必要进堆了
                dir[m[i].to]=m[i].dir;
                dis[m[i].to]=dis[x]+m[i].dist;
                qq.push(make_pair(dis[m[i].to],m[i].to));
            }
        }
    }
}