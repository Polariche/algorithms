/*
ID: polaric2
TASK: combo
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main() {
    ofstream cout ("combo.out");
    ifstream cin ("combo.in");
    
    int N;
    int a[3], b[3];
    int lock1, lock2;

    cin >> N;

    // if N < 5, then the lock is useless!!!
    if (N < 5) cout << N*N*N << endl;
    else {
        int k = 1;
        cin >> a[0] >> a[1] >> a[2];
        cin >> b[0] >> b[1] >> b[2];

        // given N >= 5, each combination gives us 5^3 = 125 solutions
        // so we have 250 solutions at max
        // we just need to find some overlaps...

        for (int i=0;i<3;i++) {
            int x,y;

            x = min(a[i], b[i]);
            y = max(a[i], b[i]);
            
            k *= max(0,(x+2) - (y-2)+1) + max(0, (y+2) - (x-2 +N) +1);
        }
        cout << 250-k << endl;
    }

    return 0;
}