#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long

void test() {
    string s;
    int N, slen;
    cin >> s;
    cin >> N;
    vector<pair<int,int>> arr(N);
    

    for (int i=0;i<N;i++)
        cin >> arr[i].first >> arr[i].second;
    
    slen = s.size();

    if (slen<4) {
        for (int i=0;i<N;i++)
            cout << "NO\n";
        return;
    }

    vector<bool> exist(slen-3);
    int exist_sum = 0;
    for (int i=0;i<slen-3;i++) {
        if (s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0')
            exist[i] = 1;
        else
            exist[i] = 0;
        exist_sum += exist[i];
    }

    for (auto [idx, val] : arr) {
        idx -= 1;
        s[idx] = val + '0';
        for (int i=max(0,idx-3);i<=min(idx,slen-4);i++) {
            exist_sum -= exist[i];
            if (s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0')
                exist[i] = 1;
            else
                exist[i] = 0;
            exist_sum += exist[i];
        }
        cout << (exist_sum ? "YES\n" : "NO\n");
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}