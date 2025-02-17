// I see you're lost inside
// Devil on your back, pushing angels away
// You found the truth in lies
// 'Cause heaven ain't the place that you thought it would be
// Feeling trapped under all of that pressure
// Promise you that it's gonna get better
// Holding on when you know you should walk away
// Save a little piece of your heart
// It's okay if you let go
// Save a little light in the dark
// For the nights when it gets cold
// Save a little hope for the days that don't make sense
// It's never too late to start again, woah-oh-oh
// Save a little piece of your heart
// 'Cause all you need is love
// You see the warning signs
// But you're blinded by the love so you're taking the blame
// Still tryna change that high
// But it's hard to tame a fire when you're fueling the flame
// Feeling trapped under all of that pressure
// Promise you that it's gonna get better
// Holding on when you know you should walk away
// Save a little piece of your heart
// It's okay if you let go
// Save a little light in the dark
// For the nights when it gets cold
// Save a little hope for the days that don't make sense
// It's never too late to start again, woah-oh-oh
// Save a little piece of your heart
// 'Cause all you need is love
// 'Cause all you need is love
// 'Cause all you need is love
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
    ll tpn, hn; cin >> tpn >> hn;
    ll teleporters[tpn], dests[hn];
    for (ll q = 0; q < tpn; q++) cin >> teleporters[q];
    for (ll q = 0; q < hn; q++) cin >> dests[q];
    ll psum[tpn+1]; psum[0] = 0;
    for (ll q = 0; q < tpn; q++) {
        psum[q+1] = psum[q]+teleporters[q];
    }
    for (ll q = 0; q < hn; q++) {
        ll lol = lower_bound(psum, psum+hn+1, dests[q])-psum;
        cout << lol << "\n";
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}