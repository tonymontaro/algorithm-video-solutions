#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll retype(ll levels, ll level, ll swordLevel) {
        ll spentTime = level;
        ll startOver = spentTime + levels;
        ll goBack = spentTime + (level - swordLevel) + (levels - swordLevel);
        return min(startOver, goBack);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        int a, b, c;
        cin >> a >> b >> c;

        auto ans = solver.retype(a, b, c);
        cout << "Case #" << case_id << ": " << ans << endl;
    }

    return 0;
}