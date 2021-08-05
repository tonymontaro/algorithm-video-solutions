#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

class Solution{
public:
    ll consecutivePrimes(ll n) {
        if (n < 10) return 6;
        ll num = sqrt(n) + 1;

        vector<ll> ps;
        while (ps.empty()) {
            if (isPrime(num)) ps.push_back(num);
            num++;
        }
        num = sqrt(n);
        while (ps.size() < 3) {
            if (isPrime(num)) ps.push_back(num);
            num--;
        }

        sort(ps.begin(), ps.end());
        ll a = ps[2] * ps[1];
        ll b = ps[0] * ps[1];
        return a <= n ? a : b;
    }

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    Solution solver;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        ll n;
        cin >> n;

        ll ans = solver.consecutivePrimes(n);
        cout << "Case #" << case_id << ": " << ans << endl;
    }
    return 0;
}
