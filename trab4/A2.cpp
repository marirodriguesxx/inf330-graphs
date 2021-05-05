#include <iostream>
#include <cmath>
#include<vector>
#include<iomanip>
using namespace std;

double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

double prim(const vector<vector<double>> &distances, int f){
    double d[f];
    vector<bool> visited(f,false);
    double resp=0;
    for(int i=0;i<f;i++) d[i]=distances[i][0];
    d[0]=0;
    visited[0]=true;
    for(int i=1;i<f;i++){
        double menor=1.0e99;
        int menorPos;
        for(int j=0;j<f;j++){
            if(!visited[j]&&d[j]<menor){
                menor=d[j];
                menorPos=j;
            }
        }
        resp+=menor;
        visited[menorPos]=true;
        for(int j=0;j<f;j++){
            if(!visited[j] && d[j]>distances[menorPos][j]) d[j]=distances[menorPos][j];
        }
    }
    return resp;
}
int main(){
    int cases;
    cin>>cases;
    for(int c=0; c<cases; c++){
        int f;
        cin>>f;
        pair<double,double> freckles[f];
        for(int j=0; j<f; j++){
            cin>>freckles[j].first>>freckles[j].second;
        }
        vector<vector<double>> distances(f, vector<double>(f,0));
        for(int i=0;i<f;i++){
            for(int j=i;j<f;j++){
                distances[i][j]=dist(freckles[i].first, freckles[i].second, freckles[j].first, freckles[j].second);
                distances[j][i]=distances[i][j];
            }
        }
        cout<<fixed<<setprecision(2)<<prim(distances,f)<<"\n";
        if(c!=cases-1) cout<<"\n";
    }
    return 0;
}