/*
 * nxt[i] = vértice mais alto da chain de i
 * p[i] = parente de i
 * query(in[a], in[b]) é a query entre os nós a e b na mesma chain (a mais alto que b)
 * Cuidado entre queries em vértices vs arestas! (limites inclusivos e exclusivos)
 */

int sz[MAXV];
vector<int> g[MAXV];

void dfs_sz(int v = 0) {
    sz[v] = 1;
    for(auto &u: g[v])
    {
        dfs_sz(u);
        sz[v] += sz[u];
        if(sz[u] > sz[g[v][0]])
            swap(u, g[v][0]);
    }
}

int in[MAXV], rin[MAXV], nxt[MAXV], out[MAXV], lvl[MAXV], t;

void dfs_hld(int v = 0, int h = 0) {
    lvl[v] = h;
    in[v] = t++;
    rin[in[v]] = v;
    for(auto u: g[v])
    {
        nxt[u] = (u == g[v][0] ? nxt[v] : u);
        dfs_hld(u, h + 1);
    }
    out[v] = t;
}

int p[MAXV];

int query_path(int a, int b) {
    int ans = INT_MIN;
    while (nxt[a] != nxt[b]) {
        if (lvl[nxt[a]] > lvl[nxt[b]]) {
            ans = max(ans, query(in[nxt[a]], in[a]));
            a = p[nxt[a]];
        } else {
            ans = max(ans, query(in[nxt[b]], in[b]));
            b = p[nxt[b]];
        }
    }
    if (lvl[a] > lvl[b]) swap(a, b);
    return max(ans, query(in[a] + 1, in[b]));
}
