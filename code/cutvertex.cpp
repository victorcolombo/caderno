#include <bits/stdc++.h>
using namespace std;
typedef int node;
typedef int edge;

// Dado um grafo conexo nao-dirigido, guarda em is_cut[u]
// se u eh um vertice de corte.
//
// u eh um vertice de corte se:
// 1) u eh raiz da arvore de dfs e tem ao menos dois filhos
// 2) u nao eh raiz da arvore de dfs e tem um filho v tal que
// nenhum vertice na sub-arvore rooteada por v tem uma aresta
// de volta para algum ancestral (na arvore de dfs) de u.

// N = no de vertices, M = no de arestas
const int N = 7, M = 13;
int tim = 0;
int visited[N], parent[N], low[N], disc[N], is_cut[N];
int head[N], nx[2*M], to[2*M];

void cut_vertex (node u){
    int child = 0;
    visited[u] = true;
    disc[u] = low[u] = tim++;
    for(edge e = head[u]; e; e = nx[e]){
        node v = to[e];
        if(!visited[v]){
            child++;
            parent[v] = u;
            cut_vertex(v);
            low[u] = min(low[u],low[v]);
            if(parent[u] == -1 && child > 1) is_cut[u] = true;
            if(parent[u] != -1 && low[v] >= disc[u]) is_cut[u] = true;
        } else if (v != parent[u]) low[u] = min(low[u],disc[v]);
    }
}
