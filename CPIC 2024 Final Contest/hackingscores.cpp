// To be young and in love in New York City (In New York City)
// To not know who I am, but still know that I'm good long as you're here with me
// To be drunk and in love in New York City (In New York City)
// Midnight into morning coffee
// Burning through the hours talking
// Damn, I like me better when I'm with you
// I like me better when I'm with you
// I knew from the first time
// I'd stay for a long time 'cause
// I like me better when
// I like me better when I'm with you
// I don't know what it is, but I got that feeling (got that feeling)
// Wakin' up in this bed next to you
// Swear the room, yeah, got no ceiling
// If we lay, let the day just pass us by
// I might get to too much talking
// I might have to tell you somethin'
// I like me better when I'm with you
// I like me better when I'm with you
// I knew from the first time
// I'd stay for a long time 'cause
// I like me better when
// I like me better when I'm with you
// Stay awhile, stay awhile
// Stay here with me
// Stay awhile, stay awhile, oh
// Stay awhile, stay awhile
// Stay here with me
// Lay here with me
// Eh-eh, eh-eh, oh
// I like me better when I'm with you (yes I do, yes I do babe)
// I like me better when I'm with you (oh no)
// I knew from the first time
// I'd stay for a long time 'cause
// I like me better when
// I like me better when I'm with you
// I'm with you
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
    ll n, time, cutoff, k; cin >> n >> time >> cutoff >> k; ll arr[n];
    for (ll q = 0; q < n; q++) cin >> arr[q];
    ll pan = arr[n-1]; pan += time*k;
    arr[n-1] = pan; ll wow = 0;
    sort(arr, arr+n); reverse(arr, arr+n);
    for (ll q = 0; q < n; q++) {
        if (arr[q] == pan) {wow = q; break;}
    }
    for (ll q = wow - 1; q >= 0; q--) {
        ll regret = arr[q] - pan;
        ll gay = ceil( (ld)(regret)/ (ld)(k) );
        if (gay > time) {
            arr[q] -= time*k;
            time = 0; break;
        } else {
            time -= gay;
            arr[q] -= gay*k;
        } 
    }
    sort(arr, arr+n); reverse(arr, arr+n);
    for (ll q = 0; q < cutoff; q++) {
        if (pan == arr[q]) {
            cout << "Gold medal is mine!"; return;
        } 
    }
    cout << "Time to cry forever!"; return;

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}