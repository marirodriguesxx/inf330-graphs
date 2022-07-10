/**
 *   //////////////////
 *   // MAXIMUM FLOW //
 *   //////////////////
 *
 * This file is part of my library of algorithms found here:
 *      http://www.palmcommander.com:8081/tools/
 * LICENSE:
 *      http://www.palmcommander.com:8081/tools/LICENSE.html
 * Copyright (c) 2004
 * Contact author:
 *      igor at cs.ubc.ca
 **/

/****************
 * Maximum flow * (Ford-Fulkerson on an adjacency matrix)
 ****************
 * Takes a weighted directed graph of edge capacities as an adjacency 
 * matrix 'cap' and returns the maximum flow from s to t.
 *
 * PARAMETERS:
 *      - cap (global): adjacency matrix where cap[u][v] is the capacity
 *          of the edge u->v. cap[u][v] is 0 for non-existent edges.
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 *      - s: source vertex.
 *      - t: sink.
 * RETURNS:
 *      - the flow
 *      - fnet contains the flow network. Careful: both fnet[u][v] and
 *          fnet[v][u] could be positive. Take the difference.
 *      - p contains the minimum cut. If p[v] == -1, then v is not
 *          reachable from s; otherwise, it is reachable.
 * DETAILS:
 * FIELD TESTING:
 *      - Valladolid 10330: Power Transmission
 *      - Valladolid 653:   Crimewave
 *      - Valladolid 753:   A Plug for UNIX
 *      - Valladolid 10511: Councilling
 *      - Valladolid 820:   Internet Bandwidth
 *      - Valladolid 10779: Collector's Problem
 * #include <string.h>
 * #include <queue>
 **/

#include <string.h>
#include<algorithm>
#include<iostream>
#include <fstream>
#include <string.h>
using namespace std;

// the maximum number of vertices
#define NN 1024

// adjacency matrix (fill this up)
int cap[NN][NN];

// flow network
int fnet[NN][NN];

// BFS
int q[NN], qf, qb, p[NN];

int fordFulkerson( int n, int s, int t )
{
    // init the flow network
    memset( fnet, 0, sizeof( fnet ) );

    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( p, -1, sizeof( p ) );
        qf = qb = 0;
        p[q[qb++] = s] = -2;
        while( qb > qf && p[t] == -1 )
            for( int u = q[qf++], v = 0; v < n; v++ )
                if( p[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
                    p[q[qb++] = v] = u;

        // see if we're done
        if( p[t] == -1 ) break;

        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for( int v = t, u = p[v]; u >= 0; v = u, u = p[v] )
            bot=min(bot,cap[u][v] - fnet[u][v] + fnet[v][u]);
            //bot <?= cap[u][v] - fnet[u][v] + fnet[v][u];

        // update the flow network
        for( int v = t, u = p[v]; u >= 0; v = u, u = p[v] )
            fnet[u][v] += bot;

        flow += bot;
    }
    return flow;
}

//----------------- EXAMPLE USAGE - Software Allocation (A) -----------------
int main()
{
    memset( cap, 0, sizeof( cap ) );
    int numVertices = 40;
    string line;
    int s=36, t=37;
    while(getline(cin, line)){
        int cont=0;
        cap[s][(int)line[0]-55] = line[1]-'0';
        cont+=line[1]-'0';
        for(int i=3; i<line.size()-1; i++) {cap[(int)line[0]-55][line[i]-'0']=1;cap[line[i]-'0'][t]=1;}
        
        while(getline(cin, line)){
            if(line.empty()){break;}
            cap[s][(int)line[0]-55] = line[1]-'0';
            cont+=line[1]-'0';
            for(int i=3; i<line.size()-1; i++) {cap[(int)line[0]-55][line[i]-'0']=1;cap[line[i]-'0'][t]=1;}
        }
        int resp =fordFulkerson( numVertices, s, t );
        if(resp<cont) cout<<"!\n";
        else{
            for(int i=0; i<10; i++){
                bool exists=false;
                bool hasfluxo=false;
                for(int j=10; j<36; j++){
                    if(cap[i][j]>0)exists=true;
                    if(fnet[j][i]-fnet[i][j]==1 ) {cout<<(char)(j+55); hasfluxo=true;}
                }
                if(!exists && !hasfluxo)cout<<"_";
            }
            cout<<"\n";
        }
        memset( cap, 0, sizeof( cap ) );      
    }
    return 0;
}