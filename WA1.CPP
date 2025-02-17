#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    unordered_map<ll, ll> counts;
    bool hp = false;
    for (ll i = 0; i < n; ++i) {
        ll a, b; cin >> a >> b;
        ll key = (static_cast<ll>(a) << 32) | b; 
        counts[key]++;
    }
    for (const auto& entry : counts) {
        if (entry.second > 1) {hp = true; break;}
    }
    cout << (hp ? "A" : "U");
    return 0;
}
