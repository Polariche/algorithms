#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h> 
#include <queue>


using namespace std;

#define mp make_pair

int N;
long long M;
int neg[310];
int pos[310];

int neg_n=0;
int pos_n=0;

int candy[310][310][2]={0};

// https://jason9319.tistory.com/343
int solve(int x, int y, int dir, int depth) {
    if (depth == 0) return 0;
    if (candy[x][y][dir] != -1) return candy[x][y][dir];

    int cur = dir? pos[y] : neg[x];
    int res = 1e9;

    if (x<neg_n)
        res = min(res, solve(x+1, y, 0, depth-1) + depth*(cur - neg[x+1]));
    if (y<pos_n)
        res = min(res, solve(x, y+1, 1, depth-1) + depth*(pos[y+1] - cur));
    
    return candy[x][y][dir] = res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long ans=0;
    cin >> N >> M;
    
    for (int i=0;i<N;i++) {
        int a;
        cin >> a;
        if (a<0) 
            neg[++neg_n] = a;
        else
            pos[++pos_n] = a;
    }
    
    sort(neg+1, neg+neg_n+1, greater<int>());
    sort(pos+1, pos+pos_n+1);

    for (int i=0;i<=N;i++) {
        memset(candy, -1, sizeof(candy));
        ans = max(ans, i*M - solve(0,0,0,i));
    }

    std::cout << ans;
}
