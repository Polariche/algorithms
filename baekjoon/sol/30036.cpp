#include <iostream>
#include <vector>
using namespace std;
#define ll long long



int main() {
    cin.tie(0)->sync_with_stdio(0);
    int I, N, K;
    cin >> I >> N >> K;

    string command;
    string ink_str;
    cin >> ink_str;

    int ink_idx = 0;
    int a = 0;

    int x = 1;
    int y = 1;

    vector<vector<char>> world (N+2, vector<char>(N+2, 0));


    for (int i=0;i<=N+1;i++) {
        for (int j=0;j<=N+1;j++) {
            if (!i || !j || i==N+1 || j==N+1)
                world[i][j] = '#';
            else {
                cin >> world[i][j];
                if (world[i][j] == '@') {
                    world[i][j] = '.';
                    x = i;
                    y = j;
                }
            }
        }
    }

    cin >> command;

    for (int i=0;i<K;i++) {
        switch(command[i]) {
            case 'j': a++; break;
            case 'J': 
                for (int i=max(1, x-a);i<=min(N, x+a);i++) {
                    for (int j=max(1, y-a);j<=min(N, y+a);j++) {
                        if (abs(i-x) + abs(j-y) > a)
                            continue;
                        if (world[i][j] != '.')
                            world[i][j] = ink_str[ink_idx];
                    }
                }
                ink_idx = (ink_idx + 1)%I;
                a=0;

                break;
            case 'U': if (world[x-1][y] == '.') x--; break;
            case 'D': if (world[x+1][y] == '.') x++; break;
            case 'L': if (world[x][y-1] == '.') y--; break;
            case 'R': if (world[x][y+1] == '.') y++; break;
        } 
    }

    for (int i=1;i<N+1;i++) {
        for (int j=1;j<N+1;j++) {
            if (x == i && y == j)
                cout << '@';
            else
                cout << world[i][j];
        }
        cout << "\n";
    }

    return 0;
}