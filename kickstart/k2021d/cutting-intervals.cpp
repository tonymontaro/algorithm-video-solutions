#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll, ll>


class Solution{
public:
    ll cuttingIntervals(ll n, ll c, vector<pi> &arr) {
        // count endpoints
        map<ll, ll> endpointsCounts;
        for (auto &x: arr) {
            endpointsCounts[x.first + 1]++;
            endpointsCounts[x.second]--;
        }

        // get a list of sorted endpoints
        vector<ll> endpoints;
        endpoints.reserve(endpointsCounts.size());
        for (auto &x: endpointsCounts)
            endpoints.emplace_back(x.first);
        ll left = endpoints[0];
        ll num = endpointsCounts[left];

        // get a list of cut segments: a pair of (number of lines affected, number of possible cuts)
        vector<pi> segments;
        for (int i = 1; i < endpoints.size(); i++) {
            ll endpoint = endpoints[i];
            segments.emplace_back(num, endpoint - left);
            left = endpoint;
            num += endpointsCounts[endpoint];
        }

        // greedily cut best segments until c is exhausted
        sort(segments.begin(), segments.end(), greater<>());
        ll ans = n;
        for (auto &x: segments) {
            ll diff = min(c, x.second);
            c -= diff;
            ans += diff * x.first;
            if (c == 0) break;
        }
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        ll n, c;
        cin >> n >> c;
        vector<pi> arr;
        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            arr.emplace_back(a, b);
        }

        ll ans = solver.cuttingIntervals(n, c, arr);
        cout << "Case #" << case_id << ": " << ans << endl;
    }
    return 0;
}