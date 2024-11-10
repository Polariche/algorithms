#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long


void test() {
    int N, M;
    ll V;
    cin >> N >> M >> V;
    vector<ll> vec(N+1);
    vector<ll> sum(N+1);
    int consumed = 0;
    ll ans = 0;

    ll fed[N+1] = {0};

    for (int i=1;i<=N;i++) {
        cin >> vec[i];
        sum[i] = sum[i-1] + vec[i];
    }
    
    auto begin = sum.begin();
    for (int i=1;i<=N;i++) {
        int idx = lower_bound(begin, begin + i, sum[i] - (V-vec[i])) - begin;
        fed[i] = fed[max(0,idx-1)] + 1;
        cout << idx<<","<<fed[i] << " ";
        
    }
    ans = max(ans, sum[N] - sum[consumed]);
    cout << ans << "\n\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}