#include<iostream>
using namespace std;
//Wolves just walk up and down, so if we surround all the sheep with dogs, 
//since we can have countless of them, the problem will be solved.

int main(){
    int r=0, c=0; //number of rows and the numbers of columns respectively.
    cin>>r>>c;

    char pasture[r][c]={'.'};
    bool yes = true; //
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            cin>>pasture[i][j];
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(pasture[i][j] == 'S'){
                if(pasture[i-1][j]=='W' && i-1>=0) {yes = false; break;}
                if(pasture[i+1][j]=='W' && i+1<r) {yes = false; break;}
                if(pasture[i][j-1]=='W' && j-1>=0) {yes = false; break;}
                if(pasture[i][j+1]=='W' && j+1<c) {yes = false; break;}
            }
        }
    }
    
    if(yes){
        cout<<"Yes\n";
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(pasture[i][j] == 'S'){
                    if(pasture[i-1][j]=='.' && i-1>=0) pasture[i-1][j]='D';
                    if(pasture[i+1][j]=='.' && i+1<r) pasture[i+1][j]='D';
                    if(pasture[i][j-1]=='.' && j-1>=0) pasture[i][j-1]='D';
                    if(pasture[i][j+1]=='.' && j+1<c) pasture[i][j+1]='D';
                }
            } 
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++)
                cout<<pasture[i][j];
            cout<<"\n";
        }
    }
    else cout<<"No\n";
    return 0;
    
}