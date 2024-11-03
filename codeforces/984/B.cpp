#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long

void test() {
    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> arr(K);
    vector<int> cost(K);
    ll ans = 0;

    for (int i=0;i<K;i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    for (auto [b, c] : arr) {
        cost[b-1] += c;
    }
    
    sort(cost.begin(), cost.end());

    for (int i=K-1;i> max(K-1 - N, -1);i--)
        ans += (ll) cost[i];
    
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}