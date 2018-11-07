#include <bits/stdc++.h>
using namespace std;

typedef int node;
typedef int edge;

const int N = 7;
const int K = 20;

int l[N][K], dep[N];
int head[N], to[2*N], nx[2*N];

// l[u][k] guarda o 2^k pai do vertice u
// Eh necessario que o pai da raiz seja ela mesma!

void dfs (node u, node p, int d) {
    l[u][0] = p; dep[u] = d;
    for (int i = 1; i < K; i++)
        l[u][i] = l[l[u][i-1]][i-1];
    for (edge e = head[u]; e; e = nx[e]){
        node v = to[e];
        if (v != p) dfs(v, u, d + 1);
    }
}

node lca (node u, node v) {
    if (dep[u] > dep[v]) swap(u,v);
    if (dep[u] < dep[v]) {
        for (int i = K-1; i >= 0; i--)
            if(dep[l[v][i]] >= dep[u])
                v = l[v][i];
    }
    if (u == v) return v;
    for (int i = K-1; i >= 0; i--)
        if(l[v][i] != l[u][i])
           v = l[v][i], u = l[u][i];
   return l[v][0]; 
}
