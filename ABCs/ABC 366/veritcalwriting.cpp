#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main() {
    ll n, m=0; cin >> n;
    string arr[n];
    for (ll q = 0; q < n; q++) {
        cin >> arr[q];
        ll bruh = arr[q].length();
        m = max(m , bruh);
    }
    char sus[m][n];
    for (ll w = 0; w < n; w++) {
        string current = arr[n - w - 1];
        for (ll q = 0; q < current.length(); q++) {
            sus[q][w] = current[q];
        }
        for (ll q = current.length(); q < m; q++) {
            sus[q][w] = '*';
        }
    }
    for (ll q = 0; q < m; q++) {
        string gay = "";
        for (ll w = 0; w < n; w++) {
            gay += sus[q][w];
        }
        for (ll w = n-1; w >= 0; w--) {
            if (gay[w] == '*') gay[w] = ' ';
            else break;
        }
        cout << gay << "\n";
    }

}