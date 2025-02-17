// It's okay to be
// Not okay sometimes
// Maybe I should, maybe I should
// Take my own advice
// It's okay to feel
// A little broke inside
// Maybe I should, maybe I should
// Take my own advice
// My head's the loudest when it's quiet
// And I'm lying in my bed
// Start to pick apart the pieces
// All the stupid shit I said
// Like did they think that I was funny?
// Are we really even friends?
// I should work more, I should chill out
// Shouldn't be so in my head
// But what would I say
// If I was someone else?
// It's okay to be
// Not okay sometimes
// Maybe I should, maybe I should
// Take my own advice
// It's okay to feel
// A little broke inside
// Maybe I should, maybe I should
// Take my own advice
// 'Cause I would never say the things
// I do to me to someone else
// When my friends ask for a shoulder
// I don't guilt them for the help
// Why's it easier to love them
// Than it is to love myself?
// 'Cause for some reason, when I'm asking
// I think they're overwhelmed
// But what would I say if I could hear myself?
// It's okay to be
// Not okay sometimes
// Maybe I should, maybe I should
// Take my own advice
// It's okay to feel
// A little broke inside
// Maybe I should, maybe I should
// Take my own advice
// Maybe I should, maybe I should
// Take my own advice
// Maybe I should, maybe I should
// Take my own advice
// Maybe I should, maybe I should
// Take my own advice
// Maybe I should, maybe I should
// Take my own advice
// It's okay to be
// Not okay sometimes
// Take my own advice
// It's okay to feel
// A little broke inside
// Take my own advice
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

ll n, l, x, c;
vector<pll> arr;
ll dp[4001];

void solve() {
  cin >> n >> l;  arr.clear();
  for (ll q = 0; q <= l+20; q++) dp[q] = INT_MAX/6;
  for (ll q = 0; q < n; q++) {
    cin >> x >> c; arr.pub({x-c, x+c});
    dp[x-c] = 0;
  }
  for (ll q = 1; q <= l; q++) {
    for (ll w = 0; w < n; w++) {
      if (arr[q].se <= q) continue;
      dp[q] = min(dp[q], q - arr[w].se + dp[arr[w].fi] - (q - arr[q].se));
      cout << q - arr[w].se + dp[arr[w].fi] - (q - arr[q].se) << " ";
    }
    cout << "\n";
  }
  cout << dp[l] << "\n";
  
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1; cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}