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
    if(relationship[pos] == -1) return 0; //when the manager=-1, means that such an employee does not have a manager,and therefore the tree will have zero height
    return(Treeheight(relationship,heights,visited,relationship[pos]))+1;
}

//Analyzing, it is noted that the entrance will be a forest. For, given a manager, he will have employees, who can be managers of others.
// With this, we must analyze the height of the largest tree, as it will represent the minimum number of groups, 
//since an employee cannot be in the same group as his manager.
int main(){
    int n; //Number of employees
    cin >> n;
    int relation[n+1]; // we add 1 beacause emplyee 0 does not exist.

    for(int i=1; i<=n; i++){
        int manager;
        cin>>manager;
        relation[i] = manager;
    }

    vector<int> heights; //this vector will save all the heights of a tree
    bool nodes_visited [n+1] = {false}; //control of nodes that have already been visited to prevent them from being counted again
    for(int i=n; i>=1; i--){
        if(!nodes_visited[i]){
        heights.push_back(Treeheight(relation,heights,nodes_visited,i));
        }
    }
    //taking the largest element of the vector, which will represent the tallest tree
    int max = *max_element(heights.begin(), heights.end());
    cout<<max+1<<endl; //as we count the height from zero, we must add 1 to its result
    return 0;
}