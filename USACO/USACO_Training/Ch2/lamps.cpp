/*
ID: polaric2
TASK: lamps
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
#include <cmath>
#include <stdlib.h>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


typedef pair<int,int> pi;

#define bit(x, i) (((x) & ((ull)1 << i)) >> i)
#define print(x, str, N) for (int i=0;i<N;i++) str[i] = (bit(x,(i%6)))+'0'; str[N] = '\0';



int main() {
    ofstream cout ("lamps.out");
    ifstream cin ("lamps.in");

    ull lamp = ~0;

    // all, odd, even, 3x
    ull ops[4] = {0b111111, 0b010101, 0b101010, 0b001001};

    int N,C;
    cin >> N >> C;
    
    ull ans = 0;
    vector<string> A;

    for (int i=1; i <= N; i++) {
        int a;
        cin >> a;
        if (a == -1)   break;
        else ans |= 1 << ((a-1)%6);
    }

    for (int i=1; i <= N; i++) {
        int a;
        cin >> a;
        if (a == -1)   break;
        else ans |= 1 << ((a-1)%6+6);
    }

    for (int i=1; i <= N; i++) {
        if (((ans >> (i-1)) &0b1000001) == 0b1000001) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }


    //cout << "ON:  "; print(ans & ops[0], N); cout << endl;
    //cout << "OFF: "; print((ans>>6) & ops[0], N); cout << endl;
    
    ull on = ans & ops[0];
    ull off = (ans>>6) & ops[0];
    int cnt = 0;

    for (int i=0;i<16;i++) {
        int k = ~0;
        int s = 0;
        for (int j=0;j<4;j++) {
            if (bit(i, j)) {
                k ^= ops[j]; s++;
            }
        }
        if (!(s <= C && (C-s)%2 == 0)) continue;

        if (!(on & ~k) && !(off & k)) {
            char c[N+1];
            print(k, c, N);
            string st(c);
            A.push_back(st);
            cnt++;
        }

    }

    sort(A.begin(), A.end());

    for (auto &t : A) {
        cout << t << endl;
    }

    if (!cnt) {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}