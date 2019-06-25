#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int m, a, b;
    scanf("%d %d %d",&m, &a, &b);


    int c = m - (a+b);

    int res = max(a, max(b,c));
    printf("%d\n", res);

}
