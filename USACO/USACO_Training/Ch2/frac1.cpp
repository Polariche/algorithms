/*
ID: polaric2
TASK: frac1
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

struct comp {
    constexpr bool operator()(const pi& p1,
                    const pi& p2) const
    {
        int a = p1.f * p2.s < p2.f * p1.s;
        return a == 0 ? p1.s < p2.s : a;
    }
};
 

int main() {
    ofstream cout ("frac1.out");
    ifstream cin ("frac1.in");

    int N;
    cin >> N;

    set<pi, comp> v;

    for(int i=1;i<=N;i++) {
        for (int j=0;j<=i;j++) {
            v.insert(pi(j, i));
        }
    }

    int j_ = -1, i_ = 1;
    for (auto& [j, i] : v) {
        if (j_ * i != i_ * j) {
            j_ = j;
            i_ = i;
            cout << j << "/" << i << endl;
        }
        
    }

    return 0;
}