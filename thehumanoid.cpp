// Feelin' my way through the darkness
// Guided by a beatin' heart
// I can't tell where the journey will end
// But I know where to start
// They tell me I'm too young to understand
// They say I'm caught up in a dream
// Well, life will pass me by if I don't open up my eyes
// Well, that's fine by me

// So wake me up when it's all over
// When I'm wiser and I'm older
// All this time, I was findin' myself and I
// Didn't know I was lost
// So wake me up when it's all over
// When I'm wiser and I'm older
// All this time, I was findin' myself and I
// Didn't know I was lost

// I tried carryin' the weight of the world
// But I only have two hands
// Hope I get the chance to travel the world
// But I don't have any plans
// Wish that I could stay forever this young
// Not afraid to close my eyes
// Life's a game made for everyone
// And love is the prize

// So wake me up when it's all over
// When I'm wiser and I'm older
// All this time, I was findin' myself and I
// Didn't know I was lost
// So wake me up when it's all over
// When I'm wiser and I'm older
// All this time, I was findin' myself and I
// I didn't know I was lost

// I didn't know I was lost
// I didn't know I was lost
// I didn't know I was lost
// I didn't know, I didn't know, I didn't know
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
  ll power, n; cin >> n >> power; ll arr[n+10], dp[n+10][10][10];
  for (ll q = 1; q <= n; q++) {cin >> arr[q];} ll ans = 0;
  sort(arr+1, arr+n+1); memset(dp, -1, sizeof(dp)); dp[0][2][1] = power; 
  for (ll q = 0; q < n; q++) {
    for (ll w = 0; w <= 2; w++) {
      for (ll s = 0; s <= 1; s++) {
        if (dp[q][w][s] == -1) continue;
        if (arr[q+1] < dp[q][w][s]) dp[q+1][w][s] = max(dp[q+1][w][s], dp[q][w][s] + arr[q+1] / 2);
        if (w >= 1 && dp[q][w][s]*2 > arr[q+1]) dp[q+1][w-1][s] = max(dp[q+1][w-1][s], dp[q][w][s]*2 + arr[q+1]/2);
        if (s >= 1 && dp[q][w][s]*3 > arr[q+1]) dp[q+1][w][s-1] = max(dp[q+1][w][s-1], dp[q][w][s]*3 + arr[q+1]/2);
        if (s >= 1 && w>= 1 && dp[q][w][s]*6 > arr[q+1]) dp[q+1][w-1][s-1] = max(dp[q+1][w-1][s-1], dp[q][w][s]*6 + arr[q+1]/2);
        if (s >= 1 && w >= 2 && dp[q][w][s]*12 > arr[q+1]) dp[q+1][w-2][s-1] = max(dp[q+1][w-2][s-1], dp[q][w][s]*12 + arr[q+1]/2);
        if (w >= 2 && dp[q][w][s]*4 > arr[q+1]) dp[q+1][w-2][s] = max(dp[q+1][w-2][s], dp[q][w][s]*4 + arr[q+1]/2);
      }
    }
  }
  for (ll q = 0; q <= n; q++) {
    for (ll w = 0; w <= 2; w++) {
      for (ll r = 0; r <= 1; r++) {
        //cout << dp[q][w][r] << " ";
        if (dp[q][w][r] > -1) ans = max(ans, q);
      }
      //cout << "\n";
    }
    //cout << "\n";
  }
  cout << ans << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}