#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> parent, depth, diameterPath;

// Function to find the farthest node from a given node using DFS
pair<int, int> dfs(int node, int par) {
    parent[node] = par;
    int farthest_node = node;
    int max_depth = 0;

    for (int neighbor : adj[node]) {
        if (neighbor != par) {
            auto res = dfs(neighbor, node);
            if (res.second + 1 > max_depth) {
                max_depth = res.second + 1;
                farthest_node = res.first;
            }
        }
    }
    return {farthest_node, max_depth};
}

// Function to find the diameter of the tree
void find_diameter(int n) {
    parent.assign(n, -1);
    auto start = dfs(0, -1);
    auto end = dfs(start.first, -1);

    int node = end.first;
    diameterPath.clear();
    while (node != -1) {
        diameterPath.push_back(node);
        node = parent[node];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        adj.assign(n, vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        find_diameter(n);

        // Maximum connected components is achieved by removing two central nodes of the diameter path
        int m = diameterPath.size();
        int max_components = 0;

        if (m > 2) {
            int mid1 = diameterPath[m / 2];
            int mid2 = diameterPath[(m - 1) / 2];

            int count1 = 0, count2 = 0;
            for (int neighbor : adj[mid1]) {
                if (neighbor != parent[mid1]) count1++;
            }
            for (int neighbor : adj[mid2]) {
                if (neighbor != parent[mid2]) count2++;
            }
            max_components = max(count1, count2) + 1; // One extra for the other central node
        } else {
            max_components = n - 1; // Removing leaves or a small tree case
        }

        cout << max_components + 1 << "\n"; // +1 because we perform two removals
    }

    return 0;
}
