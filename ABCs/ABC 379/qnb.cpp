// Is it just me?
// Is it just me?
// I hate holding babies and people tryna save me
// Think religion is a business where you pay for God's forgiveness
// Modern art is borin', politicians are annoyin'
// I don't think love lasts forever and old music was better
// Am I just high
// Or am I kinda right?
// Is it just me or does anybody
// Feel the way that I feel?
// They're just not being real
// Tell me, is it just me or is anybody
// Thinking all the same shit?
// They're just not saying it
// Or is it just me?
// Is it just me?
// (Is it just me?)
// Weddings are outdated, the show 'Friends' was overrated
// I think rich kids have it easy and PDA is creepy
// The internet's obnoxious, people my age make me nauseous
// I think marijuana's classy and doing coke is trashy
// Am I just high
// Or am I kinda right?
// Is it just me or does anybody
// Feel the way that I feel?
// They're just not being real
// Tell me, is it just me or is anybody
// Thinking all the same shit?
// They're just not saying it
// Or is it just me?
// Is it just me?
// (Is it just me?)
// should probably bite my tongue, but
// (I) can't be the only one, yeah
// (I) should probably bite my tongue, but
// (I) can't be the only one
// Oh, is it just me or does anybody
// Feel the way that I feel?
// They're just not being real
// Tell me, is it just me or is anybody
// Thinking all the same shit?
// They're just not saying it
// Or is it just me?
// Is it just me?
// (Is it just me?)
// should probably bite my tongue, but
// (I) can't be the only one, yeah
// (I) should probably bite my tongue, but
// (I) can't be the only one
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
    ll n, k; cin >> n >> k;
    string sus; cin >> sus;
    ll ans = 0;
    for (ll q = 0; q <= n-k; q++) {
        ll flag = 0;
        for (ll w = 0; w < k; w++) {
            if (sus[q+w] == 'X') {flag = 1; break;}
        }
        if (flag) continue;
        else {
            ans++; q = q+k-1;
        }
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}