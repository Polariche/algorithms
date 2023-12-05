/*
ID: polaric2
TASK: hamming
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
vector<int> h;

int dist(int x, int y, int B) {
    int s=0;
    int a = x^y;
    
    for (int i=0;i<B;i++)
        s += (a&(1<<i))>>i;

    return s;
}

bool hamming(int x, int B, int D) {
    for (int& y : h) {
        if (y >= x) break;
        else if (dist(x, y, B) < D) return false;
    }
    return true;
}


int main() {
    ofstream cout ("hamming.out");
    ifstream cin ("hamming.in");

    int N,B,D;
    cin >> N >> B >> D;

    int cnt = 0;
    int x = 0;
    while (cnt < N) {
        int a = hamming(x, B, D);
        if (a) {
            h.push_back(x);
            cnt++;

            cout << x;
            if (cnt % 10 == 0 || cnt == N) 
                cout << endl;
            else if (cnt < N)
                cout << " ";
        }
        
        x++;
    }

    
    return 0;
}