#include <bits/stdc++.h>
using namespace std;

#define ll long long


class Solution{
public:
    ll alienGenerator(ll g) {
        // O(sqrt(g)) time | O(1) space
        ll ans = 0;
        for (int n = 1; n < g + 1; n++) {
            if (getMax(n) > g) break;
            if (hasValidStartingNumber(n, g)) ans++;
        }
        return ans;
    }
    ll getMax(ll n) {
        return (n * (1 + n)) / 2;
    }
    ll hasValidStartingNumber(ll n, ll g) {
        return (g * 2) % (n) == 0 && ((g * 2) / (n) - n + 1) % 2 == 0;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        ll g;
        cin >> g;

        ll ans = solver.alienGenerator(g);
        cout << "Case #" << case_id << ": " << ans << endl;
    }
    return 0;
}