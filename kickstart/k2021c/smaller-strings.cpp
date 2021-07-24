#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll modpow(ll base, ll exp, ll modulus) {
    // compute (base^exp) % modulus using Binary Exponentiation.
    // Learn more here: https://cp-algorithms.com/algebra/binary-exp.html
    base %= modulus;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

class Solution {
public:
    ll mod = 1e9 + 7;
    ll smallerStrings(int n, int k, string &word) const {
        if (n == 1)
            return word[0] - 'a';
        ll ans = 0;

        // compute the result
        int half = (n + 1) / 2;
        for (int i = 0; i < half; i++) {
            ans = (ans + (word[i] - 'a') * modpow(k, half - i - 1, mod)) % mod;
        }

        // add one to ans if the first half of the word can form a palindrome
        int left = n % 2 == 0 ? half - 1 : half - 2;
        int right = half;
        while (left >= 0 && right < n) {
            if (word[left] != word[right]) {
                if (word[right] > word[left])
                    ans = (ans + 1) % mod;
                break;
            }
            left--;
            right++;
        }
        return ans;
    }
};


int main() {
    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        int n, k;
        string word;
        cin >> n >> k;
        cin >> word;

        ll result = solver.smallerStrings(n, k, word);

        cout << "Case #" << case_id << ": " << result << endl;
    }
    return 0;
}
