#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main() {
    ll n, a, t; cin >> n >> a >> t;
    if (abs(a-t) >= abs(n - a - t)) {
        cout << "Yes";
    } else cout << "No";
}