// La da la da da, la da da da
// La da la da di da da, la da da da da
// La da la da da, la da da
// La da la da di da
// I got my head out the sunroof
// I'm blasting our favorite tunes
// I only got one thing on my mind
// You got me stuck on the thought of you
// You're making me feel brand new
// You're more than the sunshine in my eyes
// You got those pretty eyes in your head, you know it
// You got me dancing in my bed so let me show it
// You are exactly what I want, kinda cool and kinda not
// Wanna give myself to you
// Yeah, we're driving down the freeway at night
// I only got one thing in the back of my mind (you got me stuck on the thought of you)
// I'm feeling like this might be my time to shine
// With you, with you, with you
// I got my head out the sunroof
// I'm blasting our favorite tunes
// I only got one thing on my mind
// You got me stuck on the thought of you
// You're making me feel brand new
// You're more than the sunshine in my eyes
// I got my head out the sunroof
// Oh-whoa, oh-whoa, ooh
// You got me stuck on the thought of you
// Oh-whoa, oh-whoa, ooh
// Yeah, we're driving down the freeway at night
// I only got one thing in the back of my mind (you got me stuck on the thought of you)
// I'm feeling like this might be my time to shine
// With you, with you, with you
// I got my head out the sunroof
// I'm blasting our favorite tunes
// I only got one thing on my mind
// You got me stuck on the thought of you
// You're making me feel brand new
// You're more than the sunshine in my eyes
// La da la da da, la da da da
// La da la da di da da, la da da da da
// La da la da da, la da da da
// La da la da di da da da
// La da la da da, la da da da
// La da la da di da da, la da da da da
// La da la da da, la da da da
// La da la da di da
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
    ll n, c, d, ans = -INT_MAX; cin >> n >> c >> d; ll arr[n]; 
    for (ll q = 0; q < n; q++) cin >> arr[q];
    sort(arr, arr+n); reverse(arr, arr+n);
    ll lo = 1, hi = d, test = 0;
    for (ll q = 0; q < min(d, n); q++) test+=arr[q];
    if (test >= c) {cout << "Infinity\n"; return;}
    while (lo <= hi) {
        ll mid = (lo+hi)/2, ls = 0;
        //cout << mid << "\n";
        for (ll q = 0; q <= min(mid, n-1); q++) {
            ls += arr[q];
        }
        ls *= (d / (mid+1));
        for (ll q = 0; q <= min((d%(mid+1)) -1, n-1); q++) {
            ls += arr[q];
        }
        //cout << ls << " ";
        if (ls >= c) {// can, go higher
            ans = max(ans, mid);
            lo = mid+1;
        } else {
            hi = mid-1;
        }
        //cout << "\n";
    }
    ll mid = 0, ls = 0;
    for (ll q = 0; q <= min(mid, n-1); q++) {
        ls += arr[q];
    }
    ls *= (d / (mid+1));
    for (ll q = 0; q <= min((d%(mid+1)) -1, n-1); q++) {
        ls += arr[q];
    }
    if (ls >= c) {// can, go higher
        ans = max(ans, mid);
    }
    if (ans == -INT_MAX) {cout << "Impossible\n"; return;}
    cout << ans << "\n"; return;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}