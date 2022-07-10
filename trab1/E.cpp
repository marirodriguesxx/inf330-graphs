#include<iostream>
#include <vector>
#include<algorithm>
#include <utility>
#include <map>
#include <iterator>
#include <set>
using namespace std;

int Treeheight(int relationship[], vector<int> &heights, bool visited[], int pos){
    visited[pos] = true; //node visited!
    if(relationship[pos] == -1) return 0;
    return(Treeheight(relationship,heights,visited,relationship[pos]))+1;
}

int main(){
    int n; //Numbre of employees
    cin >> n;
    int relation[n+1];

    for(int i=1; i<=n; i++){
        int manager;
        cin>>manager;
        relation[i] = manager;
    }
    
    // for(int i=1; i<=n; i++)
    //     cout<<i<<": "<<relation[i]<<"\n";

    vector<int> heights;
    bool nodes_visited [n+1] = {false};
    int h=0;
    for(int i=n; i>=1; i--){
        if(!nodes_visited[i]){
        heights.push_back(Treeheight(relation,heights,nodes_visited,i));
        }
    }
    // for(int i=0; i<heights.size(); i++){
    //     cout<<heights[i]+1<<" ";
    // }
    int max = *max_element(heights.begin(), heights.end());
    cout<<max+1<<endl;
    return 0;
}