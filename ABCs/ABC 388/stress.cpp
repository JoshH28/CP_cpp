#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N); // Stones each alien initially has
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> B = A; // Resultant stones after N years

    for (int i = 0; i < N; ++i) {
        int gifts = 0; // Count of gifts received by the i-th alien
        for (int j = 0; j < i; ++j) {
            if (B[j] > 0) {
                B[j]--; // Previous alien gives a stone
                gifts++;
            }
        }
        B[i] += gifts; // Update the stones for the i-th alien
    }

    for (int i = 0; i < N; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
