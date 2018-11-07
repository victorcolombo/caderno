#include <bits/stdc++.h>
using namespace std;

const int N = 123;

// emparelhamento maximo em grafo bipartido - O(VE)

int vis[N];
vector<int> adj[N];
int M[N]; // M[u] eh o vertice emparelho com u. -1 se nao existir.


int dfs(int u) {
    if(vis[u]) return 0;
    vis[u] = 1;
    for(int v : adj[u]) {
        if(M[v] == -1 || dfs(M[v])) {
            M[u] = v;
            M[v] = u;
            return 1;
        }
    }
    return 0;
}

int maxmatch() {
    memset(M, -1, sizeof M);
    int esq = 7; //assumindo q os esq primeiros sao um lado da biparticao
    int ans = 0;
    for(int i = 0; i < esq; i++) {  //so precisa fazer pra um lado da biparticao
        memset(vis,0,sizeof vis); //da pra fazer com turn++ tambem
        if(dfs(i)) ans++;
    }
    return ans;
}
