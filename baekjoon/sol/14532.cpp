#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;

    vector<int> upper_x(10, 11);
    vector<int> upper_y(10, 11);

    vector<int> lower_x(10, 0);
    vector<int> lower_y(10, 0);


    int arr[11][11]={0};
    set<int> canvas[11][11];

    bool exist[10] = {0};
    int adj[10][10] = {0};

    cin >> N;

    for (int x=1;x<=N;x++) {
        string s;
        cin >> s;
        for (int y=1;y<=N;y++) {
            int k = s[y-1] - '0';
            if (!k)
                continue;

            arr[x][y] = k;
            exist[k] = 1;

            upper_x[k] = min(upper_x[k], x);
            upper_y[k] = min(upper_y[k], y);
            lower_x[k] = max(lower_x[k], x);
            lower_y[k] = max(lower_y[k], y);
            
        }
    }

    for (int k=1;k<=9;k++) {
        if (!exist[k])
            continue;
        
        for (int x = upper_x[k]; x<=lower_x[k]; x++) {
            for (int y = upper_y[k]; y<=lower_y[k]; y++) {
                canvas[x][y].insert(k);
            }
        }
    }

    for (int x=1;x<=N;x++) {
        for (int y=1;y<=N;y++) {
            if (!arr[x][y])
                continue;

            int best = arr[x][y];

            for (int k : canvas[x][y]) {
                if (k!=best)
                    adj[best][k] = 1;
            }
        }
    }

    int firsts = 0;
    for (int x=1;x<=9;x++) {
        if (!exist[x])
            continue;

        int adjs = 0;
        for (int y=1;y<=9;y++) {
            if (adj[x][y])
                adjs++;
        }

        if (!adjs)
            firsts++;
        
    }
    cout << firsts;
}