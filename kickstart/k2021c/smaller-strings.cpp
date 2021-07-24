#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll modpow(ll base, ll exp, ll modulus) {
    base %= modulus;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll mod = 1e9 + 7;
    int cases;
    cin >> cases;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        int n, k;
        cin >> n >> k;
        string word;
        cin >> word;
        if (n == 1) {
            cout << "Case #" << case_id << ": " << (word[0] - 'a') << endl;
            continue;
        }

        int half = (n + 1) / 2;
        ll ans = 0;
        for (int i = 0; i < half; i++) {
            ans = (ans + (word[i] - 'a') * modpow(k, half - i - 1, mod)) % mod;
        }
        int left = n % 2 == 0 ? half - 1 : half - 2;
        int right = half;
        while (left >= 0 && right < n) {
            if (word[left] != word[right]) {
                if (word[right] > word[left]) ans++;
                break;
            }
            left--;
            right++;
        }
        cout << "Case #" << case_id << ": " << (ans % mod) << endl;
    }

    return 0;
}
