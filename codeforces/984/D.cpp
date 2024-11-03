#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define ll long long

void test() {
    int N, M;
    cin >> N >> M;

    int arr[1001][1001];
    int layers = min(N, M)/2;
    int target_cnt;
    ll ans = 0;

    for (int i=0;i<N;i++) {
        string s;
        cin >> s;
        for (int j=0;j<M;j++) {
            arr[i][j] = s[j]-'0';
        }
    }

    #define CHECK   st.push_back(arr[i][j]);

    for (int k=0;k<layers;k++) {
        vector<int> st;
        int i,j;

        i = k;
        for (j = k; j < M-k-1; j++) {
            CHECK
        }

        j = M-k-1;
        for (i = k; i < N-k-1; i++) {
            CHECK
        }

        i = N-k-1;
        for (j = M-k-1; j >= k+1; j--) {
            CHECK
        }

        j = k;
        for (i = N-k-1; i >= k+1; i--) {
            CHECK
        }

        target_cnt = 0;
        for (int t=0;t<st.size()+3;t++) {
            if (t >= st.size() && !target_cnt)
                break;
                
            switch(target_cnt) {
                case 0: if (st[t%st.size()] == 1)  target_cnt++; break;
                case 1: if (st[t%st.size()] == 5)  target_cnt++; else if (st[t%st.size()] == 1) target_cnt=1; else target_cnt = 0; break;
                case 2: if (st[t%st.size()] == 4)  target_cnt++; else if (st[t%st.size()] == 1) target_cnt=1; else target_cnt = 0; break;
                case 3: if (st[t%st.size()] == 3)  {target_cnt = 0; ans++; } if (st[t%st.size()] == 1) target_cnt=1; else target_cnt = 0; break;
            }
        }
    }
    cout << ans << "\n";

    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}