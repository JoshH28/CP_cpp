// [Verse 1]
// Skibidi, skibidi, hawk tuah hawk
// Skibidi king who gives out blumpkins
// Edging and gooning and learning to munt
// Dripping cheese all over my lunch

// [Chorus]
// Skibidi, skibidi, hawk tuah hawk
// Skibidi boom or skibidi doom
// Edging and gooning in Ohio square
// Stinky backshot air

// [Verse 2]
// On my grind time, drink a Prime time
// To mog the Ohio away
// Bulkan rage time, low taper fade time
// We go rizzing in the sigma's way

// [Chorus]
// Giddy up sigma horse, stretch out your meat
// Griddy around the ops
// Knee surgery is tomorrow and I feel skibidi
// Like a skibidi gyatt
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
    ll n; cin >> n;
    vector<pll> arr;
    pll yes[n+10];
    for (ll q = 0; q < n; q++) {
        cin >> yes[q].se >> yes[q].fi;
    }
    //cout << "\n";
    sort(yes, yes+n);
    ll curr = 0, cmax=-INT_MAX, cmin = INT_MAX;
    for (ll q = 0; q < n; q++) {
        if (yes[q].fi != curr) { // looking at new block
            if (curr != 0) {
                arr.pub({cmin, cmax});
                //cout << curr << " " << cmin << " " << cmax << "\n";
            } else {
                arr.pub({0, 0});
            }
            curr = yes[q].fi;
            cmax=-INT_MAX, cmin = INT_MAX;
        }
        cmax = max(cmax, yes[q].se);
        cmin = min(cmin, yes[q].se);
    }
    if (curr != 0) {
        arr.pub({cmin, cmax});
        //cout << curr << " " << cmin << " " << cmax << "\n";
    }
    //cout << "\n";
    ll dp[n+10][5]; 
    for (ll q = 0; q < n; q++)
        for (ll w = 0; w < 5; w++) 
            dp[q][w] = INT_MAX;
    dp[0][0] = 0; dp[0][1] = 0;
    //cout << dp[0][0] << " " << dp[0][1] << "\n";
    for (ll q = 1; q < arr.size(); q++) {
        // settle ending at front first
        dp[q][0] = min(
            dp[q-1][0] + abs(arr[q].se - arr[q-1].fi) ,  
            dp[q-1][1] + abs(arr[q].se - arr[q-1].se)
        ) + abs(arr[q].se - arr[q].fi);
        // settle ending at back first
        dp[q][1] = min(
            dp[q-1][0] + abs(arr[q].fi - arr[q-1].fi) ,  
            dp[q-1][1] + abs(arr[q].fi - arr[q-1].se)
        ) + abs(arr[q].se - arr[q].fi);
        //cout << dp[q][0] << " " << dp[q][1] << "\n";
    }
    cout << min(dp[arr.size()-1][0] + abs(arr[arr.size()-1].fi), dp[arr.size()-1][1] + abs(arr[arr.size()-1].se));
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}