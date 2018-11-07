#include <bits/stdc++.h>
using namespace std;

const int N = 34;

char p[N]; //pattern
int kmp[N];


void KMP() {
    // kmp[i] = maior borda de p[0..i-1]
    // uma borda eh prefixo PROPRIO que eh igual a um sufixo
    int m = strlen(p);
    kmp[1] = 0;
    for(int i = 2; i <= m; i++) {
        kmp[i] = kmp[i-1];
        while(kmp[i] > 0 && p[kmp[i]] != p[i-1])
            kmp[i] = kmp[kmp[i]];
        if(p[kmp[i]] == p[i-1])
            kmp[i]++;
    }
}

char t[N]; //texto

void matches() {
    int n = strlen(t);
    int m = strlen(p);
    int k = 0;
    for(int i = 0; i < n; i++) {
        while(k > 0 && p[k] != t[i]) k = kmp[k];
        if(p[k] == t[i]) k++;
        if(k == m) {
            // match terminando em i
            // portanto comeca em i-m+1
        }
    }
}
