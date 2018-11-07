#include <bits/stdc++.h>
using namespace std;
const int N = 23;
char s[N];
int z[N];

void Z() {
    int n = strlen(s);
    z[0] = 0; //indefinido - pode ser mudado sem problemas
    int l, r; l = r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r) z[i] = min(z[i-l], r-i+1);
        while(z[i] + i < n && s[z[i] + i] == s[z[i]]) z[i]++;
        if(r < i + z[i] - 1) l = i, r = i + z[i] - 1;
    }
}
