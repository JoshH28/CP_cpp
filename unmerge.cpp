// Verse]
// Falling in quickly
// Tell me you feel something too
// Caught in the moment
// I'm lost here without you

// [Pre-Chorus]
// Tangled up in your web (Web)
// Holding on to every word you said
// I'm ready, I know
// I'm hoping it shows (It shows)
// Would you say the same?
// We're falling from outer space

// [Chorus]
// We're moving like a full pace supernova
// We're making all the headlines now
// And I just wanna seize the moment
// 'Cause we won't ever slow it down
// Kissing in the rain
// Taste just like champagne
// Balling everyday
// We're falling from outer space
// Hoping time won't change
// Got love on my brain
// Would you say the same?
// We're falling from outer space
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int, long long int>
#define pq priority_queue
#define gcd(x, y) __gcd(x, y)
#define ALL(x) x.begin(), x.end()
#define pll pair<long long, long long>
#define debug(x) cerr << #x << ':' << x << endl
#define rep(x, start, end)                                                     \
  for (auto x = (start) - ((start) > (end)); x != (end) - ((start) > (end));   \
       ((start) < (end) ? x++ : x--))
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
//#define INT_MAX LONG_LONG_MAX
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset; // upper_bound and lower_bound swap functions in multi
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template <class K, class V>
using ht = gp_hash_table<
    K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>,
    hash_standard_resize_policy<hash_exponential_size_policy<>,
                                hash_load_check_resize_trigger<>, true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace
// doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is
// ht<ll,null_type>, all other operations are same as regular
inline long long readint() {
  long long x = 0;
  char ch = getchar_unlocked();
  while (ch < '0' || ch > '9')
    ch = getchar_unlocked();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar_unlocked();
  }
  return x;
}

ll sn, n;
ll dp[4001][8001];

ll arr[4001];
vector<ll> subsets;

ll recur(ll cn, ll cs) {
  if (cn == sn && cs == 4000) {
    return 1;
  } else if (cn == sn && cs != 4000) {
    return 0;
  }
  if (cs > 8000 || cs < 0) {
    return 0;
  }
  if (dp[cn][cs] != -1) {
    return dp[cn][cs];
  }
  ll ans =
      max(recur(cn + 1, cs + subsets[cn]), recur(cn + 1, cs - subsets[cn]));
  return dp[cn][cs] = ans;
}

void solve() {
  cin >> n;
  ll counter = 1;
  for (ll q = 0; q < 2 * n; q++) {
    cin >> arr[q];
  }
  ll cmax = arr[0];
  for (ll q = 1; q < 2 * n; q++) {
    // cout << cmax << " " << arr[q] << "\n";
    if (cmax < arr[q]) {
      cmax = arr[q];
      subsets.push_back(counter);
      counter = 1;
      // cout << "sus" << "\n";
    } else {
      counter++;
    }
  }
  subsets.push_back(counter);
  sn = subsets.size();
  memset(dp, -1, sizeof(dp));
  ll ans = recur(0, 4000);
  if (ans == 1) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll tc = 1;
  // cin >> tc;
  for (ll q = 0; q < tc; q++) {
    solve();
  }
}