// It's been three years and six whole months since I saw your face that night
// It took five seconds to fall in love and two more to make you mine
// Now it's four in the morning, suns set and seven minutes with you and it's heaven
// Ain't an hour that rolls by, I love you 24/7, 365
// Give you my name, if you wanted to
// Key to my heart if you want it too
// And I hope and pray that you'll stay right here
// 'til we're old and gray in our last few years
// I'm on a knee I just need a yes
// A couple kids and a picket fence
// Share the memories like an open book
// Every page I read it still got me hooked
// And I'm fine spending my whole life on everything you like
// Is it obvious that all of this is right?
// 'Cause it's been three years and six whole months since I saw your face that night
// It took five seconds to fall in love and two more to make you mine
// Now it's four in the morning, suns set and seven minutes with you and it's heaven
// Ain't an hour that rolls by, I love you 24/7, 365
// I'll share the last bite of every meal
// I'll wipe your tears when you're in your feels
// And I'll hold you close through a thunderstorm
// When it's cold at night know i'll keep you warm
// 'Cause I'm fine spending my whole life on everything you like
// Is it obvious that all of this is right?
// 'Cause it's been three years and six whole months since I saw your face that night
// It took five seconds to fall in love and two more to make you mine
// Now it's four in the morning, suns set and seven minutes with you and it's heaven
// Ain't an hour that rolls by, I love you 24/7, 365
// I love you 24/7, 365
// Now it's four in the morning, suns set and seven minutes with you and it's heaven
// Ain't an hour that rolls by, I love you 24/7, 365
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
    ll n; cin >> n; map<ll, ll> mp; ll arr[n];
    for (ll q = 0; q < n; q++) {
        cin >> arr[q];
        mp[arr[q]] +=1;
    }
    ll ans = 5;
    for (ll q = 6; q <= 7; q++) {
        if (mp[q] >= mp[ans]) {
            ans = q;
        }
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}