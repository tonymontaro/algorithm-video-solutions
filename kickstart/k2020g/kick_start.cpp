#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kick_start(string &word) {
        string kick = "KICK";
        string start = "START";
        int idx = 0;
        int ans = 0;
        int count = 0;
        while (idx < word.size()) {
            if (word[idx] == 'K' && isValid(idx, kick, word)) {
                count += 1;
                idx += kick.size() - 1;
            } else if (word[idx] == 'S' && isValid(idx, start, word)) {
                ans += count;
                idx += start.size();
            } else
                idx++;
        }
        return ans;
    }
    bool isValid(int idx, string &phrase, string &word) {
        if (idx + phrase.size() > word.size()) return false;
        return phrase == word.substr(idx, phrase.size());
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution solver;
    int cases;
    cin >> cases;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        string word;
        cin >> word;

        int result = solver.kick_start(word);
        cout << "Case #" << case_id << ": " << result << endl;
    }

    return 0;
}
