// Lights out, it's cold outside
// You're not here
// Oh, when I think of your face, it's crystal clear
// Mm-mm-mm-mmm
// And I say I'm fine, but I'm lying at the time
// And I say I'm cool, but how could I be?
// And I say I'm over it, not over it at all
// Stuck in-between it all
// Picking flowers don't really mean much
// If you're not by my side when I wake up
// I leave the TV on, make me feel less alone
// You're asleep, and I'm awake at midnight
// Counting sheep until I'm out of my mind
// Looking at pictures from you and your camera phone
// Pretending I'm alright
// Thousands of train tracks, but I can't leave no (ooh-ooh, oh-oh-oh)
// And I'd swim, but the ocean is far too deep
// So you're out of reach
// And I say I'm fine, but I'm lying at the time
// And I say I'm cool, but how could I be?
// And I say I'm over it, not over it at all
// Stuck in-between it all
// Picking flowers don't really mean much
// If you're not by my side when I wake up
// I leave the TV on, make me feel less alone
// You're asleep, and I'm awake at midnight
// Counting sheep until I'm out of my mind
// Looking at pictures from you and your camera phone
// Pretending I'm alright
// Oh yeah
// Pretending I'll be fine
// Hey, hey
// Pretending I'm alright
// But I'm not really alright, alright, alright
// Mm-mm-mm-mm
// Mm-mm-mm-mm-mm-mm-mm
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
    ll n, qn, a, b; cin >> n >> qn;
    ll dist[n+10][2], arr[n+10];
    for (ll q = 1; q <= n; q++) cin >> arr[q];
    dist[1][1] = 1; dist[n][0] = 1;
    for (ll q = 2; q <= n-1; q++) {
        if (arr[q] - arr[q-1] > arr[q+1] - arr[q]) {// shuttle from q to q+1
            dist[q][1] = 1; dist[q][0] = arr[q] - arr[q-1];
        } else {// shuttle from q to q-1
            dist[q][0] = 1; dist[q][1] = abs(arr[q] - arr[q+1]);
        }
    }
    ll inc[n+10], dec[n+10];
    inc[1] = 0; dec[n] = 0;
    for (ll q = 1; q < n; q++) {
        inc[q+1] = inc[q] + dist[q][1];
    }
    for (ll q = n; q > 1; q--) {
        dec[q-1] = dec[q] + dist[q][0];
    }
    for (ll q = 0; q < qn; q++) {
        cin >> a >> b;
        if (a < b) {
            cout << abs(inc[b] - inc[a]) << "\n";
        } else {
            cout << abs(dec[a] - dec[b]) << "\n";
        }
    }

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}