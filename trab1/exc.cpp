#include <iostream>
#include <vector>
#include<algorithm>
#include <utility>
#include <map>
#include <iterator>
#include<set>
using namespace std;

int main(){
    int n;
    cin>>n;
    int trees=0, disjointed=0;
    string edge,s_edges,s_nodes;
    int n_edges=0, n_nodes; //Number of edges and nodes, respectively
    //reading edges and nodes
    for(int i=1; i<=n; i++){
        while (cin){
            cin>>edge;
            s_edges +=edge;
            if(edge[0]=='*')break;
            n_edges++;
        }   
        cin>>s_nodes;

        //converting string elements into a set
        set<char> edges(s_edges.begin(), s_edges.end());
        set<char> nodes (s_nodes.begin(), s_nodes.end());
        nodes.erase(','); //removing unnecessary strings from the vertex set
        n_nodes = nodes.size();
        int connectd = n_nodes - n_edges; //The number of connected components will be the number of vertices - the number of edges
        
        for(char node:nodes){
            bool is_in = edges.find(node) != edges.end(); //look, for each node, if it is inside the set of edges 
            if(is_in == false)disjointed++; //if it doesn't belong to any edge, it means that it's a disconnected vertex
        }
        trees = connectd-disjointed;
        cout<<"There are "<<trees<<" tree(s) and "<<disjointed<<" acorn(s).\n";
    }
    return 0;
}