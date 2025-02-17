// CIA Triad:

// It is what is used to define security. 

// Confidentiality:

// Confidentiality relates to permitting authorized access to information, while simultaneously protecting information from improper disclosure
// eg when running a banking website, must make sure that random outsiders cant see sensitive data like other ppls bank account, but must also allow the owner of the bank account to see how much money they have 

// Integrity:

// Integrity is the property of information whereby it has not been altered in an unauthorized manner
// Eg if I make my In-game name “lol”, it shouldn't suddenly change to “bruh” without me doing so

// Availability:

// Availability means that systems and data are accessible at the time users need them.
// Note: availability means systems and data meet the requirements of the business for timely and reliable access, NOT that data or systems are available 100% of the time. 
// needs to be available + can reliably serve the content it is intended to serve
 
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
    ll n, ans = 0, streak = 1;
    cin >> n; ll arr[n];
    // ll precomp[n+1]; precomp[1] = 0;
    // for (ll q = 2; q <= n; q++) {
    //     precomp[q] = q - 1 + precomp[q-1];
    // }
    for (ll q = 0; q < n; q++) {cin >> arr[q];}
    for (ll q = 1; q < n; q++) {
        if (arr[q] == arr[q-1]) streak++;
        if (arr[q] != arr[q-1]) {
            if (streak > 1) ans = ans + (streak)*(streak-1)/2 + 1;
            streak = 1;
        }
        //cout << ans << " ";
    }
    if (streak > 1) ans = ans + (streak)*(streak-1)/2 + 1;
    streak = 1;
    //ans += precomp[streak+1];
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}