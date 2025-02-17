// [Verse 1]
// Heavy like a landslide
// That's the way my heart beats now
// Up until the last sunrise
// I'll be reaching for you
// Wanting you is all I know
// And loving you is out of my control
// So I'm letting go and going down

// [Pre-Chorus]
// 'Cause nothing lasts forever anymore
// But no one's felt the way you feel before
// 'Cause you sweep the floor beneath me and I'm
// I'm falling
// I'm infinitely falling for you

// [Chorus]
// I'm falling
// I'm infinitely falling for you
// I'm falling
// I'm infinitely falling for you
// I'm falling
// I'm infinitely falling for you
// I'm falling
// I'm infinitely falling for you

// [Verse 2]
// With all that I am 'til the last drop
// More of you I get I can't stop
// Lights always green
// Real as a dream
// You've been the cherry that's on top
// Voice in my head's getting so loud
// All I can see is you're here now
// And so
// I'm letting go and going down

// [Pre-Chorus]
// 'Cause nothing lasts forever anymore
// We float above the way you feel before
// But you sweep the floor beneath me and I'm
// I'm falling
// I'm infinitely falling for you

// [Chorus]
// I'm falling
// I'm infinitely falling for you
// I'm falling
// I'm infinitely falling for you
// I'm falling
// I'm infinitely falling for you
// I'm falling
// I'm infinitely falling for you
// I'm falling
// I'm infinitely falling for you
// I'm falling
// I'm infinitely falling for you
// I'm falling
// I'm infinitely falling for you
// I'm falling
// I'm infinitely falling for you
// [Outro]
// You
// I'm falling for you
// And only for you
// I'm falling for you
// (I'm falling
// I'm infinitely falling for you)
// (I'm falling, I'm falling)
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

bool cmp(pll p1, pll p2) {
    if (p2.se == p1.se) return p1.fi < p2.fi;
    else return p1.se < p2.se;
}

void solve() {
    ll n, k, ans = 0; 
    cin >> n >> k; 
    pll arr[n+10];
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (ll q = 0; q < n; q++) {
        cin >> arr[q].fi >> arr[q].se;
        pq.push({arr[q].fi, arr[q].se});
    }
    for (ll q = 0; q < k; q++) {
        ans += pq.top().fi;
        ll sus = pq.top().fi, gay = pq.top().se;
        pq.pop(); pq.push({sus+gay, gay});
    }
    cout << ans;
    
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}