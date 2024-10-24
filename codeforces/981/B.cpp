#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

void test() {
    int N;
    cin >> N;
    ll sum = 0;
    vector<ll> diag(2*N);

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            ll a;
            cin >> a;
            diag[i-j+N-1] = max(-a, diag[i-j+N-1]);
        }
    }

    for (ll a : diag)
        sum += a;

    cout << sum << "\n";
    
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}