// I remember when the bartender said it's on the house
// You make me wanna fall in love
// The weather felt better
// When we were in it together
// Oh I miss the way we used to talk about nothing
// I hate to say I should've seen it coming
// Last summer everything was easy
// We had it all didn't we baby
// No wonder you couldn't keep me
// It got harder than you thought it would be
// You stopped loving me on the dark nights
// Now you won't kiss me in the sunlight
// Last summer I knew you'd leave me
// 'Cause loving me isn't easy
// 'Cause loving me isn't easy
// 'Cause loving me isn't easy
// If you wanted to talk you would've texted
// If I wanted to stop I would've let it go
// But I get it it's alright
// 'Cause I can't keep my shit together
// Say f it yeah can't debate that
// Don't want sht to get better
// 'Cause it'd make me forget it all and I hate that
// Last summer everything was easy
// We had it all didn't we baby
// No wonder you couldn't keep me
// It got harder than you thought it would be
// You stopped loving me on the dark nights
// Now you won't kiss me in the sunlight
// Last summer I knew you'd leave me
// 'Cause loving me isn't easy
// 'Cause loving me isn't easy
// 'Cause loving me isn't easy
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
#define pq priority_queue
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

void solve() {
    ll x, y, e; cin >> x >> y >> e;
    cout << max(x-e-e, y);
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}