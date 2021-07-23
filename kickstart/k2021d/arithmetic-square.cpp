#include <bits/stdc++.h>
using namespace std;


int main() {
    int cases;
    cin >> cases;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        // read input
        int a1, a2, a3, b1, b3, c1, c2, c3;
        cin >> a1 >> a2 >> a3 >> b1 >> b3 >> c1 >> c2 >> c3;

        // add already valid rows/columns
        int ans = 0;
        if (a1 - a2 == a2 - a3) ans++;
        if (c1 - c2 == c2 - c3) ans++;
        if (a1 - b1 == b1 - c1) ans++;
        if (a3 - b3 == b3 - c3) ans++;

        // set appropriate mid value for the middle row, column and diagonals
        map<int, int> validMid;
        if ((a2 + c2) % 2 == 0) validMid[(a2 + c2) / 2]++;
        if ((b1 + b3) % 2 == 0) validMid[(b1 + b3) / 2]++;
        if ((a1 + c3) % 2 == 0) validMid[(a1 + c3) / 2]++;
        if ((a3 + c1) % 2 == 0) validMid[(a3 + c1) / 2]++;

        // include the mid value with the highest valid result
        int more = 0;
        for (auto& x: validMid)
            more = max(more, x.second);

        int finalAns = ans + more;
        cout << "Case #" << case_id << ": " << finalAns << endl;
    }

    return 0;
}
