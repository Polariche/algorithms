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

    int bi[M*M*4+2]={0};
    set<int> biset;

    for (int p=0;p<=M;p++) {
        for (int q=0;q<=M;q++) {
            bi[p*p+q*q]=1;
            biset.insert(p*p+q*q);
        }
    }

    // O(M^4) lmao
    int total=0;
    for(int b=1;b<=M*M;b++) {
        set<int>::iterator it;

        for (it = biset.begin(); it != biset.end();it++) {
            int i;
            int a = *it;
            for (i=0; (i<N && bi[a+i*b]); i++);
            
            if (i==N) {
                cout << a << " " << b << endl;
                total++;
                if (total>10000)    return 0;
            }
        }
    }

    if (total == 0)
        cout << "NONE" << endl;

    return 0;
}