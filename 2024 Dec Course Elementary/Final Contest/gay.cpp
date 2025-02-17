#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back

void solve() {
    int n, l; cin >> n >> l;
    vi x(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> c[i];
    }
    vi dp(l + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= l; i++) {
        for(int j = 0; j < n; j++) {
            if(x[j] + c[j] >= i) {
                int need = max(0, i - (x[j] - c[j]));
                if(x[j] - c[j] <= i) {
                    dp[i] = min(dp[i], need);
                }
            }
        }
        if(i > 1) {
            dp[i] = min(dp[i], dp[i-1] + 1);
        }
    }
    if (dp[l] == l) cout << 0 << "\n";
    else cout << dp[l] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}