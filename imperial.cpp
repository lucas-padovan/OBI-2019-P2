#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,atual;
int lista[1010];
int p[1010];

int calcula(int a, int b, int coratual, int pos, int resatual) {
    if(pos > n) return resatual;
    if(lista[pos] == coratual) {
        resatual++;
        if(coratual == a) coratual = b;
        else coratual = a;
    }
    if(pos == n) return resatual;

    return calcula(a, b, coratual, pos+1, resatual);
}

int main() {
    int res = 1;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        p[i] = -1;
    }

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        lista[i] = a;
        if(p[a] == -1) p[a] = i;
    }


    for(int i = 1; i <= n; i++) {
        if(p[i] != -1) {
            for(int j = i+1; j <= n; j++) {
                if(p[j] != -1) {
                    int res1 = calcula(i,j,i,p[i],0);
                    int res2 = calcula(j,i,j,p[j],0);
                    int resatual = max(res1, res2);
                    if(resatual > res) res = resatual;
                }
            }
        }
    }

    cout << res << endl;
}
