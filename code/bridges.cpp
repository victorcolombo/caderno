#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef int node;
typedef int edge;

// Semelhante ao algoritmo de achar vertices de corte,
// uma aresta (u,v) onde u eh pai de v na arvore de dfs,
// eh uma ponte se nao existe uma aresta que volta para
// u ou seus ancestrais na subarvore rooteada em v.

// obs: usando a representacao de listas encadeadas estaticas,
// sabemos que a aresta 'e' liga (to[e^1], to[e])

// N = no de vertices, M = no de arestas
const int N = 7, M = 13;
int tim = 0;
int visited[N], disc[N], low[N], parent[N];
int head[N], to[2*M], nx[2*M];
vector<int> bridges;

void get_bridges(node u){
    visited[u] = true;
    disc[u] = low[u] = tim++;
    for(edge e = head[u]; e; e = nx[e]){
        node v = to[e];
        if(!visited[v]){
            parent[v] = u;
            get_bridges(v);
            low[u] = min(low[u],low[v]);
            if(low[v] > disc[u]) bridges.pb(e);
        } else if (v != parent[u]) low[u] = min(low[u], disc[v]);
    }
}
