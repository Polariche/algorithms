#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

void test() {
    int N, Q;
    cin >> N >> Q;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    
    vector<vector<int>> sum1(N+1, vector<int>(26, 0));
    vector<vector<int>> sum2(N+1, vector<int>(26, 0));

    for (int i=1;i<=N;i++) {
        int idx = s1[i-1]-'a';
        for (int j=0;j<26;j++) {
            sum1[i][j] = sum1[i-1][j] + (j == idx);
        }
    }
    for (int i=1;i<=N;i++) {
        int idx = s2[i-1]-'a';
        for (int j=0;j<26;j++) {
            sum2[i][j] = sum2[i-1][j] + (j == idx);
        }
    }

    while (Q--) {
        int ans = 0;
        int s, e;
        cin >> s >> e;

        vector<int> diffsum1(26);
        vector<int> diffsum2(26);

        for (int i=0;i<26;i++)
            diffsum1[i] = sum1[e][i] - sum1[s-1][i];

        for (int i=0;i<26;i++)
            diffsum2[i] = sum2[e][i] - sum2[s-1][i];

        for (int i=0;i<26;i++)
            ans += abs(diffsum1[i] - diffsum2[i]);
        cout << ans/2 << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}