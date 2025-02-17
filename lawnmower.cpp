#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    vector<int> minweed(n, m), maxweed(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'W') {
                minweed[i] = min(minweed[i], j);
                maxweed[i] = max(maxweed[i], j);
            }
        }
    }
    int limit = n - 1;
    while (limit >= 0 && minweed[limit] == m) limit--;
    int currpos = 0, ans = 0;
    for (int i = 0; i <= limit; i++) {
        int target = currpos;
        if (i % 2 == 0) { 
            target = max(currpos, maxweed[i]);
            if (i + 1 < n) target = max(target, maxweed[i + 1]);
        } else {
            target = min(currpos, minweed[i]);
            if (i + 1 < n) target = min(target, minweed[i + 1]);
        }
        ans += abs(target - currpos);  
        currpos = target; 
        if (i < limit) ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}
