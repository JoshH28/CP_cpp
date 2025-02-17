// I'm on the West Coast swinging by your neighbor
// Haven't left my room yet, I'm still in my bath robe
// Hard to let go, momma says I'm special
// Think I'm 'bout to lose it, burnin' all my French toast
// Ooh-la-la, I'm alive, no matter how hard I try
// Tell me why

// I get nervous, every word I think about
// I'm just tryna let it out
// I'm an asshole, mmm-mm
// At least that's what people say
// I don't need them anyway
// No, they don't care about me

// I try to run but the drink keeps closin' in
// Can't reach my brain, it's blowin' in the wind
// Sure must be nice, can you tell me how it's been?
// She's stuck on stuck with me
// Might be the best start

// I'm on the West Coast swinging by your neighbor
// Haven't lеft my room yet, I'm still in my bath robe
// Hard to let go, momma says I'm special
// Think I'm 'bout to lose it, burnin' all my French toast
// Ooh-la-la, I'm alive, no matter how hard I try
// Tell me why

// You deserve it, all the pain comin' your way
// Only got yourself to blame
// How's the burnin', by the time that you figured it out?
// Now there's no one around

// I try to run (I try to) but the drink keeps closin' in
// Can't reach my brain, it's blowin' in the wind (blowin' in the wind)
// Sure must be nice, can you tell me how it's been?
// She's stuck on stuck with me
// Might be the best start

// I'm on the West Coast swinging by your neighbor
// Haven't left my room yet, I'm still in my bath robe
// Hard to let go, momma says I'm special
// Think I'm 'bout to lose it, burnin' all my French toast
// Ooh-la-la, I'm alive, no matter how hard I try
// Tell me why

// Ooh-la-la, I'm alive, no matter how hard I try
// Tell me why
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

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; //to do 4dir skip every odd index
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //to do 4dir skip every odd index

void solve() {
    ll n; cin >> n; ll arr[n+10], yes[n+10];
    vector<ll> dp(n+10, 0);
    for (ll q = 0; q <= n+5; q++) yes[q] = INT_MAX;
    for (ll q = 1; q <= n; q++) {
        cin >> arr[q];
        dp[q] = min(dp[q-1]+1, yes[arr[q]]);
        yes[arr[q]] = min(yes[arr[q]], dp[q-1]);
    }
    cout << n-dp[n] << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}