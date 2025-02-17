#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main() {
    ll qn, qt, num; cin >> qn;
    set<ll> s;
    unordered_map<ll, ll> mp;
    for (ll q = 0; q < qn; q++) {
        cin >> qt;
        if (qt == 1) {
            cin >> num;
            if (mp[num] == 0) {
                s.insert(num);
            }
            mp[num]++;
        } else if (qt == 2) {
            cin >> num;
            if (mp[num] == 1) {
                s.erase(num);
            }
            mp[num]--;
        } else {
            cout << s.size() << "\n";
        }
    }
}