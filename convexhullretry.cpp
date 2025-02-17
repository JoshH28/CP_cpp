// [Intro]
// Mm-mm, mm mm

// [Verse 1]
// Think back to all the times we were young and clueless
// Those memories just seem so faded and useless

// [Pre-Chorus]
// Can you and me be like we used to be then?
// Thinking 'bout if we could just get back together

// [Chorus]
// Can we go back to the times that we would sit down and sing out loud?
// Shouting all the songs we heard on the radio
// Take me back to the times when we were young
// Laughing and sitting underneath thе sun
// Can you take me back to the timеs we used to love?

// [Drop]
// We used to love, love
// We used to love, love
// We used to love, love
// We used to love
// We used to love, love
// We used to love, love
// We used to love, love
// We used to love

// [Post-Drop]
// Take me back to the times when we were young
// Laughing and sitting underneath the sun
// Can you take me back to the times we used to love?
// We used to love

// [Verse 2]
// I didn't mean to hurt you by leaving, you know
// I Just needed to find my own heart

// [Pre-Chorus]
// Can you and me be like we used to be then?
// Thinking 'bout if we could just get back together

// [Chorus]
// Can we go back to the times that we would sit down and sing out loud?
// Shouting all the songs we heard on the radio
// Take me back to the times when we were young
// Laughing and sitting underneath the sun
// Can you take me back to the times we used to love?

// [Drop]
// We used to love, love
// We used to love, love
// We used to love, love
// We used to love
// We used to love, love
// We used to love, love
// We used to love, love
// We used to love
// [Outro]
// Take me back to the times when we were young
// Laughing and sitting underneath the sun
// Can you take me back to the times we used to love?
// We used to love
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
typedef long long ll;
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
    while ((y = x) != begin() && (--x)->p >= y->p)
        isect(x, erase(y));
}
ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
}
};

void solve() {
    ll qn, type, value, m, c; cin >> qn;
    LineContainer lc;
    for (ll q = 0; q < qn; q++) {
        cin >> type;
        if (type == 1) {// add operation
            cin >> m >> c;
            lc.add(m, c);
        } else {
            cin >> value;
            cout << lc.query(value) << "\n";
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}