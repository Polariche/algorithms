#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void test() {
    int N, a, b;
    cin >> N >> a >> b;
    string s;
    cin >> s;

    int x = 0, y = 0;

    for (int k=0;k<2000;k++) {
        
        for (int i=0;i<=N;i++) {
            if (i>0) {
                switch(s[i-1]) {
                    case 'N': y++;  break;
                    case 'E': x++;  break;
                    case 'S': y--;  break;
                    case 'W': x--;  break;
                }
            }
            if (x == a && y == b) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}