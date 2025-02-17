// [Verse 1]
// Where there's a will, there's a way, kinda beautiful
// And every night has its day, so magical
// And if there's love in this life, there's no obstacle
// That can't be defeated
// For every tyrant a tear for the vulnerable
// In every lost soul the bones of a miracle
// For every dreamer a dream we're unstoppable
// With something to believe in

// [Chorus]
// Monday left me broken
// Tuesday I was through with hopin'
// Wednesday my empty arms were open
// Thursday waiting for love, waiting for love
// Thank the stars it's Friday
// I'm burning like a fire gone wild on Saturday
// Guess I won't be coming to church on Sunday
// I'll be waiting for love
// Waiting for love to come around

// [Instrumental Break]

// [Verse 2]
// We are one of a kind, irreplaceable
// How did I get so blind and so cynical?
// If there's love in this life we're unstoppable
// No, we can't be defeated

// [Chorus]
// Monday left me broken
// Tuesday I was through with hopin'
// Wednesday my empty arms were open
// Thursday waiting for love, waiting for love
// Thank the stars it's Friday
// I'm burning like a fire gone wild on Saturday
// Guess I won't be coming to church on Sunday
// I'll be waiting for love
// Waiting for love to come around
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

ll calculate(ll u) {
    ll bruh = ((u)*(u+1))/2;
    return bruh;
}

void solve() {
    ll n, qn; cin >> n; ll arr[n+10], psum[n+10];
    for (ll q = 1; q <= n; q++) cin >> arr[q];
    for (ll q = 1; q <= n; q++) psum[q] = psum[q-1]+arr[q];
    cin >> qn; ll l, u;
    for (ll q = 0; q < qn; q++) {
        cin >> l >> u;
        ll lo = l, hi = n, maxperformance = -INT_MAX, r = INT_MAX;
        while (lo <= hi) {
            ll mid = (lo+hi)/2, mid1 = (lo+hi)/2 + 1; //trying this current end point
            ll p1 = (psum[mid]-psum[l-1])*(u+1) - calculate(psum[mid] - psum[l-1]);
            ll p2 = (psum[mid1]-psum[l-1])*(u+1) - calculate(psum[mid1] - psum[l-1]);
            if (p1 == p2) {
                maxperformance = max(p1, p2);
                r = min({n, mid, mid1});
                break;
            } 
            else if (p1 < p2) {
                if (p2 > maxperformance) {
                    maxperformance = p2;
                    r = mid1;
                } else if (p2 == maxperformance) r = min(r, mid1);
                lo = mid+1;
            } else {
                if (p1 > maxperformance) {
                    maxperformance = p1;
                    r = mid;
                } else if (p2 == maxperformance) r = min(r, mid);
                hi = mid-1;
            }
        }
        if (r >= n) {r = n;}
        cout << r << " ";
    }
    cout << "\n"; 
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}