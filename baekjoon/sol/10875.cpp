#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define pa pair<long long, bool> 

long long L;
int N;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> L;
    cin >> N;

    vector<pa> ops;

    for (int i=0;i<N;i++) {
        long long x;
        char dir;
        cin >> x >> dir;
        ops.push_back({x, dir=='L'});
    }

    
}