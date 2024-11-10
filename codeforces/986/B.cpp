#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long

void test() {
    ll N, b, c;
    ll M;
    cin >> N >> b >> c;

    if (N==1) {
        cout << (c==0?0:1) << "\n";
        return;
    }

    if (!b && !c) {
        cout << -1 << "\n";
        return;
    }

    if (!b) {
        cout << N-(c<N?1:0) << "\n";
        return;
    }

    // find i such that (i<=N)
    // ((i-1)*b + c) - N >= 0
    M = N - (N%b) + (c % b);
    M = (M - c) / b;
    
    cout << N - max((ll) 0, M) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}