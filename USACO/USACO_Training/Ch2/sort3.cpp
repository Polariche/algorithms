/*
ID: polaric2
TASK: sort3
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

typedef pair<int,int> pi;
 
int cnt=0;
int N;

int main() {
    ofstream cout ("sort3.out");
    ifstream cin ("sort3.in");

    cin >> N;

    int a[N+1] = {0};
    int c[N+1] = {0};

    int size[4] = {0};
    map<pi, int> needs;
    
    // insert data & count occurences
    for (int i=1;i<=N;i++) {
        cin >> a[i];    
        size[a[i]]++;
    }

    for (int i=1;i<=3;i++) {
        for (int j=1;j<=3;j++)  needs[pi(i,j)] = 0;
    }

    // create the 'sorted' version
    int s=1;
    for (int i=1;i<=3;i++) {
        fill_n(c+s, size[i], i);
        s+=size[i];
    }
    
    // identify the pairs which need to be swapped
    for (int i=1;i<=N;i++) {
        needs[pi(a[i], c[i])]++;
    }

    int threeway = 0;
    for (int i=1;i<=3;i++) {
        for (int j=i+1;j<=3;j++)  {
            if (i!=j) {
                int x = needs[pi(i,j)], y = needs[pi(j,i)];
                int t = min(x,y);
                cnt += t;
                threeway += max(x,y) - t;
            }
        }
    }
    
    cout << cnt + threeway * 2 / 3 << endl;

    return 0;
}