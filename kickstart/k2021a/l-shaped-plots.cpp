#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define v vector


class Solution{
public:
    ll lShapedPlots(v<v<int>> &grid, int rlen, int clen) {
        // O(n * m) time and space solution.
        // compute the prefix-sum tables
        v<v<v<int>>> dp(rlen, v<v<int>>(clen));
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                dp[r][c] = {0, 0, 0, 0}; // up down left right
                dp[r][c][0] = (grid[r][c] == 1) ? 1 : 0;
                if (r > 0 && grid[r][c] == 1) dp[r][c][0] += dp[r-1][c][0];
                dp[r][c][2] = (grid[r][c] == 1) ? 1 : 0;
                if (c > 0 && grid[r][c] == 1) dp[r][c][2] += dp[r][c-1][2];
            }
        }
        for (int r = rlen - 1; r > -1; r--) {
            for (int c = clen - 1; c > -1; c--) {
                dp[r][c][1] = (grid[r][c] == 1) ? 1 : 0;
                if (r < rlen-1 && grid[r][c] == 1) dp[r][c][1] += dp[r+1][c][1];
                dp[r][c][3] = (grid[r][c] == 1) ? 1 : 0;
                if (c < clen-1 && grid[r][c] == 1) dp[r][c][3] += dp[r][c + 1][3];
            }
        }

        // compute the sum of valid L-Shapes
        ll ans = 0;
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                int up = dp[r][c][0];
                int down = dp[r][c][1];
                int left = dp[r][c][2];
                int right = dp[r][c][3];

                ans += max(0, min(up-1, (left/2)-1)) + max(0, min((up/2)-1, left-1));
                ans += max(0, min(up-1, (right/2)-1)) + max(0, min((up/2)-1, right-1));
                ans += max(0, min(down-1, (left/2)-1)) + max(0, min((down/2)-1, left-1));
                ans += max(0, min(down-1, (right/2)-1)) + max(0, min((down/2)-1, right-1));
            }
        }
        return ans;
    }
};


int main() {
    // read the input
    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        int rlen, clen;
        cin >> rlen >> clen;
        v<v<int>> grid(rlen, v<int>(clen));
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                cin >> grid[r][c];
            }
        }

        ll ans = solver.lShapedPlots(grid, rlen, clen);
        cout << "Case #" << case_id << ": " << ans << endl;
    }

    return 0;
}
