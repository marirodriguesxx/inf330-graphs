#include<iostream>
#include <vector>
#include<algorithm>
#include <utility>
#include <map>
#include <iterator>
#include <queue>
using namespace std;

void solve(vector<vector<char>> &matrix, vector<pair<int,int>> &startF, int rows, int cols, int &minutes,pair<int,int> &startJ){

    queue<pair<int,int>> f,j;
    for(int i=0;  i<startF.size();i++) f.push(startF[i]);
    j.push(startJ);
    pair<int,int> auxF, auxJ, upF, downF, leftF, rightF, upJ, downJ, leftJ, rightJ;
    
    while(true){
        int auxF2, auxJ2;
        auxF2=f.size(); auxJ2=j.size();

        for(int i=0; i<auxF2; i++){
        //findg next fire positions
            auxF = f.front(); f.pop(); //saving the element to remove later
            if(auxF.first-1>=0 && matrix[auxF.first-1][auxF.second]!='#' && matrix[auxF.first-1][auxF.second]!='F') 
                {upF.first=auxF.first-1; upF.second=auxF.second;f.push(upF);matrix[auxF.first-1][auxF.second]='F';}
            if(auxF.first+1<rows && matrix[auxF.first+1][auxF.second]!='#'&& matrix[auxF.first+1][auxF.second]!='F') 
                {downF.first=auxF.first+1; downF.second=auxF.second;f.push(downF);matrix[auxF.first+1][auxF.second]='F';}
            if(auxF.second-1>=0 && matrix[auxF.first][auxF.second-1]!='#'&& matrix[auxF.first][auxF.second-1]!='F') 
                {leftF.first=auxF.first; leftF.second=auxF.second-1;f.push(leftF);matrix[auxF.first][auxF.second-1]='F';}
            if(auxF.second+1<cols && matrix[auxF.first][auxF.second+1]!='#' && matrix[auxF.first][auxF.second+1]!='F') 
                {rightF.first=auxF.first; rightF.second=auxF.second+1;f.push(rightF);matrix[auxF.first][auxF.second+1]='F';}
        }
        
        for(int i=0; i<auxJ2; i++){
            auxJ = j.front(); j.pop(); //saving the element to remove later
            if(auxJ.first-1<0){return;}
            if(auxJ.first+1==rows){return;}
            if(auxJ.second+1==cols){return;}
            if(auxJ.second-1<0){return;}

            //findg next joe positions
            if(matrix[auxJ.first-1][auxJ.second]=='.')
                {upJ.first=auxJ.first-1; upJ.second=auxJ.second;matrix[auxJ.first-1][auxJ.second]='J';j.push(upJ);}
            if(matrix[auxJ.first+1][auxJ.second]=='.')
                {downJ.first=auxJ.first+1; downJ.second=auxJ.second;matrix[auxJ.first+1][auxJ.second]='J';j.push(downJ);}
            if(matrix[auxJ.first][auxJ.second-1]=='.')
                {leftJ.first=auxJ.first; leftJ.second=auxJ.second-1;matrix[auxJ.first][auxJ.second-1]='J';j.push(leftJ);}
            if(matrix[auxJ.first][auxJ.second+1]=='.')
                {rightJ.first=auxJ.first; rightJ.second=auxJ.second+1;matrix[auxJ.first][auxJ.second+1]='J';j.push(rightJ);}  
        }                
        if(j.empty()){minutes=-1;break;}
        minutes=minutes+1;      
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int r,c,minutes=1;
        cin>>r>>c;
        vector<vector<char>> matrix(r,vector<char>(c));
        vector<vector<int>> joeV(r,vector<int>(c)), fireV(r,vector<int>(c));
        pair<int,int>startJ;
        vector<pair<int,int>>startF;    
        for(int j=0; j<r; j++){
            for(int k=0; k<c; k++){
                cin>>matrix[j][k];
                joeV[j][k]=0; fireV[j][k]=0;
                if(matrix[j][k]=='J'){startJ.first=j; startJ.second=k;}
                if(matrix[j][k]=='F'){startF.push_back(make_pair(j,k));}
            }
        }
        solve(matrix,startF,r,c,minutes,startJ);
        if(minutes==-1)cout<<"IMPOSSIBLE\n";
        else cout<<minutes<<"\n";

    }
    return 0;   
}