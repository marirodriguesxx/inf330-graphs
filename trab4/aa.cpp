//Uva 10034 - Freckles
//Minimum spanning tree problem, using Prim algorithm
#include <iostream>
#include <cmath>
#include <cstdio>
#include <memory.h>
#define eps 1e-6
using namespace std;
const double INF=20000000.0;
const int maxn=110;
int n;
double a[maxn][maxn];//adjacency matrix
struct point
{
    double x;
    double y;
}p[maxn];
double dis(point p1,point p2)
{
    double x=p2.x-p1.x;
    double y=p2.y-p1.y;
    return sqrt(x*x+y*y);
}
double prim()
{
    double d[maxn];
    int visit[maxn];
    double sum=0;
    for(int i=0;i<n;i++)    d[i]=a[i][0];
    d[0]=0;
    memset(visit,-1,sizeof(visit));
    visit[0]=0;
    for(int i=1;i<n;i++)
    {
        double minv=INF;
        int v;
        for(int j=0;j<n;j++)
        {
            if(visit[j]&&d[j]<minv)     {minv=d[j];v=j;}
        }
        sum+=minv;
        visit[v]=0;
                //update
        for(int j=0;j<n;j++)
        {
            if(visit[j]&&(d[j]>a[v][j]))   d[j]=a[v][j];
        }
    }
    return sum;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)    cin>>p[i].x>>p[i].y;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
            a[i][j]=dis(p[i],p[j]);
            a[j][i]=a[i][j];
        }
        printf("%.2lf\n",prim());
        if(t)   cout<<endl;
    }
    return 0;
}