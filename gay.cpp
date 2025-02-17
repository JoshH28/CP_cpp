#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k, ans = LLONG_MIN; 
    cin >> n >> k;
    
    vector<vector<ll>> arr(n+1, vector<ll>(32, 0));
    vector<vector<ll>> dp(n+1, vector<ll>(32, LLONG_MIN));
    
    // Input and preprocessing
    for (ll q = 0; q < n; q++) {
        cin >> arr[q][0];
        for (ll w = 1; w <= 31; w++) {
            arr[q][w] = arr[q][w-1] / 2;
        }
    }
    
    // Initial state
    dp[0][0] = 0;
    
    // DP state transition
    for (ll q = 0; q < n; q++) {
        for (ll w = 0; w <= 30; w++) {
            if (dp[q][w] == LLONG_MIN) continue;
            
            // Buy good key
            dp[q+1][w] = max(dp[q+1][w], dp[q][w] - k + arr[q][w]);
            
            // Buy bad key
            dp[q+1][w+1] = max(dp[q+1][w+1], dp[q][w] + arr[q][w+1]);
        }
    }
    
    ans = LLONG_MIN;
    for (ll q = 0; q <= 30; q++) 
        ans = max(ans, dp[n][q]);
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}