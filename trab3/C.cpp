<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

bool isPrime(int num){
    int cont=0;
    if(num==2) return true;
    for(int i=2; i< sqrt(num)+0.0001; i++)
        if(num%i==0)return false;
    return true;
}
void primeVerify(queue<int> &primes, int a){
    for(int i=2; i<a; i++){
        if(a%i==0 && isPrime(i)==true)
            primes.push(i);
    }
}

int bfs(int a,int b){
    queue<pair<int,int>> ab;
    queue<int> x;
    vector<bool> visited(1001,false);

    ab.push(make_pair(a,0));

    while(!ab.empty()){
        int auxA = ab.front().first;
        int t = ab.front().second; 
        ab.pop();
        primeVerify(x,auxA);
        if(auxA==b) return t;
        for(int i=0; !x.empty(); i++){
            int auxX = x.front(); x.pop();
            if(auxA+auxX<=b){
                if(!visited[auxA+auxX]){
                    ab.push(make_pair(auxA+auxX,t+1));
                    visited[auxA+auxX]=true;
                }
            }
        }     
    }
    return -1;
}

int main(){
    int tests=0; //number os tests case
    cin>>tests;

    for(int i=0; i<tests; i++){
        int s,t;
        cin>>s>>t;
        if(s==t){cout<<"Case "<<i+1<<": "<<0<<"\n";continue;}
        else if(s>t || isPrime(s)){cout<<"Case "<<i+1<<": "<<-1<<"\n";continue;}
        int resp = bfs(s,t);
        cout<<"Case "<<i+1<<": "<<resp<<"\n";
    }
    return 0;
=======
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

bool isPrime(int num){
    int cont=0;
    if(num==2) return true;
    for(int i=2; i< sqrt(num)+0.0001; i++)
        if(num%i==0)return false;
    return true;
}
void primeVerify(queue<int> &primes, int a){
    for(int i=2; i<a; i++){
        if(a%i==0 && isPrime(i)==true)
            primes.push(i);
    }
}

int bfs(int a,int b){
    queue<pair<int,int>> ab;
    queue<int> x;
    vector<bool> visited(1001,false);

    ab.push(make_pair(a,0));

    while(!ab.empty()){
        int auxA = ab.front().first;
        int t = ab.front().second; 
        ab.pop();
        primeVerify(x,auxA);
        if(auxA==b) return t;
        for(int i=0; !x.empty(); i++){
            int auxX = x.front(); x.pop();
            if(auxA+auxX<=b){
                if(!visited[auxA+auxX]){
                    ab.push(make_pair(auxA+auxX,t+1));
                    visited[auxA+auxX]=true;
                }
            }
        }     
    }
    return -1;
}

int main(){
    int tests=0; //number os tests case
    cin>>tests;

    for(int i=0; i<tests; i++){
        int s,t;
        cin>>s>>t;
        if(s==t){cout<<"Case "<<i+1<<": "<<0<<"\n";continue;}
        else if(s>t || isPrime(s)){cout<<"Case "<<i+1<<": "<<-1<<"\n";continue;}
        int resp = bfs(s,t);
        cout<<"Case "<<i+1<<": "<<resp<<"\n";
    }
    return 0;
>>>>>>> 29eb03765de23803efe880508b16e213c244ae4b
}