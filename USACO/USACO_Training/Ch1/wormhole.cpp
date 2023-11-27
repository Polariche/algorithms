/*
ID: polaric2
TASK: wormhole
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string.h>
using namespace std;

typedef long long ll;


int cycle(int N, int next[], int pair[]) {
    // n -> next -> pair -> next -> pair -> ... until we get to the first
    // since we only have a single edge for each node, we don't need crazy dfs stuff

    // the key is to make 2 copies of each node; one with next-> edge, and the other with pair-> edge

    int visit[2*N] = {0};
    set<int> nodes;

    for (int i=0;i<N;i++) {
        int cyclic[2*N] = {0};
        int s = 2*i;

        for (int j=0;j<2*N;j++) {
            if (cyclic[s])   return 1;
            else if (visit[s])     break;

            visit[s] = cyclic[s] = 1;

            if (s%2)  s = 2*pair[s/2];
            else  {
                if (next[s/2] > 0) s = 2*next[s/2]+1;
                else break;
            }
        }
    }

    return 0;
}

int solve(int N, int i, int next[], int pair[]) {
    int a = 0;

    if (i == N-1) {
        return cycle(N,next,pair);
    }

    if (pair[i] >= 0)
        return solve(N,i+1,next,pair);

    for (int j=i+1;j<N;j++) {
        // we need this pattern for counting combinations; extremely important!
        
        if (pair[j] >= 0)
            continue;

        pair[i] = j;
        pair[j] = i;

        a += solve(N,i,next,pair);

        pair[i] = -1;
        pair[j] = -1;
    }

    return a;
}

int main() {
    ofstream cout ("wormhole.out");
    ifstream cin ("wormhole.in");
    
    int N;
    cin >> N;
    int next[N], pair[N];
    map<ll, ll> hole;

    // we don't need the coords; 
    // we only need to know how many holes are on each horizontal line
    for (int i=0;i<N;i++) {
        ll x,y;
        cin >> x >> y;
        hole[y]++;

        next[i]=pair[i]=-1;
    }

    int cnt=0;
    for (auto & [y,xs] : hole) {
        for(int i=0;i<xs-1;i++) {
            next[cnt] = cnt+1;
            cnt++;
        }
        cnt++;
    }

    cout << solve(N,0,next,pair) << endl;
    
    return 0;
}