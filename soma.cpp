#include <stdio.h>
using namespace std;

unsigned long long res = 0;
int lista[501000];
int n, k;
int m[501000][501000];

void dp(int ini, int fim, int soma) {
    if(m[ini][fim] != -1) return;
    if(ini > n || fim > n) return;
    if(soma > k) {
        m[ini][fim] = 0;
        return;
    }
    soma += lista[fim];
    if(soma == k) {
        m[ini][fim] = 1;
        res++;
    }
    dp(ini, fim+1, soma);
    dp(ini+1, ini+1, 0);
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &lista[i]);
        for(int j = 1; j <= n; j++) {
            m[i][j] = -1;
        }
    }
    dp(1,1,0);
    printf("%u\n", res);
}
