#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int allocation(int budget, vector<int> &costs) {
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++) {
            if (budget < costs[i]) return i;
            budget -= costs[i];
        }
        return costs.size();
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        int n, budget;
        cin >> n >> budget;
        vector<int> costs(n);
        for (int i = 0; i < n; i++)
            cin >> costs[i];
        cout << "Case #" << case_id << ": " << solver.allocation(budget, costs) << endl;
    }
    return 0;
}