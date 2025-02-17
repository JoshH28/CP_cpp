// The only color I wear is black
// 'Cause someone at school said you look fat
// The boy you like doesn't like you back
// But it won't always be like that
// I won't say it all gets better
// But fifteen doesn't last forever
// If high school me could see me now
// I bet high school me would be so proud, she'd find out
// The cool kids, they ain't everything
// The world is so much bigger then her town
// If high school me could see me now
// You drink just 'cause you think you should
// But it never makes you feel that good
// And you gave away your innocence
// Only 'cause he talked you into it
// I won't say it all gets better
// But fifteen doesn't last forever
// If high school me could see me now
// I bet high school me would be so proud, she'd find out
// The cool kids, they ain't everything
// The world is so much bigger then her town
// If high school me could see me now
// See me now, wish she could see me now
// See me now, see me now
// See me now, wish she could see me now
// See me now, see me now
// If high school me could see me now
// I bet high school me would be so proud, she'd find out
// The cool kids, they ain't everything
// The world is so much bigger then her town
// If high school me could see it then
// I bet she'd feel better in her skin, she'd begin
// To see the things that all go wrong
// Are things that she'll be writing songs about
// If high school me could see me now
// See me now, wish she could see me now
// See me now
// If high school me could see me now
// See me now, wish she could see me now
// See me now, see me now
// Wish I could go back, tell her it's okay
// (Tell her it's okay)
// Wish I could go back, tell her it's okay
// (Tell her it's okay)
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
    ll m, k;
    cin >> m >> k;
    map<ll, ll> mp;
    for (ll q = 0; q < 1000000; q++) {
        bool valid = true;
        for (auto it : to_string(q)) {
            if (it == 56) {
                valid = false;break;
            }
        }
        if (valid) mp[q % m]++;
    }
    ll ans = (k / m) + 1, a = k / 1'000'000;
    for (ll q = 1e6 * a; q <= k; q++) {
        if (q % m == 0) {
            bool valid = true;
            for (auto it : to_string(q)) {
                if (it == '8') {
                    valid = false; break;
                }
            }
            if (valid) ans--;
        }
    }
    for (ll q = 0; q < a; q++) {
        bool valid = true;
        for (auto it : to_string(q)) {
            if (it == '8') {
                valid = false; break;
            }
        }
        if (valid) ans -= mp[(m - (q * 1'000'000LL % m)) % m];
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}