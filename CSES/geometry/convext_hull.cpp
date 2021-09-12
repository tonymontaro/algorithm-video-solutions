#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll, ll>


class ConvexHull {
public:
    int n;
    vector<pi> getConvexHullPoints(int totalPoints, vector<pi> &points) {
        n = totalPoints;
        sortPoints(points);
        auto lowerHullPoints = getPointsOnTheLowerHull(points);
        auto upperHullPoints = getPointsOnTheUpperHull(points);
        return getUniquePoints(lowerHullPoints, upperHullPoints);
    }
    void sortPoints(vector<pi> &points) {
        // sort points by x-axis, and by the y-axis when there's a tie.
        sort(points.begin(), points.end(), [](pi &a, pi &b){
            if (b.first < a.first) return false;
            if (b.first == a.first) return a.second > b.second;
            return true;
        });
    }
    vector<pi> getPointsOnTheLowerHull(vector<pi> &points) {
        vector<pi> stk;
        for (int i = 0; i < n; i++) {
            while (stk.size() > 1 && isClockWiseMovement(stk[stk.size()-2], stk.back(), points[i]))
                stk.pop_back();
            stk.push_back(points[i]);
        }
        return stk;
    }
    vector<pi> getPointsOnTheUpperHull(vector<pi> &points) {
        vector<pi> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() > 1 && isClockWiseMovement(stk[stk.size()-2], stk.back(), points[i]))
                stk.pop_back();
            stk.push_back(points[i]);
        }
        return stk;
    }
    bool isClockWiseMovement(pi &a, pi &b, pi &c) {
        return crossProduct(a, b, c) > 0;
    }
    ll crossProduct(pi &a, pi &b, pi &c) {
        return ((a.first - b.first) * (c.second - b.second)) - ((a.second - b.second) * (c.first - b.first));
    }
    vector<pi> getUniquePoints(vector<pi> &lowerHullPoints, vector<pi> &upperHullPoints) {
        set<pi> seen;
        vector<pi> answer;
        for (auto &p: lowerHullPoints) {
            if (seen.find(p) != seen.end()) continue;
            answer.push_back(p);
            seen.insert(p);
        }
        for (auto &p: upperHullPoints) {
            if (seen.find(p) != seen.end()) continue;
            answer.push_back(p);
            seen.insert(p);
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pi> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    ConvexHull convexHull;
    vector<pi > answer = convexHull.getConvexHullPoints(n, arr);
    cout << answer.size() << endl;
    for (auto &p: answer)
        cout << p.first << " " << p.second << endl;

    return 0;
}