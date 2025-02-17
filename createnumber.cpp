// Yesterday (oh-oh)
// We were only kids, could never fade away
// Running through the wind and pouring rain
// Memories at the door
// Burning bright from long before
// We don't talk anymore
// What are we fighting for?
// I went my way
// You went sideways
// We were always running out of time
// Don't say we didn't try
// Don't say we could ever
// Be the same together (don't say we didn't try)
// We're not what we used to be
// Don't say you wanted me
// Don't say you wanted me
// Don't say you wanted me
// Seasons change (oh-oh)
// I kept getting colder
// Breathing shades of grey
// You were climbing higher, you'd say
// Memories at the door
// Burning bright from long before
// We don't talk anymore
// What are we fighting for?
// I went my way
// You went sideways
// We were always running out of time
// Don't say we didn't try
// Don't say we could ever
// Be the same together (don't say we didn't try)
// We're not what we used to be
// Don't say you wanted me
// Don't say you wanted me
// Don't say you wanted me
// Don't say you wanted me
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

void solve() {
    ll n; ll cost[10], minCost=INT_MAX; cin >> n;
    for (ll q = 1; q < 10; q++) {
        cin >> cost[q]; minCost = min(cost[q], minCost);
    }
    ll maxLength = n/minCost, idx = 0, moneyLeft = n;
    string ans=""; //cout << moneyLeft << " " << maxLength;
    for (ll q = 9; q >= 0; q--) {
        while(moneyLeft >= cost[q] + (maxLength-1)*minCost && maxLength > 0) {
            maxLength--; cout << q;
            moneyLeft -= cost[q];
        }
    }
    //cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}