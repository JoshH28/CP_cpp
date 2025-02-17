#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n; cin >> n;
    vector<tuple<ll, ll, ll, ll>> beavers(n); 
    for (ll i = 0; i < n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        beavers[i] = {x, y, z, i};
    }
    array<tuple<ll, ll, ll, ll>, 3> topX = {{ {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1} }};
    array<tuple<ll, ll, ll, ll>, 3> topY = topX, topZ = topX;
    for (const auto& b : beavers) {
        ll x, y, z, idx;
        tie(x, y, z, idx) = b;
        if (x > get<0>(topX[0])) {
            topX[2] = topX[1];
            topX[1] = topX[0];
            topX[0] = b;
        } else if (x > get<0>(topX[1])) {
            topX[2] = topX[1];
            topX[1] = b;
        } else if (x > get<0>(topX[2])) topX[2] = b;
        if (y > get<1>(topY[0])) {
            topY[2] = topY[1];
            topY[1] = topY[0];
            topY[0] = b;
        } else if (y > get<1>(topY[1])) {
            topY[2] = topY[1];
            topY[1] = b;
        } else if (y > get<1>(topY[2])) topY[2] = b;
        if (z > get<2>(topZ[0])) {
            topZ[2] = topZ[1];
            topZ[1] = topZ[0];
            topZ[0] = b;
        } else if (z > get<2>(topZ[1])) {
            topZ[2] = topZ[1];
            topZ[1] = b;
        } else if (z > get<2>(topZ[2])) {
            topZ[2] = b;
        }
    }
    set<ll> indices;
    vector<tuple<ll, ll, ll, ll>> candidates;
    for (const auto& b : topX) candidates.push_back(b);
    for (const auto& b : topY) candidates.push_back(b);
    for (const auto& b : topZ) candidates.push_back(b);
    ll ans = -1;
    for (size_t i = 0; i < candidates.size(); i++) {
        for (size_t j = i + 1; j < candidates.size(); j++) {
            for (size_t k = j + 1; k < candidates.size(); k++) {
                ll idx1 = get<3>(candidates[i]);
                ll idx2 = get<3>(candidates[j]);
                ll idx3 = get<3>(candidates[k]);

                if (idx1 != idx2 && idx2 != idx3 && idx1 != idx3) {
                    ll sum = get<0>(candidates[i]) + get<1>(candidates[j]) + get<2>(candidates[k]);
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
