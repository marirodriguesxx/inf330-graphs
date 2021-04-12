#include<iostream>
#include <vector>
#include<algorithm>
#include <utility>
#include <map>
#include <iterator>
#include <set>
using namespace std;

//Returns the number of vertices in the subtree.
// After all calls from the recursion stack, we will check if the number of nodes is odd or even
int findSubtrees(vector<int> AdjacencyList[],int pos, bool nodes_visited[], int &resp){
    //whe we call the function to some node, wue should mak this node as visited, to avoid visit same node again
    nodes_visited[pos] = true; //already visited!
    int nodes_subtree=0;
    int subtreeNodes = 0;   //Numbre of nodes in the subtree
    //looking all neighbors the node in pos
    for(int i=0; i<AdjacencyList[pos].size(); i++){
        if(!nodes_visited[AdjacencyList[pos][i]]){
            nodes_subtree = findSubtrees(AdjacencyList,AdjacencyList[pos][i],nodes_visited,resp);
            //If the number of nodes is even, we increment the answer, which was passed by reference so that we can change it. 
            //If it were created within the scope of the function, its value would always be reset 
            if (nodes_subtree % 2 == 0) resp++; 
            else subtreeNodes += nodes_subtree;
        }
    }
    return subtreeNodes+1; // return the number of nodes in the subtree
}


int evenForest (int t_nodes,int t_edges, const vector<int> &t_from, const vector<int>  &t_to){
    vector<int> AdjacencyList[t_nodes+1]; //adjacency list of the graph.
    //To create the lista, we must read edge by edge. Take the first node,
    //and add the other to the list of this node. Repeat the process to the other node 
    for(int i=0; i<t_edges; i++){
        AdjacencyList[t_from[i]].push_back(t_to[i]);
        AdjacencyList[t_to[i]].push_back(t_from[i]);
    }
    //creating a vector of visited nodes as a bool vector.
    bool nodes_visited [t_nodes+1] = {false};
    int resp = 0;
    findSubtrees(AdjacencyList,1,nodes_visited,resp);
    return resp;
}

int main(){
    int t_nodes, t_edges; //number of nodes and edges of the graph
    cin >> t_nodes >> t_edges;
    vector<int> t_from; 
    vector<int> t_to;
    
    for(int i=0; i<t_edges; i++){
        pair<int,int>edge;
        cin>>edge.first>>edge.second;   //receives the pair of edge nodes
        t_from.push_back(edge.first);
        t_to.push_back(edge.second);
    }
    int resp = evenForest(t_nodes, t_edges, t_from, t_to);
    cout<< resp <<"\n";
    
    return 0;
}