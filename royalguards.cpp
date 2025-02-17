// [Verse 1]
// I will always remember
// The day you kissed my lips
// Light as a feather
// And it went just like this
// No, it's never been better than the summer
// Of 2002 (Ooh)

// [Verse 2]
// We were only eleven
// But acting like grown-ups
// Like we are in the present
// Drinking from plastic cups
// Singing, "Love is forever and ever"
// Well, I guess that was true (Ooh)

// [Pre-Chorus]
// Dancin' on the hood in the middle of the woods
// On an old Mustang where we sang
// Songs with all our childhood friends
// And it went like this, say

// [Chorus]
// Oops, I got 99 problems, singin' "bye, bye, bye"
// Hold up, if you wanna go and take a ride with me
// Better hit me, baby, one more time, uh
// Paint a picture for you and me
// On the days when we were young, uh
// Singin' at the top of both our lungs

// [Verse 3]
// Now we're under the covers
// Fast forward to eighteen
// We are more than lovers
// Yeah, we are all we need
// When we're holdin' each other
// I'm taken back to 2002 (Ooh)
// Yeah

// [Pre-Chorus]
// Dancin' on the hood in the middle of the woods
// On an old Mustang where we sang
// Songs with all our childhood friends
// And it went like this, say

// [Chorus]
// Oops, I got 99 problems, singin' "bye, bye, bye"
// Hold up, if you wanna go and take a ride with me
// Better hit me, baby, one more time, uh
// Paint a picture for you and me
// On the days when we were young, uh
// Singin' at the top of both our lungs
// On the day we fell in love

// [Post-Chorus]
// Ooh, ooh
// On the day we fell in love
// Ooh, ooh
// [Bridge]
// Dancin' on the hood in the middle of the woods
// On an old Mustang where we sang
// Songs with all our childhood friends
// Oh, now

// [Chorus]
// Oops, I got 99 problems, singin' "bye, bye, bye"
// Hold up, if you wanna go and take a ride with me
// Better hit me, baby, one more time
// Paint a picture for you and me
// On the days when we were young
// Singin' at the top of both our lungs
// On the day we fell in love

// [Post-Chorus]
// Ooh, ooh
// On the day we fell in love
// Ooh, ooh
// On the day we fell in love
// Ooh, ooh
// On the day we fell in love
// Ooh, ooh
// On the day we fell in love, love, love
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
//#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
#define pq priority_queue
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
typedef long double ll;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
// (for doubles, use inf = 1/.0, div(a,b) = a/b)
ll inf = 1/.0;
ll div(ll a, ll b) { // floored division
    return a / b; }
bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
}
void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
        isect(x, erase(y));
}
ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
}
};

long long custom_floor(long double num){
    const long double epsilon = 0.0001;
    return static_cast<long long>( epsilon + num ) ;
}

void solve() {
    long long n; ll k; cin >> n >> k;
    ll arr[n+1], psum[n+1];
    long long dp[n+1];
    memset(dp, -1, sizeof(dp));
    psum[0] = 0;
    for (long long q = 0; q < n; q++) {
        cin >> arr[q];
        dp[q] = arr[q];
    }
    LineContainer lc;
    lc.add(0, dp[0]);
    long long ans = max(0ll, dp[0]);
    for (long long q = 1; q < n; q++) {
        long double vroom = double(q);
        ll why = vroom*vroom/k + lc.query(q);
        long long help = custom_floor(why) + arr[q]; 
        dp[q] = max(dp[q], help);
        ans = max(dp[q], ans);
        long double gay = vroom * vroom / k;
        long double sus = dp[q] + gay;
        lc.add(-2 / k * q, sus);
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}

