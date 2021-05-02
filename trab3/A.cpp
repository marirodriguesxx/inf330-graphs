#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<queue>
#include <set>
#include <map>
#include<vector>
#include<sstream>   
#include<utility>
using namespace std;

map<string,string> pathes;
map<string,int> values;
pair<map<string,int>::iterator,bool> uniqueNums; //o valor inteiro representa o número de movimentações 

void move( queue<pair<string,pair<int,string>>>&filhos){
    char pos0,pos1;
    for(int i = 0; i < 3; i++){ //percorrendo todas as linhas
        string numberNew=filhos.front().first; 
    int cont = filhos.front().second.first;
    string path = filhos.front().second.second;
        //salvando as colunas 0 1 de cada linha em uma variável auxiliar
        pos0=numberNew[0+3*i];pos1=numberNew[1+3*i];
        //"andando" com os número para a esquerda
        numberNew[0+3*i]=pos1;
        numberNew[1+3*i]=numberNew[2+3*i];
        numberNew[2+3*i]=pos0;
        stringstream ss; ss<<i+1; string intNumber; ss>>intNumber;
        uniqueNums = values.insert(make_pair(numberNew,cont+1));
        if(uniqueNums.second ==true){ 
            stringstream ss; ss<<i+1; string intNumber; ss>>intNumber;
            filhos.push(make_pair(numberNew,make_pair(cont+1,"H"+intNumber+path))); //salvando H1, H2, H3
            pathes[numberNew] = "H"+intNumber+path;
        }
    }
    for(int i = 0; i < 3; i++){ //percorrendo todas as colunas
        //salvando as linhas 0 1 de cada coluna em uma variável auxiliar
            string numberNew=filhos.front().first; 
    int cont = filhos.front().second.first;
    string path = filhos.front().second.second;
        pos0=numberNew[0+i]; pos1=numberNew[3+i];
        //"andando" com os número para baixo
        numberNew[0+i]=numberNew[6+i];
        numberNew[3+i]=pos0;
        numberNew[6+i]=pos1;
        uniqueNums = values.insert(make_pair(numberNew,cont+1));
        if(uniqueNums.second ==true){
            stringstream ss; ss<<i+1; string intNumber; ss>>intNumber;
            filhos.push(make_pair(numberNew,make_pair(cont+1,"V"+intNumber+path))); //salvando V1, V2, V3
            pathes[numberNew] = "V"+intNumber+path;
        }
    }
    filhos.pop();
}

void bfs(){
    queue<pair<string,pair<int,string>>> filhos;
    filhos.push(make_pair("123456789",make_pair(1,"")));
    values.insert(make_pair("123456789",1));
    while(!filhos.empty()){
        move(filhos);
    }   
}

int main(){
    char caracter;
    bfs();
    cout<<values.size()<<endl;

    while(true){
        string number;
        cin>>caracter;
        if(caracter=='0')break;
        number+=caracter;
        for(int i=0; i<8; i++){
            cin>>caracter;
            number+=caracter;
        }
        //caso o elemento exista,seu valor inteiro ja possuira um valor atribuido diferente de zero
        if(values[number]!=0) cout<<values[number]-1<<" "<<pathes[number]<<"\n";         
        else cout<<"Not solvable\n";
    }
    return 0;
}