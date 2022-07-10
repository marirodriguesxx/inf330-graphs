#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <array>
#include <algorithm>
#include <set>
using namespace std;

/*
Grafo com matriz de adjacencia...
2-sat
Implementado por salles
*/
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>

using namespace std;




//nao sigam este exemplo! Normalmente usamos esses defines apenas em competicoes de programacao para ganhar tempo!
#define f(i,k) for(int i=0;i<k;i++)


struct Sat2 {

public:
    //Cria o grafo de 2-Sat (inicialmente vazio) com numVariaveis variaveis (contamos a partir de 1)
    Sat2(int numVariaveis) {
        vars = numVariaveis;
        implica = vector<vector<vector<int> > >(numVariaveis+1, vector<vector<int>>(2));
        valor = vector<int>(numVariaveis+1,-1);     
    }
    //Adiciona uma clausula ao 2-Sat contendo as variaveis c1 e c2
    //As variaveis devem contar a partir de 1 !!!!
    //Adiciona a clausula: 
    //Se ambos v1 v2 true: (c1 OR c2)
    //Se v1 for false: (!c1 OR c2)
    //Se v2 for false: (c1 OR !c2)
    //Se ambos  false: (!c1 OR !c2)
    void addClausula(int c1,bool v1,int c2, bool v2) {
        implica[c1][!v1].push_back( c2*(v2?1:-1)  ); //-1 indica ~
        implica[c2][!v2].push_back( c1*(v1?1:-1) ); // ~c2 -> c1 (ou ~c2 -> ~c1 (<==> -c1) )
    }


    //No seu trabalho voce devera utilizar apenas a funcao "addImplicacao"
    //termine essa implementacao abaixo!
    //dica : a solucao sera MUITO simples . Apenas reaproveite a funcao addClausula e chame-a abaixo...
    //Adiciona uma implicacao do tipo (c1 --> c2)
    //se valor for false: (!c1 --> c2)
    //se valor2 for false: (c1 --> !c2)
    //se ambos false: (!c1 --> !c2)
    void addImplicacao(int c1, bool valor, int c2, bool valor2) {
        //TODO: termine isso!
        addClausula(c1,!valor,c2,valor2);
    }

    //retorna true iff a formula for satisfativel...
    bool satisfativel() {       
        for (int i = 1; i <= vars; ++i) {
           if ( !verificaVariavel(i) ) { //Se nao funciona com i = false e nem com i=true ==> nao funciona mesmo!
             return false;
           }
        }
        //se nenhuma variavel gera "conflitos" --> entao formula eh satisfativel...
        return true;
    }
private:
    vector<vector< vector<int> > > implica; //grafo de implicacao... implica[x][0] = vertice da variavel x valendo false. implica[x][1] = vertice de x valendo true
                                            //em cada variavel temos a sua lista de adjacencia.
                                            //Se 4 esta em implica[2][0] , isso significa que !2 --> 4
                                            //Se -4 esta em implica[2][0], isso significa que !2 --> !4 (ou seja, numeros negativos indicam NOT)
    vector<int> valor;
    int vars;
    
    
    //verifica se funciona atribuir o valor val para a variavel x
    //o valor podera ser 0 (false) ou 1 (true)
    //-1 indica que ainda nao atribui um valor booleano para a variavel..
    bool funciona(int x, int val) {
        if (valor[x]!=-1) { //já atribuí valor...
                return valor[x]==val; //Para funcionar, o valor desejado deve ser o mesmo valor que foi atribuido a x...
        }
        valor[x] = val; //Para funcionar, x deverá valer: val
        
        f(i,implica[x][val].size()) 
             if (!funciona( abs(implica[x][val][i]), (implica[x][val][i]<0 ? 0:1) ) ) { //Se x->y, y nao deve implicar na variavel x valer ~val...
                 valor[x] = -1;
                 return false;
             }    
                                  
        return true; 
    }
      

