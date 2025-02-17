#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 2e5 + 5;

vector<int> g[N];
vector<int> comp[N];
int deg[N], subtree[N];

// Returns subtree size and fills subtree array
int dfs(int v, int p) {
    subtree[v] = 1;
    for(int u : g[v]) {
        if(u != p) {
            subtree[v] += dfs(u, v);
        }
    }
    return subtree[v];
}

void solve() {
    int n;
    cin >> n;
    
    // Clear previous testcase
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        deg[i] = 0;
    }
    
    // Read edges
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    
    // Get tree info
    dfs(1, 0);
    
    int ans = 0;
    
    // For each first vertex to remove
    for(int i = 1; i <= n; i++) {
        // First vertex creates deg[i] components
        vector<int> sizes;  // sizes of components after first cut
        
        // Calculate sizes of components after removing i
        for(int u : g[i]) {
            int sz = subtree[u];
            if(u > i) {
                sz = n - subtree[u];
            }
            if(sz > 1) sizes.pb(sz);
        }
        
        // If there are no components of size > 1, just add degree of second vertex - 1
        if(sizes.empty()) {
            for(int j = i+1; j <= n; j++) {
                ans = max(ans, deg[i] + deg[j] - 1);
            }
            continue;
        }
        
        // Sort by size descending
        sort(sizes.rbegin(), sizes.rend());
        
        // For each component after first cut, we can get at best (degree-1) new components
        int max_new = 0;
        for(int sz : sizes) {
            max_new = max(max_new, sz - 1);
        }
        
        ans = max(ans, deg[i] + max_new);
    }
    
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) solve();
    
    return 0;
}