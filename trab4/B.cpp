#include <iostream>
#include <cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

class UnionFind {
	private:
		vector<int> representante;
	public:
		void createSet(int tam) {
			representante.resize(tam);
			for(int i=0;i<tam;i++)
				representante[i] = i;
		}
		//Retorna o representante do conjunto que contem
		//o elemento "elemento"
		int findSet(int elemento) {
			if (representante[elemento]==elemento) 
				return elemento;
			//Compressao do caminho...
			representante[elemento] = findSet(representante[elemento]);
			return representante[elemento];
		}
		void mergeSets(int i,int j) {
			representante[ findSet(i) ] = findSet(j);
		}
		bool isSameSet(int i,int j) {
			return (findSet(i)==findSet(j));
		}

};

struct Edge{
	int u, v;
	double c;
	Edge(int u = -1, int v = -1,double c = 0) : u(u), v(v), c(c) { }
};

bool operator <(const Edge &i,const Edge &j) {
	return i.c<j.c; //alteracao feita para quer ordene o vetor de forma descendente
}

void Kruskal(vector<Edge> &costs, int n,int r, double &s, double &roads, double &rl){
	sort(costs.begin(),costs.end());

	UnionFind c; c.createSet(n);
	int resp =0;
	for(int i=0;i<costs.size();i++) {
		if(!c.isSameSet(costs[i].u, costs[i].v)){ //se nao forma nenhum ciclo, adicionamos
            if(costs[i].c>=r){rl+=costs[i].c; s++;}
            else{roads+=costs[i].c;}
			c.mergeSets(costs[i].u, costs[i].v );
		}
	}
}
int main(){
    int cases;
    cin>>cases;
    for(int c=0; c<cases; c++){
        int n,r;
        cin>>n>>r;
        pair<int,int> coordinates[n];
        for(int j=0; j<n; j++){
            cin>>coordinates[j].first>>coordinates[j].second;
        }
        vector<Edge> d;
        vector<vector<int>> distances(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                Edge aux;
                aux.u = i; aux.v =j;
                aux.c = dist(coordinates[i].first, coordinates[i].second, coordinates[j].first, coordinates[j].second);
                d.push_back(aux);
            }
        }
        double s=0, roads=0, rl=0;
        Kruskal(d,n,r,s,roads,rl);
        cout<<"Case #"<<c+1<<": "<<round(s+1)<<" "<<round(roads)<<" "<<round(rl)<<"\n";

    }
    return 0;
}