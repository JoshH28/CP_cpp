#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
#define gcd(x,y) __gcd( x, y)
#define ALL(x) x.begin(),x.end()
#define pll pair<long long,long long>
#define debug(x) cerr<<#x<<':'<<x<<endl
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INTMAX 2147483647
#define INT_MAX LONG_LONG_MAX
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

ll countSafeSquares(ll n, vector<pll>& queens) {
    if(queens.empty()) return n * n;
    vector<ll> xs, ys;
    for(auto [x, y] : queens) {
        xs.pb(max(0ll, x-1));
        xs.pb(x);
        xs.pb(min(n-1, x+1));
        ys.pb(max(0ll, y-1));
        ys.pb(y);
        ys.pb(min(n-1, y+1));
        if(x > 0 && y > 0) { xs.pb(x-1); ys.pb(y-1); }
        if(x > 0 && y < n-1) { xs.pb(x-1); ys.pb(y+1); }
        if(x < n-1 && y > 0) { xs.pb(x+1); ys.pb(y-1); }
        if(x < n-1 && y < n-1) { xs.pb(x+1); ys.pb(y+1); }
    }
    xs.pb(0); xs.pb(n-1);
    ys.pb(0); ys.pb(n-1);
    sort(ALL(xs));
    sort(ALL(ys));
    xs.erase(unique(ALL(xs)), xs.end());
    ys.erase(unique(ALL(ys)), ys.end());
    ll safe = n * n;
    unordered_set<ll> attacked;
    for(auto [qx, qy] : queens) {
        ll qi = lower_bound(ALL(xs), qx) - xs.begin();
        ll qj = lower_bound(ALL(ys), qy) - ys.begin();
        for(ll i = 0; i < xs.size(); i++) {
            for(ll j = 0; j < ys.size(); j++) {
                ll x = xs[i], y = ys[j];
                ll idx = i * ys.size() + j;
                if(!attacked.count(idx)) {
                    if(x == qx || y == qy || abs(x - qx) == abs(y - qy)) {
                        attacked.insert(idx);
                        ll next_x = (i+1 < xs.size()) ? xs[i+1] : n;
                        ll next_y = (j+1 < ys.size()) ? ys[j+1] : n;
                        safe -= (next_x - x) * (next_y - y);
                    }
                }
            }
        }
    }
    
    return safe;
}

void solve() {
    ll n, q; cin >> n >> q;
    vector<pll> queens;
    rep(i, 0, q) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        queens.pb({r, c});
    }
    
    cout << countSafeSquares(n, queens) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    rep(t, 0, tc) {
        solve();
    }
    return 0;
}