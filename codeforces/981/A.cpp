#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

void test() {
    int N;
    cin >> N;
    int i = 1;
    int pos = 0;
    int sign = -1;
    while (abs(pos) <= N) {
        pos += sign*(2*i-1);
        sign *= -1;
        i++;
    }
    cout << (pos > 0 ? "Kosuke" : "Sakurako") << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}