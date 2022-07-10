#include<iostream>
#include <vector>
#include<algorithm>
#include <utility>
#include <map>
#include <iterator>
#include <set>
using namespace std;

bool dfs(vector<int> adjacencyList[], int colors[],int pos,int color){    
    if(colors[pos]!=-1){
        if(colors[pos]!=color) return false;
        else return true;
    }
    colors[pos] = color;
    for(int i=0; i<adjacencyList[pos].size(); i++){
        bool aux = dfs(adjacencyList,colors,adjacencyList[pos][i],1-color);  
        if(!aux) return false;
    }
    return true;
}
int main(){
    int n=0; //number of vertices in graph
    while(cin>>n){
        if(n==0) break;
        int a,b;
        vector<int> adjacencyList[n+1];
        while(cin>>a>>b){
            if(a==0 && b==0) break;
            adjacencyList[a].push_back(b);
            adjacencyList[b].push_back(a);
        }

        int colors[n+1] ; //number os sets that we can divide the graph
        bool resp=false;
        for(int i=0; i<=n; i++) colors[i]=-1;

        // for(int i=1; i<=n ; i++){
        //     if(colors[i]!=-1)continue;
        //     if(dfs(adjacencyList,colors,i,0)){
        //         cout<<"YES\n"; resp = true; break;
        //     }                              
        // }

        if(dfs(adjacencyList,colors,1,0))
            cout<<"YES\n"; 
        else cout<<"NO\n";
   
    }
    return 0;
}