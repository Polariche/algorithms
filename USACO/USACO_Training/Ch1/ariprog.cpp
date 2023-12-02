/*
ID: polaric2
TASK: ariprog
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


int main() {
    ofstream cout ("ariprog.out");
    ifstream cin ("ariprog.in");

    int N,M;
    cin >> N >> M;

    int bi[M*M*2+1]={0};
    map<int, vector<int>> ans;

    for (int p=0;p<=M;p++) {
        for (int q=0;q<=M;q++) {
            bi[p*p+q*q]=1;
        }
    }

    int total=0;
    for (int a=0;a<=2*M*M;a++) {
        if (!bi[a]) continue;
        for (int b=1;b<=(2*M*M-a)/(N-1);b++) {
            int i;
            for (i=0; (i<N && bi[a+i*b]); i++);
            
            if (i==N) {
                ans[b].push_back(a);
                if (++total>10000)    return 0;
            }
        }
    }

    if (total == 0)
        cout << "NONE" << endl;
    else {
        for (auto & [b, as] : ans) {
            for (int& a : as)
                cout << a << " " << b << endl;
        }
    }

    return 0;
}