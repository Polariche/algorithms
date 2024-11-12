#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long

int N;
ll L;

vector<ll> lefts(1);
vector<ll> rights(1);

ll dp[1001][1001][2];

ll solve(int x, int y, bool dir) {
    if (dp[x][y][dir] != -1)
        return dp[x][y][dir];
    
    ll ret;
    if (x && !dir)
        ret = min(solve(x-1, y, 0)+(lefts[x-1]-lefts[x])*(N+1-x-y), 
                solve(x-1, y, 1)+(rights[y]-lefts[x])*(N+1-x-y));
    if (y && dir)
        ret = min(solve(x, y-1, 0)+(rights[y]-lefts[y-1])*(N+1-x-y), 
                solve(x, y-1, 1)+(rights[y]-rights[y-1])*(N+1-x-y));

    return dp[x][y][dir]=ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    
    cin >> N >> L;

    
    for (int i=0;i<N;i++) {
        ll x;
        cin >> x;
        if (x < L)
            lefts.push_back(x);
        else if (x > L)
            rights.push_back(x);
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = 0;

    lefts[0]=rights[0]=(ll)L;

    sort(lefts.rbegin(), lefts.rend());
    sort(rights.begin(), rights.end());


    cout << min(solve(lefts.size()-1, rights.size()-1, 0), solve(lefts.size()-1, rights.size()-1, 1));
    return 0;
}