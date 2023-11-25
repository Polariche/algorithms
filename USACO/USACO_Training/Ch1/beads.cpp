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
#define SAME(a,b) ((bool) (a&b))
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int N;
    string str;
    int *bead;
    int *start[4];
    int *end[4];
    int best = 0, chain=0, last_chain=0;
    int flag = 0;
    fin >> N >> str;
    
    bead = NEW_ARRAY(N);

    for (int i=0;i<N;i++) {
        switch(str[i]) {
            case 'r': bead[i] = 1; flag |= 1; break;
            case 'b': bead[i] = 2; flag |= 2; break;
            case 'w': bead[i] = 3; break;
        }
    }

    if (flag < 3) { 
        // single-colored
        fout << N << endl;
        return 0;
    } 

    for (int i=1;i<3;i++) {
        start[i] = NEW_ARRAY(N);
        end[i] = NEW_ARRAY(N);
    }
    
    for (int k=0;k<2;k++) {
        for (int i=0;i<N;i++) {
            int j = (i-1+N)%N;
            int a = bead[i], b = bead[j];

            for (int c=1;c<=2;c++) {
                if (!SAME(a, c)) {
                    // chain broken
                    start[c][i] = end[c][i] = -1;
                    end[c][start[c][j]] = j;

                } else if (SAME(a, b) && start[c][j] > -1) {
                    // chain continued
                    start[c][i] = start[c][j];
                    end[c][i] = -1;

                } else {
                    // new chain
                    start[c][i] = i;
                    if (!end[c][i]) end[c][i] = i;
                }
            }
        }
    }

    for (int i=0;i<N;i++) {
        for (int c=1;c<=2;c++) {
            int d = (~c)&3;
            if (end[c][i] > -1) {
                // suppose we break the beads at end[c][i]
                int j = (end[c][i]+1)%N;
                int cnt = end[d][start[d][j]] - i + 1;
                if (cnt < 0) cnt += N;
                best = MAX(best, cnt);
            }
        }
    }

    fout << best << endl;

    
    return 0;
}