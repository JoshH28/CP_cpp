#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll>> adj;
vector<bool> visited;
map<ll, ll> sizes;
set<ll> deleted;

void dfs(ll u) {
    visited[u] = true;
    for (ll v : adj[u]) {
        if (!visited[v] && deleted.find(v) == deleted.end()) {
            dfs(v);
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    adj.clear();
    adj.resize(n + 1);
    visited.clear();
    visited.resize(n + 1, false);
    sizes.clear();
    deleted.clear();

    // Reading the graph
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        sizes[u]++;
        sizes[v]++;
    }

    // Find the node with the largest degree
    vector<ll> nodes;
    for (ll q = 1; q <= n; q++) nodes.push_back(q);

    // First deletion (largest degree)
    while (true) {
        // Sort the nodes by their degree in descending order
        sort(nodes.begin(), nodes.end(), [](ll a, ll b) { return sizes[a] > sizes[b]; });

        // Find all nodes with the current largest degree
        ll largestDegree = sizes[nodes[0]];
        vector<ll> toDelete;
        for (ll node : nodes) {
            if (sizes[node] == largestDegree) {
                toDelete.push_back(node);
            } else {
                break;
            }
        }

        // If we have found the largest degree node(s), delete them
        if (!toDelete.empty()) {
            for (ll node : toDelete) {
                for (ll neighbor : adj[node]) {
                    sizes[neighbor]--;
                }
                deleted.insert(node);
                sizes[node] = 0;
            }

            // Recompute the nodes list excluding deleted nodes
            nodes.clear();
            for (ll q = 1; q <= n; q++) {
                if (deleted.find(q) == deleted.end()) {
                    nodes.push_back(q);
                }
            }
            break;
        }
    }

    // Second deletion (second largest degree)
    while (true) {
        // Sort the nodes again by degree
        sort(nodes.begin(), nodes.end(), [](ll a, ll b) { return sizes[a] > sizes[b]; });

        // Find all nodes with the current largest degree
        ll largestDegree = sizes[nodes[0]];
        vector<ll> toDelete;
        for (ll node : nodes) {
            if (sizes[node] == largestDegree) {
                toDelete.push_back(node);
            } else {
                break;
            }
        }

        // If we have found the second largest degree node(s), delete them
        if (!toDelete.empty()) {
            for (ll node : toDelete) {
                for (ll neighbor : adj[node]) {
                    sizes[neighbor]--;
                }
                deleted.insert(node);
                sizes[node] = 0;
            }

            // Recompute the nodes list excluding deleted nodes
            nodes.clear();
            for (ll q = 1; q <= n; q++) {
                if (deleted.find(q) == deleted.end()) {
                    nodes.push_back(q);
                }
            }
            break;
        }
    }

    // Count the number of connected components in the remaining graph
    ll ans = 0;
    for (ll q = 1; q <= n; q++) {
        if (!visited[q] && deleted.find(q) == deleted.end()) {
            ans++;
            dfs(q);
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll q = 0; q < tc; q++) {
        solve();
    }
}
