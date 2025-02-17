// I'll tell you a story before it tells itself
// I'll lay out all my reasons, you'll say that I need help
// We all got expectations and sometimes they go wrong
// But no one listens to me, so I put it in this song

// They tell me think with my head, not that thing in my chest
// They got their hands at my neck this time
// But you're the one that I want and if that's really so wrong
// Then they don't know what this feelin' is like

// And I say yeah, yeah
// Yeah, yeah, yeah
// Yeah, yeah
// Yeah, yeah, yeah-eah

// And I say yeah, yeah-eah
// Yeah, yeah, yeah-eah
// Yeah, yeah-eah
// Yeah, yeah, yeah-eah

// I'll tell them a story, they'll sit and nod their heads
// I tell you all my secrets and you tell all your friends
// Hold on to your opinions and stand by what you said (Stand by what you said)
// In the end, it's my decision, so it's my fault when it ends
// You might also like
// ​bad idea right?

// They tell me think with my head, not that thing in my chest
// They got their hands at my neck this time
// But you're the one that I want, and if that's really so wrong
// Then they don't know what this feelin' is like

// And I say yeah, yeah-eah
// Yeah, yeah, yeah-eah
// Yeah, yeah-eah
// Yeah, yeah, yeah-eah
// And I say yeah, yeah-eah
// Yeah, yeah, yeah-eah
// Yeah, yeah-eah
// Yeah, yeah, yeah-eah

// I'll tell you a story before it tells itself
// I'll lay out all my reasons, you'll say that I need help
// We all got expectations and sometimes they go wrong
// But no one listens to me, so I put it in this song

// They tell me think with my head, not that thing in my chest
// They got their hands at my neck this time
// But you're the one that I want, and if that's really so wrong
// Then they don't know what this feelin' is like
// [Build: Kelsea Ballerini, Andrew Taggart, Both]
// My friends say no, no (But they don't know)
// No, no
// Yeah, they don't know, no
// They don't know, no-no (No, no)

// And I say yeah, oh (Oh)
// And I say yeah, hey-ey, yeah
// They don't know, oh
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

ll n, arr[2001], dp[2001][2001];

ll memo(ll curr, ll prev) {
    if (curr > n) return 0;
    if (dp[curr][prev] != -1) return dp[curr][prev];
    ll ans = memo(curr+1, prev);
    if (prev == 0 || !(arr[curr]&arr[prev])) ans = max(ans, memo(curr+1, curr)+1);
    return dp[curr][prev] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp)); cin >> n;
    for (ll q = 1; q <= n; q++) cin >> arr[q]; 
    ll ans = memo(1, 0); cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}