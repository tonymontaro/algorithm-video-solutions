#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string increasingSubstring(int n, string word) {
        // O(n) time ans space
        vector<int> ans(n);
        int count = 1;
        string res = "1 ";
        for (int i = 1; i < n; i++) {
            if (word[i] > word[i - 1])
                count++;
            else count = 1;
            res += to_string(count);
            if (i != n - 1)
                res += " ";
        }
        return res;
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
        string word;
        cin >> n >> word;

        string result = solver.increasingSubstring(n, word);
        cout << "Case #" << case_id << ": " << result << endl;
    }

    return 0;
}