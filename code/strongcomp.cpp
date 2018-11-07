#include <bits/stdc++.h>
using namespace std;

const int N = 20004;
const int M = 50004;

int n, m, t, tempo, ps, cs, es;
int to[M], head[N], nx[M], vis[N], low[N], d[N], instac[N], st[N], comp[N];

void dfs (int u) {
    vis[u] = 1;
    st[ps++] = u;
    instac[u] = 1;
    low[u] = d[u] = tempo++;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(!vis[v]) {
            dfs(v);
            low[u] = min(low[u],low[v]);
        } else if (instac[v]) low[u] = min(low[u], d[v]);
    }
    if (low[u] == d[u]) {
        int v;
        do {
            v = st[--ps];
            comp[v] = cs;
            instac[v] = 0;
        } while (v != u);
        cs++;
    }
}

int main() {
    es = 2; tempo = cs = 0;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++) head[i] = vis[i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d",&u, &v);
        u--; v--;
        to[es] = v; nx[es] = head[u]; head[u] = es++;
    }
    for(int u = 0; u < n; u++) if(!vis[u]) dfs(u);
    // comp[u] guarda um id unico da componente forte de u
    // os ids estao no intervalo [0, cs-1]
}
