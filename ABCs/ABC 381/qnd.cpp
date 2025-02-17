#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int, long long int>
#define gcd(x, y) __gcd(x, y)
#define ALL(x) x.begin(), x.end()
#define pll pair<long long, long long>
#define debug(x) cerr << #x << ':' << x << endl
#define rep(x, start, end) for (auto x = (start) - ((start) > (end)); x != (end)-((start) > (end)); ((start) < (end) ? x++ : x--))
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; // upper_bound and lower_bound swap functions in multi
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template <class K, class V>
using ht = gp_hash_table<K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>, hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<>, true>>;

vector<pll> supershy;
// ll dp[500001][2]; 

// ll memo(ll idx, ll tookprev, unordered_set<ll>& us) {
//     if (idx == supershy.size()) return 0;
//     if (dp[idx][tookprev] != -1) return dp[idx][tookprev];
//     ll ans = memo(idx + 1, 0, us); // skip current element
//     if (tookprev == 0) {
//         if (us.find(supershy[idx].se) == us.end()) {
//             us.insert(supershy[idx].se);
//             ans = max(ans, 2 + memo(idx + 1, 1, us)); // take current element
//             us.erase(supershy[idx].se);
//         }
//     }
//     dp[idx][tookprev] = ans;
//     return ans;
// }

void solve() {
    ll n, ans = 0; cin >> n;
    vector<ll> arr(n);
    for (ll q = 0; q < n; q++) cin >> arr[q];
    for (ll i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            supershy.push_back({i, arr[i]});
        }
    }
    deque<pll> skibidi; unordered_set<ll> us;
    for (auto it : supershy) {
        if (skibidi.empty()) {
            skibidi.push_back(it);
            us.insert(it.se);
        } else {
            if (us.find(it.se) == us.end() && it.fi == skibidi.back().fi + 2) {
                skibidi.push_back(it);
                us.insert(it.se);
            } else if (it.fi == skibidi.back().fi + 2) {
                while (us.find(it.se) != us.end()) {
                    us.erase(skibidi.front().se);
                    skibidi.pop_front();
                }
                skibidi.push_back(it);
                us.insert(it.se);
            } else {
                skibidi.clear();
                us.clear();
                skibidi.push_back(it);
                us.insert(it.se);
            }
        }
        ans = max(ans, (ll)skibidi.size() * 2);
    }
    cout << ans << "\n";
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    for (ll q = 0; q < tc; q++) {
        solve();
    }
}
