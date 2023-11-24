/*
ID: polaric2
TASK: beads
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

#define NEW_ARRAY(N) (int*)malloc(sizeof(int)*N);
#define COMP(a,b) ((bool) (a&b))
#define MAX(a,b) (a>b?a:b)

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int N;
    string str;
    int *bead;
    int *cnt[4];
    int best = 0, chain=0, last_chain=0;
    bool flag=true;

    fin >> N >> str;
    
    bead = NEW_ARRAY(N);

    for (int i=0;i<N;i++) {
        switch(str[i]) {
            case 'r': bead[i] = 1; break;
            case 'b': bead[i] = 2; break;
            case 'w': bead[i] = 3; break;
        }
    }

    for (int i=0;i<4;i++) {
        cnt[i] = NEW_ARRAY(N);
    }
    
    for (int k=0;k<2;k++) {
        for (int i=0;i<N;i++) {
            int j = (i-1+N)%N;
            int cur;
            int a = bead[i], b = bead[j];

            for (int k=1;k<=2;k++) {
                cnt[k][i] = COMP(a,k) + (COMP(a,b) ? cnt[k][j] : 0);
            }

            if (a == 3) cnt[3][i] = cnt[1][i] > cnt[2][i] ? 1 : 2;
            else    cnt[3][i] = a;

            if (cnt[3][i] != cnt[3][j] && a != b) {
                int t = cnt[3][j];
                flag = false;
                best = MAX(last_chain+cnt[t][j] - (b==3), best);

                cnt[t][i] = 0;

                cout << "chain cut: " << best << endl;

                last_chain = cnt[t][j];
            }

            cout << cnt[1][i] << " " << cnt[2][i] << " " << best << endl;
        }
        cout << "break" << endl;
    }

    if (flag) {
        best = N;
    }
    
    fout << best << endl;

    return 0;
}