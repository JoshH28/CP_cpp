// Lose it all and find
// That you’re slipping through my fingers
// And the pain it stays and lingers
// Try to stay alive
// But I fear I’m losing patience this time
// All of the things you said we’d do
// they’re just overused
// All of the things you said we’d try
// they just passed us by
// I’m getting sick of saving lives and leaving mine to dry
// So I picked up the pace
// Left you I don’t need you babe
// Why does the world keep spinning round
// When all I did was hold you down
// Feels like I’m losing patience when you keep me waiting
// Why does the world keep spinning round
// When all I did was hold you down
// It’s so hard to save you
// When I needed saving
// Oooh
// I love you now but times
// running out and I’m losing you
// It’s like our love was fine
// But we lost our minds and feelings
// And you can blame me for the reasons
// All of the times we tried to fix us left me compromised
// Told me to leave you so I did and now our love has died
// I’m getting sick of saving lives and leaving mine to dry
// So I picked up the pace
// Left you I don’t need you babe
// Why does the world keep spinning round
// When all I did was hold you down
// Feels like I’m losing patience when you keep me waiting
// Why does the world keep spinning round
// When all I did was hold you down
// But it’s hard to save you
// When I needed saving
// Why does the world keep spinning round
// When all I did was hold you down
// Why does the world keep spinning round
// When all I did was hold you down
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

ll n, team[201], strength[201];
ll dp[101][501][501], target;

ll memo(ll index, ll a, ll b) {
  if (index == n) {
    if (a == target && b == target) return 0;
    else return INT_MAX;
  }
  if (dp[index][a][b] != -1) return dp[index][a][b];
  ll ans = INT_MAX;
  if (team[index] == 1) {
    ans = min(ans, 1+memo(index+1, a, b));
    if (a+strength[index] <= target) ans = min(ans, memo(index+1, a+strength[index], b));
    if (b+strength[index] <= target) ans = min(ans, 1 + memo(index+1, a, b+strength[index]));
  } else if (team[index] == 2) {
    ans = min(ans, 1+memo(index+1, a, b));
    if (a+strength[index] <= target) ans = min(ans, 1 + memo(index+1, a+strength[index], b));
    if (b+strength[index] <= target) ans = min(ans, memo(index+1, a, b+strength[index]));
  } else {
    ans = min(ans, memo(index+1, a, b));
    if (a+strength[index] <= target) ans = min(ans, 1 + memo(index+1, a+strength[index], b));
    if (b+strength[index] <= target) ans = min(ans, 1+memo(index+1, a, b+strength[index]));
  }
  dp[index][a][b] = ans; return ans;
}

void solve() {
  cin >> n; memset(dp, -1, sizeof(dp));
  for (ll q = 0; q < n; q++) cin >> team[q] >> strength[q]; 
  ll temp = 0; 
  for (ll q = 0; q < n; q++) temp += strength[q];
  if (temp%3 != 0){cout << -1; return;}
  target = temp/3;
  ll ans = memo(0, 0, 0);
  if (ans == INT_MAX) {
    cout << -1; return;
  } else {
    cout << ans;
  }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}