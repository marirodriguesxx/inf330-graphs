#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


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
	int c;
	Edge(int u = -1, int v = -1,int c = 0) : u(u), v(v), c(c) { }
};

bool operator <(const Edge &i,const Edge &j) {
	return i.c>j.c; //alteracao feita para quer ordene o vetor de forma descendente
}

int Kruskal(vector<Edge> &costs, int n) {
	sort(costs.begin(),costs.end());

	UnionFind conjuntos;
	conjuntos.createSet(n);
	int resp =0;

	for(int i=0;i<costs.size();i++) {
		if(!conjuntos.isSameSet(costs[i].u, costs[i].v)){ //se nao forma nenhum ciclo, adicionamos
			resp = costs[i].c; //como estamos adicionando de forma descendente, o ultimo custo a ser adicionado ja sera o menor
			conjuntos.mergeSets(costs[i].u, costs[i].v );
		}
	}
	return resp;
}

int main(){
	int tests;
    cin >> tests;
    for(int t=0; t<tests; t++){
        int n,m;
        cin>>n>>m;
        vector<Edge> costs;
        for(int i=0; i<m; i++){
			Edge aux;
            cin>>aux.u>>aux.v>>aux.c;
            costs.push_back(aux);
            
        }
        cout<<"Case #"<<t+1<<": "<<Kruskal(costs,n)<<"\n";
    }
    return 0;
}



