#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<climits>
using namespace std;

struct edge{
    int x,y,t;
};

bool BellmanFord(vector<edge> &w, int nodes, int edges, int start){
    int infinite = INT_MAX;
    int cost[nodes], dad[nodes];

    for(int i=0; i<nodes; i++) {cost[i] = infinite; dad[i]=-1;}
    cost[start]=0; dad[start]=start;

    for(int i=0; i <nodes-1; i++){
        for(int j=0; j <edges; j++){
            if (cost[w[j].x] + w[j].t < cost[w[j].y])
                {cost[w[j].y] = cost[w[j].x] + w[j].t; dad[w[j].y] = w[j].x;}
        }
    }
    for(int j=0; j <edges; j++){
        if (cost[w[j].x] + w[j].t < cost[w[j].y]) return true;
    }

    return false;
}

int main(){
    int cases, n, m;
    cin>>cases;
    for(int c=0; c<cases; c++){
        cin>>n>>m;
        vector<edge> wormholes;
        for(int i=0; i<m; i++){
            edge e;
            cin>>e.x>>e.y>>e.t;
            wormholes.push_back(e);
        }
        if(BellmanFord(wormholes,n,m,0)) cout<<"possible\n";
        else cout<<"not possible\n";

    }
    return 0;
}