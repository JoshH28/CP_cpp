#include <bits/stdc++.h>
using namespace std;

struct Block {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, W;
    cin >> N >> W;
    
    vector<Block> blocks(N);
    map<int, vector<int>> column_blocks;
    
    for (int i = 0; i < N; i++) {
        cin >> blocks[i].x >> blocks[i].y;
        column_blocks[blocks[i].x].push_back(blocks[i].y);
    }
    
    for (auto &[col, ys] : column_blocks) {
        sort(ys.begin(), ys.end(), greater<int>());
    }
    
    vector<int> min_y(W + 1, INT_MAX);
    for (auto &[col, ys] : column_blocks) {
        min_y[col] = ys.back();
    }
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        int T, A;
        cin >> T >> A;
        A--;
        int x = blocks[A].x, y = blocks[A].y;
        if (y - T > 0 && y - T >= min_y[x]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}
