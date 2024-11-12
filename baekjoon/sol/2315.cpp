#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long
#define MAX 1000000007

int N;
int M;
int L, R;

ll center;

vector<pair<ll,ll>> lefts;
vector<pair<ll,ll>> rights;

vector<ll> left_cost;
vector<ll> right_cost;

ll dp[1001][1001][2];

ll solve(int x, int y, bool dir) {

    if (dp[x][y][dir] != -1)
        return dp[x][y][dir];
    
    ll res = dp[x][y][dir] = MAX;

    if (x && !dir) {
        ll cost = left_cost[L] - left_cost[x-1] + right_cost[R] - right_cost[y];
        ll v1 = solve(x-1, y, 0) + cost * (lefts[x-1].first - lefts[x].first);
        ll v2 = solve(x-1, y, 1) + cost * (rights[y].first - lefts[x].first);

        res = min(v1, v2);

    } else if (y && dir) {
        ll cost = left_cost[L] - left_cost[x] + right_cost[R] - right_cost[y-1];
        ll v1 = solve(x, y-1, 0) + cost * (rights[y].first - lefts[x].first);
        ll v2 = solve(x, y-1, 1) + cost * (rights[y].first - rights[y-1].first);

        res = min(v1, v2);
    }


    return dp[x][y][dir] = res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;

    for (int i=0;i<N;i++) {
        ll a,b;
        cin >> a >> b;

        if (i+1 < M) {
            lefts.push_back({a, b});
        } else if (i+1 > M) {
            rights.push_back({a, b});
        } else {
            center = a;
        }
    }
    lefts.push_back({center, 0});
    rights.push_back({center, 0});

    left_cost.push_back(0);
    right_cost.push_back(0);

    sort(lefts.rbegin(), lefts.rend());
    sort(rights.begin(), rights.end());

    L = lefts.size()-1;
    R = rights.size()-1;

    for (int i=1;i<=L;i++) 
        left_cost.push_back(lefts[i].second + left_cost[i-1]);

    for (int i=1;i<=R;i++) 
        right_cost.push_back(rights[i].second + right_cost[i-1]);
    
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = 0;

    cout << min(solve(L, R, 0), solve(L, R, 1));
}