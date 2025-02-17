// You're a world away
// Somewhere in the crowd
// In a foreign place
// Are you happy now?
// There's nothing left to say
// So I shut my mouth
// So won't you tell me, babe
// Are you happy now?

// You're the only one who can up and run
// Leave me just as empty as the day you came
// And you hold all the cards, all the broken hearts
// Strung over your shoulder till it's all in vain

// And only you know the strength of your teeth
// The wash in the weight of your pockets, so deep
// And lonely

// You're a world away
// Somewhere in the crowd
// In a foreign place
// Are you happy now?
// There's nothing left to say
// So I shut my mouth
// So won't you tell me, babe
// Are you happy now?
// Are you happy now?

// You're the only one who can

// In the palm of your hands, you can make me dance
// Spin me around in circles till I'm wrapped in string
// You keep on talking sweet till your fingers bleed
// But don't you dare ask me how I've been

// Now only you know the strength of your teeth
// The wash in the weight of your pockets, so deep
// And lonely

// You're a world away
// Somewhere in the crowd
// In a foreign place
// Are you happy now?
// There's nothing left to say
// So I shut my mouth
// So won't you tell me, babe
// Are you happy now?
// Are you happy now?

// You're the only one who can
// You're the only, you're the only
// You're the only one who can
// You're the only, you're the only

// World away
// Somewhere in the crowd
// In a foreign place
// Are you happy now?
// There's nothing left to say
// So I shut my mouth
// So won't you tell me, babe
// Are you happy now?
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
#define pq priority_queue
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
  ll n; cin >> n;
  ll arr[n], a[n], b[n];
  ld holdArr[n];
  ll lo = 0, hi = INT_MAX;
  ld ans = 0;
  for (ll q = 0; q < n; q++) {cin >> arr[q];}
  for (ll q = 0; q < n; q++) {cin >> a[q]; 
  if (a[q] == 0) continue;
  hi = min(hi, arr[q]/a[q]);
  }
  hi--;
  for (ll q = 0; q < n; q++) {cin >> b[q];}
  ans = hi;
  while(lo <= hi) {
    ll mid = (lo+hi)/2;
    ld currAns = INT_MAX, prevAns = INT_MAX;
    for (ll q = 0; q < n; q++) {
      holdArr[q] = arr[q];
      if (b[q] == 0) continue;
      currAns = min(currAns, ( (ld)arr[q] - mid*(ld)a[q] ) / (ld)b[q] );
      prevAns = min(prevAns, ((ld)arr[q] - (ld)(mid+1)*(ld)a[q]) / (ld)b[q]);
    }
    // ll cmin = INT_MAX;
    // for (ll q = 0; q < n; q++) {
    //   cmin = min(cmin, holdArr[q] / b[q]);
    // }
    // currAns = mid+cmin;
    // ll prevAns = mid+1;
    // for (ll q = 0; q < n; q++) {
    //   holdArr[q] = arr[q];
    //   holdArr[q] -= (prevAns)*a[q];
    // }
    // cmin = INT_MAX;
    // for (ll q = 0; q < n; q++) {
    //   cmin = min(cmin, holdArr[q] / b[q]);
    // }
    //cout << prevAns << " " << currAns << mid << "\n";
    prevAns += (ld)(mid+1); currAns += (ld)(mid);
    
    ans = max({currAns, prevAns, ans});
    //cout << ans << " " << mid << "\n";
	  if (prevAns == currAns) {break;}
    if (currAns < prevAns) {
      lo = mid+1;
    } else {
      hi = mid-1;
    }
  }
  if (ans < 0) ans = 0;
  cout << (ll)ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}