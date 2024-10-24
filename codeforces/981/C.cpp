#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define ll long long

void test() {
    ll N;
    cin >> N;
    vector<int> arr(N+1);
    vector<vector<int>> dp(N+1, vector<int>(2, 0));

    for (int i=1;i<=N;i++)
        cin >> arr[i];

    for (int i=2;i<=N/2;i++) {
        int a = arr[i];
        int b = arr[N-i+1];

        int c = arr[i-1];
        int d = arr[N-i+2];

        // don't swap
        dp[i][0] = min(dp[i-1][0] + (a==c) + (b==d), 
                        dp[i-1][1] + (a==d) + (b==c));

        // swap
        dp[i][1] = min(dp[i-1][0] + (b==c) + (a==d),
                        dp[i-1][1] + (b==d) + (a==c));

    }

    if (N%2 == 1) {
        dp[N/2+1][0] = dp[N/2+1][1] = min(dp[N/2][0], dp[N/2][1]) + (arr[N/2+1] == arr[N/2]) + (arr[N/2+1] == arr[N/2+2]);
        cout << dp[N/2+1][0] << "\n";
    } else {
        dp[N/2][0] += (arr[N/2] == arr[N/2+1]);
        dp[N/2][1] += (arr[N/2] == arr[N/2+1]);
        cout << min(dp[N/2][0], dp[N/2][1]) << "\n";
    }
    
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}