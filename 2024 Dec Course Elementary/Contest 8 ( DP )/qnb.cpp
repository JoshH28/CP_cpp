// Gyattin' around the Rizzmas tree
// Kodak Black's with Kai Cenat
// Mangoes are hung, so skibidi
// 2hollis concert on Roblox
// Gyattin' around the Rizzmas tree
// Let the John Pork calls ring
// Later we'll have some Lunchly, Primes
// And we'll do some hawk tuahing
// You will get a sigma aura feeling
// When you mew
// Winter's arcing, cheese be drippy
// Still, the water with toilets, Skibidi
// Gyattin' around the Rizzmas tree
// Have a Feastable the Ocky Way
// Everyone mewin' rizzily
// In their new low taper fade
// You will get a sigma aura feeling
// When you mew
// Winter's arcing, cheese be drippy
// Still, thе water with toilet, Skibidi
// Gyattin' around the Rizzmas tree
// Havе a Feastable the Ocky Way
// Everyone mewin' rizzily
// In their new low taper fade
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
    ll n, mod = 1e9+7; cin >> n; 
    ll dp[n+10], arr[n+10], ans=0;
    for (ll q = 0; q < n; q++) {
        cin >> arr[q]; dp[q] = 1;
    }
    for (ll q = 0; q < n; q++) {
        for (ll w = 0; w < q; w++) {
            if (arr[w] < arr[q] && arr[q]%2 != arr[w]%2) {
                dp[q] += dp[w]%mod; dp[q]%=mod;
            }
        }
    }
    for (ll q = 0; q < n; q++) {
        ans += dp[q]%mod; ans%=mod;
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}