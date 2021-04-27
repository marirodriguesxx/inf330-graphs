#include<iostream>
#include <vector>
#include<algorithm>
#include <utility>
#include <map>
#include <iterator>
#include <set>
using namespace std;

//Function to find the greatest common divisor
int Euclides(int a, int b){
    int largest=0, smaller=0;
    //defining the largest and smallest number
    if(a>b) { largest =a; smaller=b;}
    else {largest = b; smaller=a;}

    if(largest%smaller != 0) return Euclides(smaller,largest%smaller);    
    else return smaller;
}
//Function to simplify a fraction
void Simplify( int &numerator, int &denominator){
    //First we need to find the greatest commom divisor using Euclides algorithm
    int divisor = Euclides(numerator,denominator);
    //so we divide the numerator and denominator by divisor
    numerator=numerator/divisor;
    denominator=denominator/divisor;
}

void hasPath( vector<vector<pair<int,pair<int,int>>>> &adjacencyList, int posA, int posB, vector<bool> &visited, pair<int,int> result, 
bool &tem, pair<int,int> &result2){
    visited[posA]=true;
    
    for(int i=0; i<adjacencyList[posA].size();i++){
            int num =adjacencyList[posA][i].second.first;
            int den =adjacencyList[posA][i].second.second;
            Simplify(num,den);
            result.first = result.first * num;
            result.second = result.second * den;
        if(adjacencyList[posA][i].first==posB){
            tem = true; //are adjacent   
            Simplify(result.first,result.second);
            result2=result;
        }
        if(visited[adjacencyList[posA][i].first]==false){
            hasPath(adjacencyList,adjacencyList[posA][i].first,posB,visited,result,tem,result2);  
        }
        //if the path taken does not reach the desired node, we undo the operation.
        result.first = result.first / num;
        result.second = result.second / den;                             
    }
} 

int main(){

    char operation,equal;
    string typeA, typeB;
    int m=0,n=0, value=0;
    map<string,int> values;
    vector<vector<pair<int,pair<int,int>>>> adjacencyList;
    adjacencyList.reserve(61);
    
    while(true){
        cin>>operation;
        if(operation=='!'){
            cin>>m>>typeA>>equal>>n>>typeB;
            pair<map<string,int>::iterator,bool> insertedA, insertedB;
            insertedA = values.insert(pair<string,int>(typeA,value));
            if(insertedA.second==true) value++;            
            insertedB = values.insert(pair<string,int>(typeB,value));
            if(insertedB.second==true) value++;
            adjacencyList.resize(values.size());  //For each insertion on map, it means that we have a new different element, 
            //so we need to resize our vector to add to adjacency list at the right position
            adjacencyList[values[typeA]].push_back(make_pair(values[typeB],(make_pair(m,n))));
            adjacencyList[values[typeB]].push_back(make_pair(values[typeA],(make_pair(n,m))));

        }
        else if(operation=='?'){
            pair<int,int>result, result2;
            vector<bool> visited (values.size(),false); //vector to verify, in each consultation, if the node has already been visited
            result.first=result.second=1;
            cin>>typeA>>equal>>typeB;
            bool has=false;
            hasPath(adjacencyList,values[typeA],values[typeB],visited,result,has,result2);
            if (has){
                cout<<result2.first<<" "<<typeA<<" "<<equal<<" "<<result2.second<<" "<<typeB<<"\n";
            }
            else{
                cout<<"?"<<" "<<typeA<<" "<<equal<<" "<<"?"<<" "<<typeB<<"\n";
            }

        }
        else if(operation=='.')break;
    }

        
    return 0;
}