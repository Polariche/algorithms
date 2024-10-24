#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

void test() {
    ll ans = 0;
    ll N, X;
    cin >> N >> X;

    for (int a=1;a<=min(N,X);a++) {
        ll b;

        for (b=1;a+b+1 <= X && a*b+a+b<=N;b++) {
            ll c = min(X -a-b, (N-a*b)/(a+b));
            ans += c;
        }
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}