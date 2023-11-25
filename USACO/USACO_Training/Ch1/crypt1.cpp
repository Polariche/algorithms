/*
ID: polaric2
TASK: crypt1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int valid(int numbit, int a) {
    int bit = 0;

    while (a) {
        bit |= 1 << (a%10);
        a/=10;
    }

    return !(bit & ~(numbit));
}

void get_three (vector<int> num, int numbit, map<int, vector<int>> * three) {
    // O(N^4) ? we're in for a bad time...
    // thankfully, 1<=N<=9 so our max is 6561
    for(int& a : num) {
        for(int &b : num) {
            for (int &c : num) {
                int x = a*100+b*10+c;

                for (int &d : num) {    // ewwwwww
                    int res = x*d;

                    if (valid(numbit, res) && res < 1000)
                        (*three)[x].push_back(res);

                }
            }
        }
    }
    return;
}

int main() {
    ofstream cout ("crypt1.out");
    ifstream cin ("crypt1.in");
    
    int N;
    cin >> N;
    vector<int> num(N);
    map<int, vector<int>> three;
    int numbit = 0, cnt=0;

    for (int i=0;i<N;i++)   cin >> num[i];

    sort(num.begin(), num.end());

    for (int & n : num)
        numbit |= 1 << n;

    get_three(num, numbit, &three);

    for (auto &[a,v]: three) {
        for (int &i : v) {
            for (int &j : v) {
                if (valid(numbit, i*10+j))  cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}