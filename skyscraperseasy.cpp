// [Verse 1]
// I love it when we hang out in your tree house after dark
// And when you hang my heart against the wall and play with darts
// I know it's kinda sad but you're the only home I got
// I promise I will love you even with my broken heart

// [Chorus]
// (And oh)
// 7UP in my red cup
// Tears pouring down on your makeup
// You can hold me down if you want to
// I don't really mind 'cause I'd like to
// Feel love, how it hurts, ah
// Fire in my chest, watch it burn out
// You can hold me down if you'd like to
// I don't really mind 'cause I love you

// [Verse 2]
// Remember when we took my car and
// Scratched it with our names
// And I was writing poetry about you everyday
// And yeah I know that things they never tend to stay the same
// But I don't think you love me and it kills me everyday

// [Chorus]
// (And oh)
// 7UP in my red cup
// Tears pouring down on your makeup
// You can hold me down if you want to
// I don't really mind 'cause I'd like to
// Feel love, how it hurts, ah
// Fire in my chest, watch it burn out
// You can hold me down if you'd like to
// I don't really mind 'cause I love you

// [Bridge]
// Rip the bandaid fast
// So it feels right
// Knife to my chest as I don't cry
// 7UP in my red cup
// Tears pouring down on your makeup
// You can hold me down if you want to
// (You can hold me down, oh, you can hold me down)

// [Chorus]
// 7UP in my red cup
// Tears pouring down on your makeup
// You can hold me down if you want to
// I don't really mind 'cause I'd like to
// Feel love, how it hurts, ah
// Fire in my chest, watch it burn out
// You can hold me down if you'd like to
// I don't really mind 'cause I love you
// I don't really mind 'cause I love you
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
    ll n; cin >> n; ll arr[n];
    for (ll q = 0; q < n; q++) cin >> arr[q];
    ll maxcnt = 0; ll ans[n];
    for (ll q = 0; q < n; q++) {
        ll currmin = arr[q], currcnt = arr[q];
        ll local[n]; local[q] = arr[q];
        for (ll w = q-1; w >= 0; w--) {
            currmin  = min(arr[w], currmin);
            local[w] = currmin;
            currcnt += local[w];
        }
        currmin = arr[q];
        for (ll w = q+1; w < n; w++) {
            currmin  = min(arr[w], currmin);
            local[w] = currmin;
            currcnt += local[w];
        }
        if (currcnt > maxcnt) {
            maxcnt = currcnt;
            for (ll q = 0; q < n; q++) {ans[q] = local[q];}
        }
    }
    for (ll q = 0; q < n; q++) {
        cout << ans[q] << " ";
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}