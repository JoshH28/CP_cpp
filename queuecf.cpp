// Lost my train of thought again
// And wrote a bridge to 3 am (oh no)
// Fell asleep with open eyes
// And played a song to ease my mind (oh no)
// And after all I put me through
// There's gotta be a tunnel light
// There's gotta be some paradise
// And if I'm grip tight bulletproof
// There's never been a better time
// I'll drive the coast down to Loveland (and I)
// I'll take a dip in the sky (I)
// I call my mom cause she's still here and I feel alive
// Just one more time
// Heard a breeze and felt it take
// Some mileage off my lemon face (oh no)
// Thought the floor was fragile till I
// Took a breath and I sat real still (oh no)
// After all, who am I to say?
// There's gotta be a tunnel light
// There's gotta be some paradise
// And if I find out either way
// There's never been a better ride
// I'll drive the coast down to Loveland (and I)
// I'll take a dip in the sky (I)
// I call my mom cause she's still here and I feel alive
// Just one more time
// Calmly
// The rain is falling down
// And it finds me
// I feel it now I feel the clouds
// Softly
// They're laying on the ground
// And finally
// I feel it now I feel it now
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
    string sus; cin >> sus;
    ll n = sus.length();
    deque<ll> girl; ll start = 0;
    for (ll q = 0; q < n; q++) {
        if (sus[q] == 'M') break;
        start = q;
        girl.pub(0);
    }
    for (ll q = start+1; q < n; q++) {
        if (sus[q] == 'M') continue;
        if (girl.size() == 0)  girl.pub(q);
        else if (q - girl.size() > girl.back()){
            girl.pub(q-girl.size());
        } else {
            girl.pub(girl.back() + 1);
        } 
    }
    if (girl.size() == 0) cout << 0;
    else cout << girl.back();
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}