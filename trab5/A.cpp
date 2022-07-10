#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
using namespace std;

void floyd(vector<vector<int>> &distances, int nodes){
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            for(int k=0; k<nodes; k++){
                int m=min(distances[j][i],distances[i][k]);
                //if exists path and it is shortest the the other or wasnt inicializated yet
                if((distances[j][i]!=-1 && distances[i][k]!=-1) && (distances[j][k]==-1||distances[j][k]<m)) 
                    distances[j][k]=m;
            }
        }
    }
}

int main(){
    int n,r, w, value=0; //number of cities en road segments
    string cityA, cityB, consultaA, consultaB;
    map<string,int> values; //map to make the keys as int
    vector<vector<int>> distances(201,vector<int>(201,-1));
    int scenario=1;
    while(cin>>n>>r){
        if(n==0 && r==0)break; //"Input will be terminated by two values of 0 for n and r."
        for(int i=0; i<r; i++){
            cin>>cityA>>cityB>>w;
            pair<map<string,int>::iterator,bool> insertedA, insertedB; //will return a boolean value for inserting the vertex in the map
            //if we insert a new vertex, we increase the counter 
            insertedA = values.insert(pair<string,int>(cityA,value));
            if(insertedA.second==true) value++;          
            insertedB = values.insert(pair<string,int>(cityB,value));
            if(insertedB.second==true) value++;
            //distance from A to B is the same that the distance from B to A
            distances[values[cityA]][values[cityB]] = w;
            distances[values[cityB]][values[cityA]] = w;
        }
 
        int nodes = values.size(); //number of graph nodes
        floyd(distances,nodes);
        cin>>consultaA>>consultaB;
        cout<<"Scenario #"<<scenario<<"\n";
        cout<<distances[values[consultaA]][values[consultaB]]<<" tons\n\n";
        scenario++; //counting the number of test cases
    }
    return 0;
}