    //Verifica se tudo esta ok com a variavel i no grafo de implicacao...
    //Se i nao puder ser true nem false --> nao esta ok --> retorna false
    bool verificaVariavel(int i) { 
        f(k,vars+1) valor[k]=-1;
        if ( funciona(i,0) ) return true; //Funciona com a variavel i = ~i ?
        f(k,vars+1) valor[k]=-1;
        if ( funciona(i,1) ) return true; //Funciona com a variavel i = i ?
        return false; 
    }    
            


};


 
int main() {	
    //No seu trabalho, voce devera implementar a funcao "addImplicacao" e utiliza-la
    //nao utilize a funcao addClausula (diretamente) para resolver seu trabalho! Use apenas a funcao addImplicacao

    int n, n_streets, n_avenues, n_routes;
    cin>>n; //how many city descriptions 
    for(int i=0; i<n; i++){
        cin>>n_streets>>n_avenues>>n_routes;
        Sat2 solver(n_routes*10);
        int routeDef[n_routes][4];
        for(int j=0; j<n_routes; j++){
            cin>>routeDef[j][0]>>routeDef[j][1]>>routeDef[j][2]>>routeDef[j][3];
        }
        for(int j=0; j<n_routes; j++){
            int linha1 = routeDef[j][0], coluna1 = routeDef[j][1];
            int linha2 = routeDef[j][2], coluna2 = routeDef[j][3];
            //definindo os quadrantes   
            if(linha1!=linha2 && coluna1!=coluna2){
                if(linha2 < linha1 && coluna2 > coluna1 ){
                    solver.addImplicacao(routeDef[j][1],true,routeDef[j][0]+n_avenues,true);
                    solver.addImplicacao(routeDef[j][1],true,routeDef[j][3],false);
                    solver.addImplicacao(routeDef[j][2]+n_avenues,false,routeDef[j][0]+n_avenues,true);
                    solver.addImplicacao(routeDef[j][2]+n_avenues,false,routeDef[j][3],false);
                }
                if(linha2 < linha1 && coluna2 < coluna1 ){
                    solver.addImplicacao(routeDef[j][2]+n_avenues,true,routeDef[j][0]+n_avenues,false);
                    solver.addImplicacao(routeDef[j][2]+n_avenues,true,routeDef[j][3],false);
                    solver.addImplicacao(routeDef[j][1],true,routeDef[j][0]+n_avenues,false);
                    solver.addImplicacao(routeDef[j][1],true,routeDef[j][3],false);
            
                    solver.addImplicacao(routeDef[j][3],true,routeDef[j][1],false);
                    solver.addImplicacao(routeDef[j][3],true,routeDef[j][2]+n_avenues,false);
                    solver.addImplicacao(routeDef[j][0]+n_avenues,true,routeDef[j][1],false);
                    solver.addImplicacao(routeDef[j][0]+n_avenues,true,routeDef[j][2]+n_avenues,false);
                }
                if(linha2 > linha1 && coluna2 < coluna1 ){
                    solver.addImplicacao(routeDef[j][2]+n_avenues,true,routeDef[j][0]+n_avenues,false);
                    solver.addImplicacao(routeDef[j][2]+n_avenues,true,routeDef[j][3],true);
                    solver.addImplicacao(routeDef[j][1],false,routeDef[j][0]+n_avenues,false);
                    solver.addImplicacao(routeDef[j][1],false,routeDef[j][3],true);
                }
                if(linha2 > linha1 && coluna2 > coluna1 ){
                    solver.addImplicacao(routeDef[j][2]+n_avenues,false,routeDef[j][0]+n_avenues,true);
                    solver.addImplicacao(routeDef[j][2]+n_avenues,false,routeDef[j][3],true);
                    solver.addImplicacao(routeDef[j][1],false,routeDef[j][0]+n_avenues,true);
                    solver.addImplicacao(routeDef[j][1],false,routeDef[j][3],true);


                    solver.addImplicacao(routeDef[j][0]+n_avenues,false,routeDef[j][2]+n_avenues,true);
                    solver.addImplicacao(routeDef[j][0]+n_avenues,false,routeDef[j][1],true);
                    solver.addImplicacao(routeDef[j][3],false,routeDef[j][2]+n_avenues,true);
                    solver.addImplicacao(routeDef[j][3],false,routeDef[j][1],true);
                }

            }
            else if(linha1==linha2 && coluna1!=coluna2){
                if(coluna2 > coluna1) solver.addImplicacao(routeDef[j][0]+n_avenues,false,routeDef[j][0]+n_avenues,true);
                if(coluna2 < coluna1) solver.addImplicacao(routeDef[j][0]+n_avenues,true,routeDef[j][0]+n_avenues,false);
            }
            else if(linha1!=linha2 && coluna1==coluna2){
                if(linha2 > linha1) solver.addImplicacao(routeDef[j][1],false,routeDef[j][1],true);
                if(linha2 < linha1) solver.addImplicacao(routeDef[j][1],true,routeDef[j][1],false); 
            }
        }
        cout << (solver.satisfativel()?"Yes":"No") << endl;
    }
    return 0;
}