//incompleto
#include <iostream>
#include <vector>
#include<algorithm>
#include <utility>
#include <map>
#include <iterator>
#include<set>

using namespace std;
//Um grafo é euleriano se todos seus vétices possuem grau PAR!
void ordering(int beads[][2], int size){
    for(int i=0; i<size; i++){
        if(i+1 < size && beads[i+1][0] != beads[i][1]){
            //cout<<beads[i][1]<<"\n";
            for(int j=i+1; j<size; j++){
                if(beads[j][0] == beads[i][1]){
                    //cout<<"linha "<<j<<"coluna 0 tem igual\n";
                    swap(beads[i+1][0], beads[j][0]);
                    swap(beads[i+1][1], beads[j][1]);
                }
                else if(beads[j][1] == beads[i][1]){
                    //cout<<"linha "<<j<<"coluna 1 tem igual\n";
                    swap(beads[j][0], beads[j][1]);
                    swap(beads[i+1][0], beads[j][0]);
                    swap(beads[i+1][1], beads[j][1]);
                }
            }
        }
    }
}

int main(){
    int t=0, n=0; //t- number of tests cas and n - number of beads my sister was able to collect
    cin>>t;
    set<int> nodes;
    for(int i=0; i<t; i++){
        cout<<"Case #"<<i+1<<"\n";
        cin>>n;
        int beads[n][2];
        set<int> nodes;
        for(int j=0; j<n; j++){
            cin>>beads[j][0]>>beads[j][1];
            nodes.insert(beads[j][0]);
            nodes.insert(beads[j][1]);
        }
        // for (auto it=nodes.begin(); it != nodes.end(); ++it)     
        //     cout << ' ' << *it;
        // cout<<"\n";
        int degree[nodes.size()+1] = {0};
        //percorrendo a matriz, para cada valor encontrado, incrementaremos 1 na posição respectiva ao nodo
        for(int i=0; i<n ;i++){
            degree[beads[i][0]]++;
            degree[beads[i][1]]++;
        }
        bool euleriano = true;
        for(int i=1; i<nodes.size()+1; i++){
            if(degree[i]%2 != 0) euleriano = false;
            //cout<<degree[i]<<" ";
        }
        int elementos_conexos = n-nodes.size();
        //cout<<"conexos: "<<elementos_conexos<<endl;
        if(euleriano && elementos_conexos==1) {
            ordering(beads,n);
            for(int i=0; i<n; i++)
                cout<<beads[i][0]<<" "<<beads[i][1]<<"\n";
            cout<<"\n";
        }
        else if(!euleriano || elementos_conexos!=1)cout<<"some beads may be lost\n\n";

    }
    

    return 0;
}