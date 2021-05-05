#include<iostream>
#include <cmath>
#include<vector>
#include<iomanip>
using namespace std;

const double INF=20000000.0;
const int maxn=110;
double distances[maxn][maxn];
int f;

double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

double prim(const vector<vector<double>> &distances,bool visited[], int start){
    visited[start] = true;
    double menor = 1.0e99;
    int menorPos = -1;
    for(int i=0; i<distances[start].size(); i++){
        if(distances[start][i]!=0 && distances[start][i]<menor && !visited[i]){
            menor = distances[start][i];
            menorPos = i;
        } 
    }
    if(menorPos=-1) return 0;
    else return menor + prim(distances,visited,menorPos);
}

double prim2(vector<vector<double>> &distances, int f){
    double aux[f];
    int visited[f]={-1};
    double resp=0;
    for(int i=0;i<f;i++) aux[i]=distances[i][0];
    aux[0]=0;
    visited[0]=0;
    for(int i=1; i<f; i++){
        double menor=1.0e99;
        int menorPos;
        for(int j=0;j<f;j++){
            if(visited[j] && aux[j]<menor){
                menor=aux[j];
                menorPos=j;
            }
        }

        resp+=menor;
        visited[menorPos]=0;
        for(int j=0;j<f;j++){
            if(visited[j] && aux[j]>distances[menorPos][j])   
                aux[j]=distances[menorPos][j];
        }
    }
    return resp;
}
double prim3()
{
    double d[maxn];
    int visit[maxn];
    double sum=0;
    for(int i=0;i<f;i++)    d[i]=distances[i][0];
    d[0]=0;
    visit[0]=0;
    memset(visit,-1,sizeof(visit));
    for(int i=1;i<f;i++)
    {
        double minv=INF;
        int v;
        for(int j=0;j<f;j++)
        {
            if(visit[j]&&d[j]<minv)     {minv=d[j];v=j;}
        }
        sum+=minv;
        visit[v]=0;
                //update
        for(int j=0;j<f;j++)
        {
            if(visit[j]&&(d[j]>distances[v][j]))   d[j]=distances[v][j];
        }
    }
    cout<<sum<<endl;
    return sum;
}

int main(){
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        //int f;
        cin>>f;
        //vector<vector<double>> distances(f, vector<double>(f,0));
        pair<double,double> freckles[f];
        for(int j=0; j<f; j++){
            cin>>freckles[j].first>>freckles[j].second;
        }
        for(int j=0; j<f; j++){
            //distances[j][j] = 0; // a distancia de um nodo para ele mesmo eh sempre zero
            for(int k=j; k<f; k++){
                distances[j][k] = dist(freckles[j].first, freckles[j].second, freckles[k].first, freckles[k].second);
                distances[k][j] = distances[j][k];
            }
        }
        printf("%.2lf\n",prim());
        //cout<<fixed<<setprecision(2)<<prim(distances,visited,0)<<"\n";
    }
    return 0;

}