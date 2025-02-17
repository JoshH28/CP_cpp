// Saturday night what a wild wild dream
// The room feels like a full screen cinema
// Got you close got you so so close
// But not for long
// So I keep my head down keep my heart open
// Cause maybe one day you'll wanna stay
// You won't run away
// Street lights
// Remind me
// Of what it looks like
// To hit a dead end feeling
// I don't want to steal it but
// If I could borrow your time
// Lay your soul onto mine
// We could let go
// We could let go
// All night
// I wanna lose track of life
// Find myself in those eyes
// Pull you in close
// Baby don't go
// Hold tight
// All night
// Such a game such a cruel cruel game
// To watch my heart like sand through your fingertips
// In the meantime in the you and me time
// Don't let it fall
// Street lights
// Remind me
// Of what it looks like
// To hit a dead end feeling
// I don't want to steal it but
// If I could borrow your time
// Lay your soul onto mine
// We could let go
// We could let go
// All night
// I wanna lose track of life
// Find myself in those eyes
// Pull you in close
// Baby don't go
// Hold tight
// All night
// The sun keeps fading
// On my patience
// I'm losing faith
// It drives me crazy
// My heart keeps racing
// Can't stop chasing
// You
// The sun keeps fading
// On my patience
// I'm losing faith
// It drives me crazy
// But I'll keep waiting
// Can't stop chasing
// You
// If I could borrow your time
// Lay your soul onto mine
// We could let go
// We could let go
// All night
// I wanna lose track of life
// Find myself in those eyes
// Pull you in close
// Baby don't go
// Hold tight
// All night
// Hold tight
// All night
// The sun keeps fading
// On my patience
// I'm losing faith
// It drives me crazy
// My heart keeps racing
// Can't stop chasing
// You
// The sun keeps fading
// On my patience
// I'm losing faith
// It drives me crazy
// But I'll keep waiting
// Can't stop chasing
// You
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
    ll n, m, qn, t1; 
    cin >> n >> m >> qn;
    vector<ll> arr(m+2);
    arr.pub(0);
    for (ll q = 0; q < m; q++) 
        cin >> arr[q+1];
    arr.pub(n+1);
    sort(arr.begin(), arr.end());
    // for (auto it: arr) {
    //     cout << it << " ";
    // } cout << "\n";
    for (ll q = 0; q < qn; q++) {
        cin >> t1;
        auto eketright = upper_bound(arr.begin(), arr.end(), t1); 
        auto eketleft = lower_bound(arr.begin(), arr.end(), t1)-1;
        //cout << *eketleft << " " << *eketright << " ";
        if (*eketright == n+1) {//straight up go to last room
            cout << n - *eketleft << "\n";
        } else if (*eketleft == 0) {
            cout << *eketright - 1 << "\n";
        } else {
            ll mid = (*eketleft+*eketright)/2;
            //cout << mid << " ";
            cout << mid - *eketleft << "\n";
        }
    }

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}