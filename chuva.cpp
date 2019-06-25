#include <iostream>
using namespace std;

char casa[1010][1010];

void paint(int x, int y) {
    if(casa[x+1][y] == '.') {
        casa[x+1][y] = 'o';
        paint(x+1, y);
    }
    if(casa[x][y+1] == '.' && casa[x+1][y] == '#') {
        casa[x][y+1] = 'o';
        paint(x, y+1);
    }
    if(casa[x][y-1] == '.' && casa[x+1][y] == '#') {
        casa[x][y-1] = 'o';
        paint(x, y-1);
    }

    return;
}

int main() {
    int n, m;
    cin >> n >> m;

    int xini = 0;
    int yini = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            casa[i][j] = 'X';
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> casa[i][j];
            if(casa[i][j] == 'o') {
                xini = i;
                yini = j;
            }
        }
    }

    paint(xini, yini);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << casa[i][j];
        }
        cout << endl;
    }


}
