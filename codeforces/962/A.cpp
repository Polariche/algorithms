#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

void test() {
    int a;
    cin >> a;
    cout << a/4 + (a%4)/2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) test();
}