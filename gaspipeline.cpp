// 2AM and I'm still breathing
// Staring at my thoughts floating up to the ceiling
// I'm swimming in everything you said
// I'm thinking 'bout jumping in instead
// I've got you skinny dipping deep inside my head

// It's in the way you see
// You know what I need
// It's in the way that you're holding me, bringing me close
// You know that I won't let go
// You've got me on repeat (repeat)
// You've got me in a dream (a dream)
// I let my worries go soon as you come through the door
// Thinking 'bout what it'd be like to be yours

// Every time you move
// You’re looking like you’re dancing
// I think that you could have it
// (Ooh-ooh)
// Everything you do
// I want to do it with you
// Don't ever want to miss you
// You might also like

// Woah, oh
// You do, you do, you do
// You do, you do, you do, you do

// It's in the way you touch me
// I don't know much about love
// But I'll keep on checking my phone to see when you're home
// Or when you want me to pull up (ah)
// We're one in the same
// You got me caught in a daze (oh, no)
// I love it when you say my name real slow
// All my love is yours

// I'm swimming in everything you said
// I'm thinking 'bout jumping in instead
// I've got you skinny dipping deep inside my head
// (Inside my head)

// Every time you move
// You’re looking like you’re dancing (dancing)
// I think that you could have it (you can)
// (Ooh-ooh)
// Everything you do
// I want to do it with you (with you)
// Don't ever want to miss you

// Woah, oh
// You do, you do, you do
// You do, you do, you do, you do

// [Outro: Alina Baraz]
// 2am, and I'm still breathing
// Staring at my thoughts floating up to the ceiling
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

ll n, a, b; const ll MAXN = 2e5+10;
ll arr[MAXN], dp[MAXN][5];

ll memo(ll idx, ll currheight) {
  if (idx == n) {
    if (currheight != 1) return INT_MAX/5;
    return 0;
  }
  if (dp[idx][currheight] != -1) return dp[idx][currheight];
  ll ans = INT_MAX;
  if (arr[idx] == 1) {
    if (currheight == 1) {ans = INT_MAX/5;}
    else ans = min(ans, memo(idx+1, 2) + a + 2*b);
  } else {
    if (currheight == 2) {
      ans = min({ans, memo(idx+1, 2) + a + b*2, memo(idx+1, 1) + a*2 + b});
    } else {
      ans = min({ans, memo(idx+1, 1) + a + b, memo(idx+1, 2) + a*2 + b*2});
    }
  }
  return dp[idx][currheight] = ans;
}

void solve() {
  char c; cin >> n >> a >> b; memset(dp, -1, sizeof(dp));
  for (ll q = 0; q < n; q++) {
    cin >> c; arr[q] = ll(c -'0');
  }
  cout << memo(0, 1)+b << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}