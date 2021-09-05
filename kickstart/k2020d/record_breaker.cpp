#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int recordBreaker(int n, vector<int> &arr) {
        int maxVisitors = -1;
        int recordBreakingDays = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxVisitors && (i == n - 1 || arr[i] > arr[i + 1]))
                recordBreakingDays++;
            maxVisitors = max(maxVisitors, arr[i]);
        }
        return recordBreakingDays;
    }
};

int main() {
    // makes printing the result faster
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        cout << "Case #" << case_id << ": " << solver.recordBreaker(n, arr) << endl;
    }

    return 0;
}