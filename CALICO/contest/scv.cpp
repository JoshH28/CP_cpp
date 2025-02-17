// Order food online
// 'Bout a hundred times
// Just to hide out
// Go for endless drives
// Just to clear my mind
// Without any luck

// Keep the sweater
// 'Cause I know you're gonna miss me in September
// When pumpkin spice makes you cry
// But treat it better
// 'Cause there's nothing that can stitch us back together

// Close your eyes
// Am I still somewhere in your mind?
// We were young, thought we had superpowers
// Grew too tall for our small town
// Didn't wanna slow down
// We'd drink all night
// Singing, "Hit me baby one more time"
// Running through the mayflowers
// We both know why it ended
// I will spend forever
// Trying to forget her

// Throw away my phone
// 'Cause I wanna call every night
// Make up yet another lie
// That I tell myself to get by

// Keep the sweater
// 'Cause I know you're gonna miss me in September
// But treat it better
// 'Cause there's nothing that can stitch us back together

// Close your eyes
// Am I still somewhere in your mind?
// We were young, thought we had superpowers
// Grew too tall for our small town
// Didn't wanna slow down
// We'd drink all night
// Singing, "Hit me baby one more time"
// Running through the mayflowers
// We both know why it ended
// I will spend forever
// Trying to forget her
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
    ll r, c; cin >> r >> c;
    char grid[r][c]; ll flag = 0;
    pair<ll, ll> first = {-1, -1}, last = {-1, -1};
    for (ll q = 0; q < r; q++) {
        for (ll w = 0; w < c; w++) {
            cin >> grid[q][w];
        }
    }
    for (ll q = 0; q < r; q++) {
        ll count = 0;
        for (ll w = 0; w < c; w++) {
            count += grid[q][w] == '#';
        }
        if (count == 1) {flag = 1; break;}
    }
    for (ll q = 0; q < c; q++) {
        ll count = 0;
        for (ll w = 0; w < r; w++) {
            count += grid[w][q] == '#';
        }
        if (count == 1) {flag = 1; break;}
    }
    if (flag == 1) cout << "phineas\n";
    else  cout << "ferb\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}