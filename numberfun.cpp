// These days, our song's on replay
// Begging the DJ, don't turn it off
// Baby, let your body move to my heartbeat
// I don't need no sleep, leave our love on
// And turn it up, up, play it all night
// Let your hands go, pick the tempo
// You're spinning on and on in my head
// Like a broken record, since I met ya, you're
// The melody that's stuck in my head
// I used to need hard liquor to get buzzed, but lately
// I got double vision when we touch, all I know is
// These days, our song's on replay
// Begging the DJ, don't turn it off
// Baby, let your body move to my heartbeat
// I don't need no sleep, leave our love on
// And turn it up, up, play it all night
// All night, play it all night
// All night, turn it up, up, play it all night
// (Turn it up, up, play it all night)
// (Turn it up, up, play it all night)
// (Turn it up, up, play it all night)
// (Turn it up, up, play it all night)
// Baby, let your body move to my heartbeat
// I don't need no sleep, leave our love on
// And turn it up, up, play it all night
// (Turn it up, up, play it all night)
// (Turn it up, up, play it all night)
// (Turn it up, up, play it all night)
// (Turn it up, up, play it all night)
// Let your hands go, pick the tempo
// You're spinning on and on in my head
// Like a broken record, since I met ya, you're
// The melody that's stuck in my head, I
// Used to need hard liquor to get buzzed, but lately
// I got double vision when we touch, all I know is
// These days, our song's on replay
// Begging the DJ, don't turn it off
// Baby, let your body move to my heartbeat
// I don't need no sleep, leave our love on
// And turn it up, up (play it all night)
// Baby, let your
// (Turn it up, up, play it all night)
// (Turn it up, up, play it all night)
// (Turn it up, up, play it all night)
// (Turn it up, up, play it all night)
// Baby, let your body move to my heartbeat
// I don't need no sleep, leave our love on
// And turn it up, up, play it all night
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
    ll maxn = 30000000, n, temp; ll dp[30000000+2]; 
    memset(dp, inf, sizeof(dp)); dp[0] = 0;
    for (ll q = 0; q <= 30000000; q++) {
        dp[q+1] = min(dp[q+1], dp[q]+1);
        if (q*3 <= maxn) dp[q*3] = min(dp[q*3], dp[q]+1);
        if (q*2 <= maxn) dp[q*2] = min(dp[q*2], dp[q]+1);
        //cout << dp[q] << " ";
    }
	cin >> n;
    for (ll q = 0; q < n; q++) {
        cin >> temp;
        cout << dp[temp] << "\n";
    }


}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}