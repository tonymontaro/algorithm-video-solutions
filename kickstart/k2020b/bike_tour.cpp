#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int bikeTour(int n, vector<int> arr) {
        // O(n) time  | O(1) space
        int peaks = 0;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                peaks++;
        }
        return peaks;
    }
};

int main() {
    // makes printing the result faster
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // read the input
    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << "Case #" << case_id << ": " << solver.bikeTour(n, arr) << endl;
    }

    return 0;
}