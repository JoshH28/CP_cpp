// Don't lie
// I know you've been thinking it
// And two times, you let it slip from your lips
// You got too much pride to make any promises
// Thinking that we got time
// And you wanna keep it in
// I want you out in the pouring rain
// I want you down on your knees
// Praying to God that I'll feel the same
// I'm right here baby so please
// Hold me up, tie me down
// "Cause I never wanna leave your side
// Swear to never let you down
// And it's been eatin' me alive
// You can take me home
// You can never let me go
// Hold me up, hold me up
// And tie me, tie me
// Down, down (down)
// And tie me, tie me
// Down, down
// And tie me, tie me
// Down, down (down)
// And tie me, tie me
// Down, down
// Nine lives until you fall at my feet
// Don't hide, you're wasting your energy
// You're not shy, so baby it's useless
// So don't try, cause you'll end up losing it
// I want you out in the pouring rain
// I want you down on your knees
// Praying to God that I'll feel the same
// I'm right here baby so please
// Hold me up, tie me down
// "Cause I never wanna leave your side
// Swear to never let you down
// And it's been eatin' me alive
// You can take me home
// You can never let me go
// Hold me up, hold me up
// And tie me, tie me
// Down, down (down)
// And tie me, tie me
// Down, down
// And tie me, tie me
// Down, down (down)
// And tie me, tie me
// Down, down
// So wrap your arms around my chest
// And I'll put my hands around your neck
// 'Cause nobody waste this waiting game
// You push and you pull, but you should stay
// Stay
// Hold me up, tie me down
// 'Cause I never wanna leave your side
// Swear to never let you down
// And it's been eatin' me alive
// You can take me home
// You can never let me go
// Hold me up, hold me up
// And tie me, tie me
// Down, down (down)
// And tie me, tie me
// Down, down
// And tie me, tie me
// Down, down (down)
// And tie me, tie me
// Down, down (down, down)
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

bool cmp(vector<ll> t1, vector<ll> t2) {
    return t1.size() < t2.size();
}

void solve() {
    vector<vector<ll>> lol;
    map<vector<ll>, ll> sussy; // noway this works
    ll n, k, t1; cin >> n >> k;
    for (ll q = 0; q < n; q++) {
        vector<ll> sus;
        for (ll w = 0; w < k; w++) {
            cin >> t1;
            sus.pub(t1);
        }
        sort(sus.begin(), sus.end());
        sussy[sus] += 1;
    }
    ll ans = 0;
    for (const auto& [key, value] : sussy) ans = max(value, ans);
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}