// Monday left me broken
// Tuesday I was through with hopin'
// Wednesday my empty arms were open
// Thursday waiting for love, waiting for love
// Thank the stars it's Friday
// I'm burning like a fire gone wild on Saturday
// Guess I won't be coming to church on Sunday
// I'll be waiting for love
// Waiting for love to come around
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

ll n, par[500001], s[500001], regret = 0;
vector<ll> adj[500001];
vector<ll> yes;

ll dfs(ll currn, ll currsum) {
    if (s[currn] < currsum) return 0;
    if (s[currn] == INT_MAX) s[currn] = currsum;
    currsum = s[currn]; ll ans = 1;
    if (!adj[currn].size()) {
        yes.pub(s[currn]); return 1;
    }
    for (auto it: adj[currn]) {
        ans = min(ans, dfs(it, currsum));
    }
    return ans;
}
void dfs2(ll currn, ll p, ll depth) {
    if (depth%2 == 0) {
        if (!adj[currn].size()) {
            s[currn] = s[p]; return;
        }
        ll mina = INT_MAX;
        for (auto it: adj[currn]) {
            mina = min(s[it] - s[p], mina);
        }
        s[currn] = s[p]+mina;
        for (auto it: adj[currn]) {
            dfs2(it, currn, depth+1);
        }
    } else {
        for (auto it: adj[currn]) {
            dfs2(it, currn, depth+1);
        }
    }
}

ll calc(ll currn, ll p) {
    ll whyy = (s[currn] - s[p]);
    for (auto it: adj[currn]) {
        whyy+=calc(it, currn);
    }
    return whyy;
}


void solve() {
    cin >> n; 
    for (ll q = 2; q <= n; q++) {
        cin >> par[q]; adj[par[q]].pub(q);
    }
    for (ll q = 1; q <= n; q++) {cin >> s[q]; if (s[q] == -1) s[q] = INT_MAX;}
    ll state = dfs(1, 0); s[0] = 0;
    if (!state) {cout << -1; return;}
    dfs2(1, 0, 1); cout << calc(1, 0);
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}