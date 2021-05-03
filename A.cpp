#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

bool gira(queue<string>&fila){
    string novo;
    char aux1,aux2;
    for (int i = 0; i < 3; i++){
        novo=fila.front();
        aux1=novo[0+3*i];
        aux2=novo[1+3*i];
        novo[0+3*i]=novo[2+3*i];
        novo[1+3*i]=aux1;
        novo[2+3*i]=aux2;
        fila.push(novo);
    }
    for (int i = 0; i < 3; i++){
        novo=fila.front();
        aux1=novo[0+i];
        aux2=novo[3+i];
        novo[0+i]=novo[6+i];
        novo[3+i]=aux1;
        novo[6+i]=aux2;
        fila.push(novo);
    }
    fila.pop();
}

int main(){
    while (true){
        string p,s,t;
        getline(cin,p);
        if(p[0]=='0')
            break;
        p.erase(p.begin()+1);
        p.erase(p.begin()+2);
        getline(cin,s);
        s.erase(s.begin()+1);
        s.erase(s.begin()+2);
        getline(cin,t);
        t.erase(t.begin()+1);
        t.erase(t.begin()+2);
        p+=s;
        p+=t;
        queue<string>fila;
        fila.push(p);
        //gira(fila);
        int aux=fila.size();
        for (int i = 0; i < aux; i++){
            cout << fila.front() << endl;
            fila.pop();
        }
        cout <<"--------"<<endl;
    }
}