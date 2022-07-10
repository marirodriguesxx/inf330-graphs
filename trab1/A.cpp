#include <iostream>
#include <vector>
#include<algorithm>
#include <utility>
#include <map>
#include <iterator>

//criando um vetor para armezenar a soma de cada coluna, pois para que uma matriz seja a matriz de incidencia de um grafo simples
//não orientado, a soma de cada coluna deve ser igual 2!

using namespace std;

int main(){
    int t; //number of test cases
    int n,m; //n (number of vertices), m (number of edges)
    //vector<vector<vector<int>>> IncidenceMatrixs;

    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n>>m;
        vector<vector<int>> matrix;
        int sum[m]= {0};
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
        //IncidenceMatrixs.push_back(matrix);

        // for(int j=0; j<m; j++)
        //     cout<<sum[j]<<"-";
        // cout<<"\n";

        map<vector<int>,int> edges; //map of all edges of the graph. A simple graph has only one edge between two nodes, then if in a matrix
        //have two equal edges, cant be a incidence matrix;
        bool yes = true;

        pair<map<vector<int>,int>::iterator,bool> edges_bool;

        for(int j=0; j<m; j++){
            vector<int> col;
            for(int k=0; k<n; k++)
                col.push_back(matrix[k][j]);
            if (sum[j] == 2)
                edges_bool = edges.insert(pair<vector<int>,int>(col,j)); 
            //cout<<sum[j]<<"\n";
            if(sum[j] != 2 || !edges_bool.second) yes = false;
            //cout<<"yes:"<<yes<<"\n";
        }
        
        if(yes) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}