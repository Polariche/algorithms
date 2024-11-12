#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Line {
public:
    double x1;
    double x2;
    double y;

public:
    Line() : x1(0), x2(0), y(0) {};
    Line(double x1, double x2, double y) : x1(x1), x2(x2), y(y) {};
    void input() {
        cin >> x1 >> x2 >> y;
    }
};

bool test() {
    Line house;
    Line land;
    int N;
    double ans = 0;
    
    house.input();

    if (!house.x1 && !house.x2 && !house.y)
        return 0;

    land.input();
    cin >> N;

    vector<Line> walls(N);
    vector<pair<double, double>> shadows;

    #define clamp(x) max(land.x1, min(land.x2, x))
    for (Line& wall : walls) {
        wall.input();

        if (!(house.y <= wall.y && wall.y <= land.y || house.y >= wall.y && wall.y >= land.y) )
            continue;
        
        double dy1 = abs(house.y - wall.y);
        double dy2 = abs(house.y - land.y);
        double dy = dy2 / dy1;

        double x1, x2;

        x1 = clamp(dy * (wall.x1 - house.x2) + house.x2);
        x2 = clamp(dy * (wall.x2 - house.x1) + house.x1);

        shadows.push_back({min(x1,x2), max(x1,x2)});
    }

    if (shadows.empty()) {
        cout << fixed << setprecision(2) <<  land.x2 - land.x1 << "\n";
        return 1;
    }

    sort(shadows.begin(), shadows.end());

    int s = 0;
    int e = 0;

    if (shadows[s].first > land.x1)
        ans = shadows[s].first -  land.x1;

    for (int i = 0; i < shadows.size(); i++) {
        if (shadows[i].first > shadows[e].second) {
            ans = max(ans, shadows[i].first - shadows[e].second);
            s = e = i;
        }
        
        if (shadows[i].second > shadows[e].second)
            e = i;
        
    }

    if (shadows[e].second <  land.x2)
        ans = max(ans, land.x2 - shadows[e].second);

    if (ans > 1e-6)
        cout << fixed << setprecision(2) << ans << "\n";
    else
        cout << "No View\n";

    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (test());
    return 0;
}