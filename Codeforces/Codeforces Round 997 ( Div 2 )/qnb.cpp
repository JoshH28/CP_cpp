#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve_test_case() {
    int n;
    cin >> n;
    vector<string> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> adj[i];
    }
    vector<int> result(n + 1); 
    for (int i = 0; i < n; i++) {
        int position = 1; 
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (adj[i][j] == '0' && j < i) {
                position++;
            }
            if (adj[i][j] == '1' && j > i) {
                position++;
            }
        }
        
        result[position] = i + 1;
    }
    for (int i = n; i >= 1; i--) {
        cout << result[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve_test_case();
    }
    
    return 0;
}