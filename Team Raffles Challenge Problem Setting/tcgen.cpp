#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main() {
    vector<ll> arr;
    for (ll q = 1; q <= 15; q++) arr.push_back(q);
    random_shuffle(arr.begin(), arr.end());
    ll cnt = 1;
    for (auto it: arr) {
        cout << it << " " << cnt << "\n";
        cnt++;
    }
}