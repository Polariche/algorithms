/*
ID: polaric2
TASK: holstein
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
using namespace std;

typedef long long ll;

#define f first
#define s second

#define MAX 16

typedef pair<int,int> pi;

int V, G;
int *v, *feeds;

int cur_best = MAX;
int ansx = 0;
int cnt=0;

int solve(int x, int n) {
    if (n > G || cnt >= cur_best)    return cur_best;
    int i, s, s1, s2;

    // see if we have all the vitamins
    for (i=0;i<V && v[i] <= 0;i++);
    if (i==V) {
        ansx = x;
        return cur_best = cnt;
    }

    // next iteration
    cnt++;
    for (i=0;i<V;i++) v[i] -= feeds[n*V + i];
    
    s1 = solve(x | (1<<n), n+1);

    for (i=0;i<V;i++) v[i] += feeds[n*V + i];
    cnt--;

    s2 = solve(x, n+1);

    s = min(s1,s2);

    return s;
}

int main() {
    ofstream cout ("holstein.out");
    ifstream cin ("holstein.in");

    
    cin >> V;

    v = new int[V];
    

    for (int i=0;i<V;i++) {
        cin >> v[i];
    }
    cin >> G;

    feeds = new int[G*V];

    for (int i=0;i<G;i++) {
        for(int j=0;j<V;j++) {
            cin >> feeds[i*V + j];
        }
    }

    cout << solve(0, 0);
    for (int i=0;i<G;i++) {
        if (ansx & (1<<i)) cout << " " << i+1;
    }
    cout << endl;
    return 0;
}