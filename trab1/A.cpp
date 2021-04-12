#include <iostream>
#include <vector>
#include<algorithm>
#include <utility>
#include <map>
#include <iterator>
// creating a vector to store the sum of each column, because for a matrix to be the incidence matrix of a simple graph
//not oriented, the sum of each column must be equal to 2!

using namespace std;

int main(){
    int t; //number of test cases
    int n,m; //n (number of vertices), m (number of edges)
    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n>>m;
        vector<vector<int>> matrix;
        int sum[m]= {0};    //will store the sum of each column of the given matrix
        for(int j=0; j<n; j++){
            vector<int> row;
            for(int k=0; k<m; k++){
                int value;
                cin>>value;
                sum[k] +=value;
                row.push_back(value);
            }
            matrix.push_back(row);
        }
        //map of all edges of the graph. A simple graph has only one edge between two nodes, 
        //then if in a matrixhave two equal edges, cant be a incidence matrix;
        map<vector<int>,int> edges; 
        bool yes = true;

        pair<map<vector<int>,int>::iterator,bool> edges_bool;

        for(int j=0; j<m; j++){
            vector<int> col;
            for(int k=0; k<n; k++)
                col.push_back(matrix[k][j]);
            if (sum[j] == 2)
                edges_bool = edges.insert(pair<vector<int>,int>(col,j)); 
            if(sum[j] != 2 || !edges_bool.second) yes = false;
        }
        
        if(yes) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}