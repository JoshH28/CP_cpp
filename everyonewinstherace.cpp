// I've been reading books of old
// The legends and the myths
// Achilles and his gold
// Hercules and his gifts
// Spider-Man's control
// And Batman with his fists
// And clearly I don't see myself upon that list
// But she said, where'd you wanna go?
// How much you wanna risk?
// I'm not lookin' for somebody
// With some superhuman gifts
// Some superhero
// Some fairy-tale bliss
// Just something I can turn to
// Somebody I can kiss
// I want something just like this
// Doo-doo-doo, doo-doo-doo
// Doo-doo-doo, doo-doo
// Doo-doo-doo, doo-doo-doo
// Oh, I want something just like this
// Doo-doo-doo, doo-doo-doo
// Doo-doo-doo, doo-doo
// Doo-doo-doo, doo-doo-doo
// Oh, I want something just like this
// I want something just like this
// I've been reading books of old
// The legends and the myths
// The testaments they told
// The moon and its eclipse
// And Superman unrolls
// A suit before he lifts
// But I'm not the kind of person that it fits
// She said, where'd you wanna go?
// How much you wanna risk?
// I'm not lookin' for somebody
// With some superhuman gifts
// Some superhero
// Some fairy-tale bliss
// Just something I can turn to
// Somebody I can miss
// I want something just like this
// I want something just like this
// Oh, I want something just like this
// Doo-doo-doo, doo-doo-doo
// Doo-doo-doo, doo-doo
// Doo-doo-doo, doo-doo-doo
// Oh, I want something just like this
// Doo-doo-doo, doo-doo-doo
// Doo-doo-doo, doo-doo
// Doo-doo-doo, doo-doo-doo
// Where'd you wanna go?
// How much you wanna risk?
// I'm not lookin' for somebody
// With some superhuman gifts
// Some superhero
// Some fairy-tale bliss
// Just something I can turn to
// Somebody I can kiss
// I want something just like this
// Oh, I want something just like this
// Oh, I want something just like this
// Oh, I want something just like this
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
  ll n, time; cin >> n >> time;
  ll speeds[n]; ll positions[n]; ll startTime[n];
  for (ll q = 0; q < n; q++) {cin >> speeds[q];}
  for (ll q = 0; q < n; q++) {cin >> positions[q];}
  for (ll q = 0; q < n; q++) {cin >> startTime[q];}
  ll lo = 0, hi = 1e9, best = 0;
  while(lo <= hi) {
    ll mid = (lo+hi)/2; // this is the current position of end line we are trying
    //cout << mid << "\n";
    sort(speeds, speeds+n);
    ld lol[n];
    for (ll q = 0; q < n; q++) {
      ld distToRun = mid - positions[q];
      if (distToRun <= 0) {lol[q] = 0; continue;}
      ld minSpeed = (distToRun / ( time - startTime[q]));
      lol[q] = minSpeed;
    }
    sort(lol, lol+n);
    ll flag = 0;
    for (ll q = 0; q < n; q++) {
      if (lol[q] > (ld)speeds[q]) {flag = 1; break;}
      //cout << pq.top() << " " << speeds[q] << "\n";
    }
    if (flag) {// cant do this ending position, go lower
      hi = mid-1;
    } else {
      lo = mid+1;
      best = max(mid, best);
    }
    //cout << "\n";
  }
  cout << best;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}