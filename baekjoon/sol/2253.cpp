#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<bool> defects(N+1);
    int dp[10001][501];

    for (int i=0;i<M;i++) {
        int x;
        cin >> x;
        defects[x] = 1;
    }

    memset(dp, -1, sizeof(dp));
    dp[2][1] = 1;  

    for (int i=2;i<N;i++) {
        if (defects[i])
            continue;
        for (int j=1;j<=min(500,i);j++) {
            if (dp[i][j] == -1)
                continue;
            for (int k=max(1,j-1);k<=min(500,j+1) && i+k <= N;k++) {
                if (dp[i + k][k] == -1)
                    dp[i + k][k] = 0;
                dp[i + k][k] = dp[i][j] + 1;
            }
            
        }
    }

    int ans=N+1;
    for (int i=1;i<=500;i++) {
        if (dp[N][i] != -1)
            ans = min(ans, dp[N][i]);
    }

    if (ans == N+1)
        cout << -1;
    else 
        cout << ans;

}