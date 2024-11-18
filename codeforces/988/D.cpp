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
    ll L;
    cin >> N >> M >> L;

    vector<pair<ll,ll>> hurdles(N);
    int hpos = 0;
    ll jump = 1;
    int ans = 0;

    for (auto &[x, y] : hurdles) {
        cin >> x >> y;
        y = y - x + 2;
    }
    
    priority_queue<ll> powers;
    for (int i=0;i<M;i++) {
        ll x, y;
        cin >> x >> y;

        if (hpos >= N || ans == -1)
            continue;

        while (hpos < N && x >= hurdles[hpos].first) {
            while (jump < hurdles[hpos].second && !powers.empty()) {
                ll p = powers.top(); powers.pop();
                jump += p;
                ans++;
            }

            if (jump < hurdles[hpos].second) {
                ans = -1;
            }
            hpos++;
        }
        powers.push({y});
    }

    for (; hpos< N && ans != -1; hpos++) {
        while (jump < hurdles[hpos].second && !powers.empty()) {
            ll p = powers.top(); powers.pop();
            jump += p;
            ans++;
        }

        if (jump < hurdles[hpos].second) {
            ans = -1;
        }
    }
    if (hpos != N)
        ans = -1;
    cout << ans << "\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}