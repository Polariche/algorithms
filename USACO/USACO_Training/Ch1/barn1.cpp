/*
ID: polaric2
TASK: barn1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
    ofstream cout ("barn1.out");
    ifstream cin ("barn1.in");
    
    int m,s,c, ans=0;
    cin >> m >> s >> c;

    vector<int> stall(c);
    vector<int> empty;

    for (int i=0;i<c;i++) cin >> stall[i];

    sort(stall.begin(), stall.end());

    ans = c;
    m -= c;
    // count the necessary boards and the empty spaces
    for (int i=1;i<c;i++) {
        int b = stall[i-1], a = stall[i];
        if (a > b+1)   {   
            empty.push_back(a-b-1); 
        } else {
            m++;
        }
    }

    sort(empty.begin(), empty.end());

    for(;m<0;m++) ans += empty[-m-1];

    cout << ans << endl;

    return 0;
}