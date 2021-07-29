#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector


class Solution{
public:
    ll rabbitHouse(v<v<int>> &grid, int rlen, int clen, priority_queue<pair<int, pair<int, int>>> &pq){
        v<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        ll ans = 0;
        while (!pq.empty()) {
            auto node = pq.top();
            if (node.first == 0) break;
            pq.pop();
            int h = node.first, row = node.second.first, col = node.second.second;
            if (grid[row][col] == -1) continue;
            ans += h - grid[row][col];
            grid[row][col] = -1;
            for (auto [rAdd, cAdd]: directions) {
                int r = row + rAdd, c = col + cAdd;
                if (r < 0 || r >= rlen || c < 0 || c >= clen || grid[r][c] == -1) continue;
                if (h - 1 > grid[r][c])
                    pq.push({h - 1, {r, c}});
            }
        }
        return ans;
    }
};


int main() {
    // read input data
    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        int rlen, clen;
        cin >> rlen >> clen;
        v<v<int>> grid(rlen, v<int>(clen));
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                cin >> grid[r][c];
                pq.push({grid[r][c], {r, c}});
            }
        }

        ll ans = solver.rabbitHouse(grid, rlen, clen, pq);
        cout << "Case #" << case_id << ": " << ans << endl;
    }
    return 0;
}
