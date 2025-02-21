#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    unordered_map<int, vector<pair<int, int>>> colorCells;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            colorCells[a[i][j]].push_back({i, j});
        }
    }
    
    int steps = 0;
    while (colorCells.size() > 1) {
        int bestColor = -1, maxGroupSize = 0;
        vector<pair<int, int>> bestGroup;
        
        for (auto &[color, cells] : colorCells) {
            unordered_set<int> used;
            vector<pair<int, int>> strangers;
            for (int i = 0; i < cells.size(); i++) {
                bool isStranger = true;
                for (int j : used) {
                    if (abs(cells[i].first - cells[j].first) + abs(cells[i].second - cells[j].second) <= 1) {
                        isStranger = false;
                        break;
                    }
                }
                if (isStranger) {
                    strangers.push_back(cells[i]);
                    used.insert(i);
                }
            }
            if (strangers.size() > maxGroupSize) {
                maxGroupSize = strangers.size();
                bestColor = color;
                bestGroup = strangers;
            }
        }
        
        int targetColor = -1;
        for (auto &[color, _] : colorCells) {
            if (color != bestColor) {
                targetColor = color;
                break;
            }
        }
        
        steps++;
        for (auto &[x, y] : bestGroup) {
            a[x][y] = targetColor;
            colorCells[targetColor].push_back({x, y});
        }
        
        colorCells[bestColor].erase(remove_if(colorCells[bestColor].begin(), colorCells[bestColor].end(),
            [&](pair<int, int> p) { return find(bestGroup.begin(), bestGroup.end(), p) != bestGroup.end(); }),
            colorCells[bestColor].end());
        
        if (colorCells[bestColor].empty()) {
            colorCells.erase(bestColor);
        }
    }
    cout << steps << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
