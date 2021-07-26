#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int kGoodnessString(int n, int k, string &word) {
        // O(n) time | O(1) space
        int goodness = 0;
        for (int i = 0; i < n / 2; i++) {
            if (word[i] != word[n - i - 1])
                goodness++;
        }
        return abs(k - goodness);
    }
};

int main() {

    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int ans = solver.kGoodnessString(n, k, s);
        cout << "Case #" << case_id << ": " << ans << endl;
    }

    return 0;
}