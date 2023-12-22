/*
ID: polaric2
TASK: money
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <bitset>
#include <iterator>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> pi;

#define M 26
int coins[M];
ll dp[M][10001];

ll solve(int v, int n) {
    if(!v || !n) return dp[v][n]=!n;
    if (dp[v][n] > -1)  return dp[v][n];
    
    dp[v][n] = 0;

    for (int i=n/coins[v];i>=0;i--)
        dp[v][n] += solve(v-1, n-coins[v]*i);

    return dp[v][n];
}

int main() {
    ofstream cout ("money.out");
    ifstream cin ("money.in");

    int v,n;
    
    cin >> v >> n;
    for (int i=1;i<=v;i++) {
        cin >> coins[i];
        for (int j=1;j<=n;j++) {
            dp[i][j] = -1;
        }
    }
        
    sort(coins, coins+v);
    cout << solve(v,n) << endl;

    return 0;
}