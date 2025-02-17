// Did I say something wrong? Did you hear what I was thinking?
// Did I talk way too long when I told you all my feelings that night?
// Is it you? Is it me? Did you find somebody better?
// Someone who isn't me, 'cause I know that I was never your type
// Never really your type
// Overthinking's got me drinking
// Messing with my head, whoa
// Tell me what you hate about me
// Whatever it is, I'm sorry
// Yeah, yeah, yeah, yeah, yeah, yeah
// I know I can be dramatic
// But everybody said we had it
// Yeah, yeah, yeah, yeah, yeah, yeah
// I'm coming to terms with a broken heart
// I guess that sometimes good things fall apart
// When you said it was real, guess I really did believe you
// Did you fake how you feel when we parked down by the river that night?
// That night?
// That night when we fogged up the windows in your best friend's car
// 'Cause we couldn't leave the windows down in December
// Whoa
// Tell me what you hate about me
// Whatever it is, I'm sorry
// Yeah, yeah, yeah, yeah, yeah, yeah
// I know I can be dramatic
// But everybody said we had it
// Yeah, yeah, yeah, yeah, yeah, yeah
// I'm coming to terms with a broken heart
// I guess that sometimes good things fall apart
// Overthinking's got me drinking
// Messing with my head, oh
// Tell me what you hate about me (about me)
// Whatever it is, I'm sorry (oh, I'm sorry)
// Yeah, yeah, yeah (oh, I'm sorry), yeah, yeah, yeah
// I know I can be dramatic (I know I can be)
// Everybody said we had it
// Yeah, yeah, yeah, yeah, yeah, yeah
// I'm coming to terms with a broken heart
// I guess that sometimes good things fall apart
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

ll dp[101][10001], cost[101];
ll n, m;
const ll mod = 998244353;

ll memo(ll cn, ll cm) {
    if (cn == n) {return cm == 0;}
    if (dp[cn][cm] != -1) {return dp[cn][cm];}
    ll ans = 0;
    if (cm >= cost[cn]) ans += memo(cn+1, cm - cost[cn])%mod;
    ans += memo(cn+1, cm)%mod;
    return dp[cn][cm] = ans%mod;
}

void solve() {
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for (ll q = 0; q < n; q++) {cin >> cost[q];}
    cout << memo(0, m)%mod;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}