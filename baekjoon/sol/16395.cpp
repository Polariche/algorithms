#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    ll arr[31][31];

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (j==1 || j==i) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
        }
    }

    cout << arr[N][K];
}