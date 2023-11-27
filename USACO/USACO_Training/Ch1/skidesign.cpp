/*
ID: polaric2
TASK: skidesign
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
    ofstream cout ("skidesign.out");
    ifstream cin ("skidesign.in");
    
    int N;
    cin >> N;

    int t, x=101, y=-1;
    int hills[101]={0};

    ll a[3]={0}, b[3]={0};

    for (int i=0;i<N;i++) {
        cin >> t;
        hills[t]++;

        x = min(x, t);
        y = max(y, t);
    }

    #define f(c,z)  c[0] += hills[z]; c[1] += -2*hills[z]*z; c[2] += hills[z]*z*z;
    #define quad(c,z)  (c[0]*(z)*(z) + c[1]*(z) + c[2])     // plz put some paranthesis to prevent your macros from being messed up
    #define sol(x,y) (quad(a,x)+quad(b,y))

    f(a,x);
    f(b,y);

    while(y - x > 17) {
        if(sol(x+1,y) < sol(x,y-1)) {
            x++;
            f(a,x); // DON'T put x++ in your macros
        }
            
        else {
            y--;
            f(b,y);
        }

    }
    cout << sol(x,y) << endl;
    
    return 0;
}