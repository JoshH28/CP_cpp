#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m; 
    cin >> n >> m;
    
    vector<int> gourmet(n);
    for (int i = 0; i < n; i++) {
        cin >> gourmet[i];
    }
    
    // Sort gourmet levels
    sort(gourmet.begin(), gourmet.end());
    
    for (int j = 0; j < m; j++) {
        int sushi;
        cin >> sushi;
        
        // Binary search to find the first person who can eat
        auto it = lower_bound(gourmet.begin(), gourmet.end(), sushi);
        
        if (it == gourmet.end()) {
            // No one can eat this sushi
            cout << -1 << "\n";
        } else {
            // Print 1-based index of the person who eats the sushi
            cout << (it - gourmet.begin() + 1) << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc = 1;
    // Uncomment to handle multiple test cases
    // cin >> tc;
    
    while (tc--) solve();
    
    return 0;
}