#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<int> sorted_x = x;
    sort(sorted_x.begin(), sorted_x.end());
    vector<int> prefix_sum(n, 0);
    prefix_sum[0] = sorted_x[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + sorted_x[i];
    }
    vector<int> result(n, 0);
    for (int i = 0; i < n; i++) {
        int s = x[i];
        int idx = lower_bound(sorted_x.begin(), sorted_x.end(), s) - sorted_x.begin();
        int left_count = idx; 
        int left_sum = (idx > 0) ? prefix_sum[idx - 1] : 0;
        int right_count = n - idx - 1; 
        int right_sum = prefix_sum[n - 1] - prefix_sum[idx];
        int power = (s * left_count - left_sum) + (right_sum - s * right_count);
        result[i] = power;
    }
    for (int i = 0; i < n; i++) cout << result[i]+n << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Number of test cases
    while (t--) {
        solve();
    }

    return 0;
}
