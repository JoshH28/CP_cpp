// Clarity wasn't really our thing
// Calling me, so you could do the talking
// Late nights, always at my place, yeah
// High off the shi you think would save ya
// Even though, I never really knew you
// Letting go is something I just can’t do
// How would it be if I knew better
// To just stay inside and wait for good weather?

// [Pre-Chorus]
// In the morning light, it's no surprise
// That our colors faded
// Keep on fanning the flame to burn it all away
// End it how we started

// [Chorus]
// 'Cause you look happier, happier without me
// It doesn’t matter where, matter where I'll be
// But I could nevеr figure it out, I could never changе your route, no
// 'Cause you look happier, happier without me
// Without me, without me
// (Without me, without me, without me, without me)
// 'Cause you look happier, happier without me

// [Drop]
// You look happier
// Never figure it out
// You look happier
// Never figure it out

// [Verse 2]
// I feel you now, only in my dreams
// Don't know how it became so haunting
// Masking the pain 'cause I'm still missing
// Even though I'm the only one losing
// Never close but God, I always tried to
// Let you know, giving more than I was meant to
// Too much has changed giving in like this
// But this melody’s holding me captive

// [Pre-Chorus]
// In the morning light, it’s no surprise
// That our colors faded
// Keep on fanning the flame to burn it all away
// End it how we started

// [Chorus]
// 'Cause you look happier, happier without me
// It doesn’t matter where, matter where I'll be
// But I could never figure it out, I could never change your route, no
// 'Cause you look happier, happier without me
// Without me, without me
// (Without me, without me, without me, without me)
// 'Cause you look happier, happier without me

// [Drop]
// You look happier
// Never figure it out
// You look happier
// Never figure it out
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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define INTMAX 2147483647
#define INT_MAX LONG_LONG_MAX
#define int long long
typedef long long ll;
typedef unsigned long long ull;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
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
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }
ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
    }
};

void solve() {
    ll n, c; cin >> n >> c;
    ll h[n], dp[n];
    for (ll q = 0; q < n; q++) {
        cin >> h[q];
        dp[q] = INT_MAX;
    }
    LineContainer lc;
    dp[0] = 0;
    lc.add(2*h[0], -((h[0]*h[0]) + c));
    for (ll q = 1; q < n; q++) {
        ll sus = h[q]*h[q] - lc.query(h[q]);
        dp[q] = min(dp[q], sus);
        lc.add(2*h[q], -((h[q]*h[q]) + c + dp[q]));
    }
    cout << dp[n-1];

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}