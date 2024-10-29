#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define ll long long

void test() {
    int N;
    string s;

    cin >> N;
    cin >> s;

    vector<bool> bought(N+1);
    vector<int> zeroj(N+1);

    ll ans = 0;

    int j;
    int max_zero = 0;
    bool out_of_zero = 0;

    for (int i=1;i<=N;i++) {
        bool bit = s[i-1] == '1';
        if (!bit)
            max_zero = i;
        else
            zeroj[i] = max_zero;
    }

    j = zeroj[N];
    for (int i=N;i>=1;i--) {
        bool ibit = s[i-1] == '1';
        if (!ibit || bought[i])
            continue;

        if (!out_of_zero) {
            if (j>i)
                j = zeroj[i];

            while ((bought[j] || s[j-1] == '1') && j>0) {
                bool jbit = s[j-1] == '1';
                if (jbit)
                    j = zeroj[j];
                else
                    j--;
            }

            if (!j) {
                out_of_zero = 1;
                j = 1;
            }
        }

        if (out_of_zero) {
            while (bought[j])
                j++;
        }
            

        if (i > j && !bought[j])
            ans += (ll) i;

        bought[i] = bought[j] = 1;
        
    }
    
    cout << (ll) N*(N+1)/2 - ans << "\n";
    return;
}

int main () {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) test();
}