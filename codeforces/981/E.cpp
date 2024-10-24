#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
using namespace std;

#define ll long long


void test() {
    int N;
    cin >> N;

    int swaps = 0;
    vector<int> p(N+1);
    vector<bool> visit(N+1);
    deque<int> dq;
    vector<int> waiting;
    
    for (int i=1;i<=N;i++) {
        cin >> p[i];
    }

    for (int i=N;i>=1;i--)
        waiting.push_back(i);

    while (!waiting.empty()) {
        bool started = 0;
        int x = waiting.back(); waiting.pop_back();
        int y = x;

        if (visit[x])
            continue;

        if (dq.empty()) {
            while (!started || y != x) {
                started = 1;
                y = p[y];
                dq.push_back(y);
            }
            if (!dq.empty())
                dq.pop_back();
        }
        
        
        int z = dq[0];
        if (dq.size() <= 2 && ((p[x] == x && p[z] == p[z]) || (p[z] == x && p[x] == z))) {
            visit[x] = visit[z] = 1;
            dq.clear();
        } else {
            visit[x] = visit[z] = 1;
            
            // swap
            int tmp = p[dq[0]];
            p[dq[0]] = p[dq[dq.size()-1]];
            p[dq[dq.size()-1]] = tmp;
            swaps++;
            
            dq.pop_front();

            waiting.push_back(dq[0]);
            dq.pop_front();
        }
    }
    cout << swaps << "\n";

    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}