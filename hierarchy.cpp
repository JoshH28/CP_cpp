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

struct DSU {
    const ll MAXN = 100001;
    ll parent[100001];
    ll size[100001];
    ll sizeOfMax = 1;
    DSU(ll n) {
        for (ll q = 1; q <= n; q++) {
            parent[q] = q;
            size[q] = 1;
        }
    }
    ll par(ll x) {
        if (parent[x] == x) {
            return x;
        } else {
            ll pathCompression = par(parent[x]);
            parent[x] = pathCompression; // path compression;
            return pathCompression;
        }
    }
    void merge(ll x, ll y) {
        if (par(x) == par(y)) return;
        if (size[par(x)] < size[par(y)]) {
            size[par(y)] += size[par(x)];
            parent[par(x)] = par(y);
            sizeOfMax = max(sizeOfMax, size[par(y)]);
        } else {
            size[par(x)] += size[par(y)];
            parent[par(y)] = par(x);
            sizeOfMax = max(sizeOfMax, size[par(x)]);
        }
    }
    bool isSameSet(ll x, ll y) {
        return par(x) == par(y);
    }
}*no;

struct edge {
    int a, b, w;
    edge (int _a=0, int _b=0, int _w=0): a(_a), b(_b), w(_w) {}
};
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w < y.w; } //Swap the comparator for maximum

void solve() {
    ll t1, t2, t3, n, en; cin >> n; ll arr[n+10], helpme[n+10];
    for (ll q = 1; q <= n; q++) cin >> arr[q];
    cin >> en; vector<pll> adjlist[n+10];
    no = new DSU(n+10);
    for (ll q = 0; q < en; q++) {
        cin >> t1 >> t2 >> t3;
        edge temp(t1, t2, t3);
        edgeList.pub(temp);
        adjlist[t1].pub({t2, t3});
        adjlist[t2].pub({t1, t3});
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    ll ans = 0;
    for (vector<edge>::iterator it = edgeList.begin(); it != edgeList.end(); ++it) {
        if (no->isSameSet(it->a, it->b)) continue;
        no->merge(it->a, it->b);
        ans += it->w;
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}