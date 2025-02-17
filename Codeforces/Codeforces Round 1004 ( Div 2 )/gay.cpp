#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    if (to_string(n).find('7') != string::npos) {
        cout << 0 << "\n";
        return;
    }
    int min_ops = INT_MAX;
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++) {
        int digit = s[i] - '0';
        if (digit == 7) {
            cout << 0 << "\n";
            return;
        }
        int ops = 0;
        int temp = digit;
        while (temp != 7) {
            temp = (temp + 9) % 10;
            ops++;
        }
        min_ops = min(min_ops, ops);
    }
    cout << min_ops << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
