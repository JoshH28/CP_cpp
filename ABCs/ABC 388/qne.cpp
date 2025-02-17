#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int left = 0, right = N / 2, pairs = 0;
    while (left < N / 2 && right < N) {
        if (A[left] * 2 <= A[right]) {
            pairs++; left++; right++;
        } else {
            right++;
        }
    }
    cout << pairs;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
