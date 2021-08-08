#include <bits/stdc++.h>
using namespace std;

#define ll long long


class Solution {
public:
    vector<ll> finalExam(map<ll, ll> &testSets, vector<ll> &difficulties) {
        vector<ll> result;
        result.reserve(difficulties.size());

        for (ll diff: difficulties) {
            auto iter = testSets.lower_bound(diff);
            auto previous = iter == testSets.begin() ? iter : prev(iter);
            bool usePrevious = iter == testSets.end()
                    || (previous->first <= diff && diff <= previous->second)
                    || diff - previous->second <= abs(iter->first - diff);
            if (usePrevious)
                iter = previous;

            ll start = iter->first;
            ll end = iter->second;
            testSets.erase(iter);
            if (start == end) {
                result.push_back(start);
            }
            else if (diff <= start) {
                result.push_back(start);
                testSets[start + 1] = end;
            } else if (diff >= end) {
                result.push_back(end);
                testSets[start] = end - 1;
            } else {
                result.push_back(diff);
                testSets[start] = diff - 1;
                testSets[diff+1] = end;
            }
        }

        return result;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        int n, m;
        cin >> n >> m;
        map<ll, ll> testSets;
        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            testSets[a] = b;
        }
        vector<ll> difficulties(m);
        for (int i = 0; i < m; i++) {
            cin >> difficulties[i];
        }

        // format and print the result.
        auto resArr = solver.finalExam(testSets, difficulties);
        string res = to_string(resArr[0]);
        for (int i = 1; i < m; i++) res += " " + to_string(resArr[i]);
        cout << "Case #" << case_id << ": " << res << endl;
    }
}
