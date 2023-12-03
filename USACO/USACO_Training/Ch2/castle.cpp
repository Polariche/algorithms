/*
ID: polaric2
TASK: castle
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

#define f first
#define s second
typedef pair<int,int> pi;


int main() {
    ofstream cout ("castle.out");
    ifstream cin ("castle.in");

    int M,N;
    cin >> M >> N;

    int room[N+1][M+1] = {0};
    int v[N+1][M+1] = {0};

    map<int,int> cnts;

    int roomn = 0;      // output line 1
    int maxcnt = 0;     // output line 2
    int ifmax = 0;      // output line 3
    pi wallpos;         // output line 4-1, 4-2
    char walltype;      // output line 4-3

    vector<pi> q;

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            cin >> room[i][j];
        }
    }

    int it = 0;
    while (it < M*N) {
        pi c;
        int cnt=0;
        int roomcode;

        for (;it<M*N;it++) {
            int i = it/M+1, j = it%M+1;
            if (v[i][j]) continue;

            c = pi(i,j);
            q.push_back(c);
            break;
        }
        
        roomcode = c.f * M + c.s;

        if (q.empty()) break;

        while (!q.empty()) {
            pair<int,int> a = q.back();
            q.pop_back();
            int i = a.f, j = a.s;

            if (v[i][j])    continue;

            int r = room[i][j];
            v[i][j] = roomcode;

            if (!(r&1) && j>0)  q.push_back(pi(i,j-1)); 
            if (!(r&2) && i>0)  q.push_back(pi(i-1,j)); 
            if (!(r&4) && j<M)  q.push_back(pi(i,j+1));
            if (!(r&8) && i<N)  q.push_back(pi(i+1,j));
            
            cnt++;
        }

        cnts[roomcode] = cnt;
        roomn++;
        maxcnt = max(maxcnt, cnt);
    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            cin >> room[i][j];
        }
    }

    cout << roomn << endl;
    cout << maxcnt << endl;
    

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            int r = room[i][j];
            int k;

            #define ifs(x,y,w) k = cnts[v[i][j]] + cnts[v[x][y]]; \
                             if(v[i][j] != v[x][y] && (ifmax < k || (ifmax == k && (j < wallpos.s || (j == wallpos.s && i > wallpos.f))))) { \
                                ifmax = k;   \
                                wallpos = pi(i,j); \
                                walltype = w; \
                             }

            if ((r&1) && j>0)  { ifs(i,j-1,'W') }; 
            if ((r&2) && i>0)  { ifs(i-1,j,'N') }; 
            if ((r&4) && j<M)  { ifs(i,j+1,'E') };
            if ((r&8) && i<N)  { ifs(i+1,j,'S') };
        }
    }

    cout << ifmax << endl;
    cout << wallpos.f << " " << wallpos.s << " " << walltype << endl;

    return 0;
}