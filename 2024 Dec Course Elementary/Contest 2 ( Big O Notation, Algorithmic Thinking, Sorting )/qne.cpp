// I'm sorry if it hurt
// Some things that I say
// Shouldn't be heard
// No I can't hide the pain
// But you still stick around
// Through every wave
// I'm tired of always changing
// Like the weather
// Can't keep my feelings to myself
// When I can't breathe
// Only you have seen
// How messed up I can be
// It's like you
// Love me on the inside
// Love me on the inside
// Love me on the inside out
// I don't see a good side
// No one I can recognize
// You still get me
// Inside out
// But I'll never see me
// Through your eyes
// You see through all my flaws
// It's almost like you're in love with my scars
// I can't lose who we are
// Cus we are all I've got
// I'm tired of always changing
// Like the weather
// Can't keep my feelings to myself
// When I can't breathe
// Only you have seen
// How messed up I can be
// It's like you
// Love me on the inside
// Love me on the inside
// Love me on the inside out
// I don't see a good side
// No one I can recognize
// You still get me
// Inside out
// Don't have to hide your darkness
// Let me carry it for a while
// Never have to cry in silence
// Everything that's yours is mine
// It's like you
// Love me on the inside
// Love me on the inside
// Love me on the inside out
// I don't see a good side
// No one I can recognize
// You still get me
// Inside out
// But I'll never see me
// Through your eyes
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
    ll n, c[10], mincost=INT_MAX; cin >> n;
    for (ll q = 1; q < 10; q++) {
        cin >> c[q]; mincost = min(mincost, c[q]);
    }
    ll l = n / mincost; vector<ll> arr;
    for (ll q = 0; q < l; q++) {
        for (ll w=9; w >=1; w--) {
            if ((l - q - 1) * mincost + c[w] <= n) {
                n -= c[w]; arr.pub(w);
                break;
            }
        }
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    for (auto it: arr) cout << it;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}