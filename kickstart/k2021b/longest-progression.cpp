#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll, ll>
#define ll long long


class Solution{
public:
    ll longestProgression(int n, vector<ll> &arr) {
        if (n <= 2) return n;
        auto forward = prefix(n, arr);
        reverse(arr.begin(), arr.end());
        auto backward = prefix(n, arr);
        reverse(arr.begin(), arr.end());
        reverse(backward.begin(), backward.end());
        ll ans = 2;
        for (int i = 0; i < n; i++) {
            if (i < n - 1) ans = max(ans, 1 + backward[i + 1].first);
            if (i > 0) ans = max(ans, 1 + forward[i - 1].first);

            if (i == 0 || i == n - 1) continue;
            if ((arr[i - 1] + arr[i + 1]) % 2 == 0) ans = 3 > ans ? 3 : ans;
            else continue;
            ll mid = (arr[i - 1] + arr[i + 1]) / 2;
            ll diff = mid - arr[i - 1];
            if (diff == -backward[i + 1].second) {
                ans = max(ans, 2 + backward[i + 1].first);
            }
            if ( (arr[i + 1] - mid) == forward[i - 1].second) {
                ans = max(ans, 2 + forward[i - 1].first);
            }
            if (i == 1 || i == n - 2) continue;
            if (diff == forward[i - 1].second && diff == -backward[i + 1].second)
                ans = max(ans, forward[i - 1].first + 1 + backward[i + 1].first);
        }

        return ans;
    }
    vector<pi> prefix(int n, vector<ll> &arr) {
        vector<pi> res(n);
        ll prevDiff = 1e10;
        ll ans = 0;
        ll count = 0;
        for (int i = 1; i < n; i++) {
            ll diff = arr[i] - arr[i - 1];
            if (diff == prevDiff) {
                count++;
            } else {
                count = 2;
                prevDiff = diff;
            }
            res[i] = {count, diff};
            ans = max(ans, count);
        }
        return res;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        int n;
        cin >> n;
        vector<ll> arr; arr.reserve(n);
        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            arr.push_back(a);
        }

        ll ans = solver.longestProgression(n, arr);
        cout << "Case #" << case_id << ": " << ans << endl;
    }
    return 0;
}