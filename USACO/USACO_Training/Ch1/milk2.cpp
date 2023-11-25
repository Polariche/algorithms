/*
ID: polaric2
TASK: milk2
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000
#define MAX(a,b) (a>b?a:b)
int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    
    int cs, ce; // current start, current end
    int N;
    int best_idle=0, best_work=0; 

    fin >> N;

    // do NOT use map structure; there may be duplicate starts
    vector<pair<int,int>> stoe(N);

    for (int i=0;i<N;i++) {
        int s,e;
        fin >> stoe[i].first >> stoe[i].second;
    }

    sort(stoe.begin(), stoe.end());

    cs = stoe.begin()->first;
    ce = stoe.begin()->second;
    best_work = ce-cs;

    for(auto &[s,e] : stoe) {
        if (s > ce) {
            // break
            best_work = MAX(best_work, ce - cs);
            best_idle = MAX(best_idle, s - ce);

            cs = s;
            ce = e;
        } else if (e > ce) {
            // extend
            ce = e;
            best_work = MAX(best_work, ce - cs);
        }   // completely within; ignore
    }

    fout << best_work << " " << best_idle << endl;

    return 0;
}