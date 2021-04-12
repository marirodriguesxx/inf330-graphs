#include <iostream>
#include <vector>
#include<algorithm>
#include <utility>
#include <map>
#include <iterator>
#include<set>
using namespace std;

void read(int &trees, int &disjointed){
    string edge,s_edges;
    int n_edges=0, n_nodes; //Number of edges and nodes, respectively

    while (cin){
        cin>>edge;
        s_edges +=edge;
        if(edge[0]=='*')break;
        n_edges++;
    }
    string s_nodes;
    cin>>s_nodes;
    //converting string elements into a set
    set<char> edges(s_edges.begin(), s_edges.end());
    set<char> nodes (s_nodes.begin(), s_nodes.end());
    nodes.erase(','); //removendo string desnecessárias
    n_nodes = nodes.size();
    int connectd = n_nodes - n_edges; //The number of connected components will be the number of vertices - the number of edges
    int disjoint =0;
    for(char node:nodes){
        bool is_in = edges.find(node) != edges.end(); //look, for each node, if it is inside the set of edges 
        if(is_in == false)disjoint++; //if it doesn't belong to any edge, it means that it's a disconnected vertex
    }
    //cout<<"There are "<<(connectd-disjoint)<<" tree(s) and "<<disjoint<<" acorn(s).\n";
    trees= connectd-disjoint;
    disjointed = disjoint;

}

int main(){
    int n;
    cin>>n;
    int trees=0, disjointed=0;
    for(int i=1; i<=n; i++){
        read(trees,disjointed);
        cout<<"There are "<<trees<<" tree(s) and "<<disjointed<<" acorn(s).\n";
    }
    return 0;
}