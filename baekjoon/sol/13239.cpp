#include <iostream>
using namespace std;

#define ll long long
#define M 1000000007

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll arr[1001][1001];

    int N;
    cin >> N;

    for (int i=1;i<=1000;i++) {
        for (int j=0;j<=i;j++) {
            if (j==0 || i==j) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = (arr[i-1][j] + arr[i-1][j-1]) % M;
            }
        }
    }

    for (int i=0;i<N;i++) {
        int a,b;
        cin >> a >> b;
        cout << arr[a][b] << "\n";
    }
}