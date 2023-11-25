/*
ID: polaric2
TASK: milk
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
    ofstream cout ("milk.out");
    ifstream cin ("milk.in");
    
    int n,m,a=0;
    cin >> n >> m;

    vector<pair<int,int>> milk(m);

    for(int i=0;i<m;i++) {
        cin >> milk[i].first >> milk[i].second;
    }

    sort(milk.begin(), milk.end());

    for(auto [p,n_] : milk) {
        n_ = min(n_, n);
        n -= n_;
        a += n_ * p;

        if (!n) break;
    }

    cout << a << endl;

    return 0;
}