#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long
#define M 998244353



ll gcd(ll x, ll y) {
    if (y==0)   return x;
    return gcd(y, x%y);
}

void test() {
    int N;
    cin >> N;
    vector<ll> arr(N);
    vector<ll> dp(N);
    dp[0] = 1;
    
    for (int i=0;i<N;i++) {
        cin >> arr[i];
        for (int j=i-1;j>=0;j--) {
            ll mx = max(arr[i], arr[j]);
            ll mn = min(arr[i], arr[j]);

            if (gcd(mx, mn) != 1)
                dp[i] = (dp[i] + dp[j]) % M; 
        }
    }
    cout << dp[N-1];

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    test();
}