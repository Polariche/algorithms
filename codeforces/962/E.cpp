#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define M 1000000007

void test() {
    ll ans = 0;

    string s;
    cin >> s;
    vector<int> sum(s.size()+1);
    map<int, vector<int>> mp;

    for (int i=0;i<=s.size();i++) {
        if (i>=1)
            sum[i] = sum[i-1] + int(s[i-1]-'0')*2-1;
        
        if (mp.find(sum[i]) == mp.end())
            mp[sum[i]] = vector<int>();
        mp[sum[i]].push_back(i);
    }

    for (auto &[k,v] : mp) {
        ll cnt = 0;
        for (int i=0;i<v.size();i++) {
            ans += (cnt * ((ll) s.size() - v[i]+1)) % M;
            cnt += v[i]+1;
            cnt = cnt%M;
            ans = ans%M;
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}