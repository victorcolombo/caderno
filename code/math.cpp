typedef long long ll;

ll fexp(ll x, ll e) {
    ll r = 1;
    while(e) {
        if(e&1) r = (x*r) % modn;
        x = (x*x) % modn;
        e >>= 1;
    }
    return r%modn;
}

//p[x] = maior primo q divide x
ll phi(ll n) {
    ll res = 1;
    while(n > 1) {
        ll k = p[n], e = 0;
        while(n%k == 0) {
            e++;
            n /= k;
        }
        res *= (k-1);
        for(int i = 0; i < e-1; i++) res *= k;
    }
    return res;
}


// px + qy = mdc(p,q)
void euclidao (int &x, int &y, int p, int q){
    if(q == 0){
        x = 1, y = 0 ;
        return;
    }
    euclidao(x, y, q, p%q);
    int t = y;
    y = x - (p/q)*y;
    x = t;
}
