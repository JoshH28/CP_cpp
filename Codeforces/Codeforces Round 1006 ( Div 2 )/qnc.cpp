#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[i][j] represents the number of subsequences ending at index i with last element j
    vector<vector<long long>> dp(n, vector<long long>(4, 0));
    vector<long long> cnt(4, 0); // cnt[j] represents the total number of subsequences ending with j

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int j = 1; j <= 3; ++j) {
            if (x > j) {
                dp[i][x] = (dp[i][x] + cnt[j]) % MOD;
            }
        }
        cnt[x] = (cnt[x] + 1) % MOD;
    }

    long long total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (dp[i][j] >= 1) {
                total = (total + dp[i][j]) % MOD;
            }
        }
    }

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}