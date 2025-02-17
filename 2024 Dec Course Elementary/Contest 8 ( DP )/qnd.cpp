// There's a skibidi in my bed
// Sigmas goonin' in my head
// Glizzies all over the room
// Fanum's taxing in the pool
// I smell like a Discord mod
// Diddy's maxed out in the yard
// Mousepay on the tap-to-pay
// This my aura or my views?
// Snapchats of last night ended up on stream
// I'm sigma, oh, well
// It's a low-taper fade, but I'm pretty sure I mewed
// Damn
// Last rizzday night, yeah, we rizzed up all the gyatts
// And we griddied on the opps, think we streamed, but I got doxxed
// Last rizzday night, yeah, we readied up our squads
// And ate Feastable bars, IShowSpeed jumped over cars
// Last rizzday night, we went streaming with John Pork
// Livvy rizzed up Baby Gronk then we canceled Eminem
// Last rizzday night, I got plus ten thousand aura
// Kai Cenat, we're gonna rizz in Ohio
// But this rizzday night
// Skibidi again
// But this rizzday night
// Skibidi again
// Tryna edge but I got caught
// In 4K, I told my gyatts
// Think silky doin' too much
// Grimace Shakes are on the floor
// Rizz my favorite, Carti next
// Blud just doin' a side quest
// Think I need an alpha male
// That was such a beta L
// Snapchats of last night ended up on stream
// I'm sigma, oh, well (Oh, well)
// It's a low-taper fade, but I'm pretty sure I mewed
// Damn
// Last rizzday night, yeah, we rizzed up all the gyatts
// And we griddied on the opps, think we streamed, but I got doxxed
// Last rizzday night, yeah, we readied up our squads
// And ate Feastable bars, IShowSpeed jumped over cars
// Last rizzday night, we went streaming with John Pork
// Livvy rizzed up Baby Gronk then we canceled Eminem
// Last rizzday night, I got plus ten thousand aura
// Kai Cenat, we're gonna rizz in Ohio
// But this rizzday night
// Skibidi again
// But this rizzday night
// Skibidi again
// T.G.I.R., T.G.I.R., T.G.I.R
// T.G.I.R., T.G.I.R., T.G.I.R
// Last rizzday night, yeah, we rizzed up all the gyatts
// And we griddied on the opps, think we streamed, but I got doxed
// Last rizzday night, yeah, we readied up our squads
// And ate Feastable bars, IShowSpeed jumped over cars
// Last rizzday night, we went streaming with John Pork
// Livvy rizzed up Baby Gronk then we canceled Eminem
// Last rizzday night, I got plus ten thousand aura
// Kai Cenat, we're gonna rizz in Ohio
// But this rizzday night
// Skibidi again
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
    ll n; cin >> n; ll a[n+10], b[n+10], dp[n+10][5];
    for (ll q = 0; q < n; q++) cin >> a[q];
    for (ll q = 0; q < n; q++) cin >> b[q];
    for (ll q = 0; q < n+5; q++) 
        for (ll w = 0; w < 2; w++)
            dp[q][w] = INT_MAX;
    dp[0][0] = 0, dp[0][1] = 0;
    for (ll q = 1; q < n; q++) {
        //handle case of picking student from class 1
        dp[q][0] = min(max(dp[q-1][0], abs(a[q] - a[q-1])), max(dp[q-1][1], abs(a[q] - b[q-1])));
        //handle case of picking student from class 2
        dp[q][1] = min(max(dp[q-1][0], abs(b[q] - a[q-1])), max(dp[q-1][1], abs(b[q] - b[q-1])));
    }
    cout << min(dp[n-1][0], dp[n-1][1]);
    

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}