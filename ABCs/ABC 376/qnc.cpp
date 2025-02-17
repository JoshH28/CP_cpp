// [Verse 1]
// Baby, heard you've been talking about me lately
// Telling all your friends how much you hate me
// But who you calling up when you get lonely?
// When you get lonely, yeah

// [Pre-Chorus]
// You be saying real, real nice, real nice things
// When I'm touching you
// You be getting real, real, real, real, real jealous
// When it wasn't you, oh
// And every now when my iPhone, iPhone rings (Brr, brr)
// I be telling you
// I told you, I told you, I told you

// [Chorus]
// You said it was over, you said it was over
// But your clothes say different on my bedroom floor
// You said it was over, you said it was over
// But your clothes say different on my bedroom floor
// But your clothes say different on my bedroom floor
// But your clothes say different on my bedroom floor, yeah

// [Verse 2]
// Baby, why you always act like you don't want me?
// Don't make me bring up your dirty laundry
// We always on and off until you're on me
// Until you're on me, yeah

// [Pre-Chorus]
// You be saying real, real nice, real nice things
// When I'm touching you
// You be getting real, real, real, real, real jealous
// When it wasn't you, oh
// And every now when my iPhone, iPhone rings (Brr, brr)
// I be telling you
// I told you, I told you, I told you

// [Chorus]
// You said it was over, you said it was over
// But your clothes say different on my bedroom floor
// You said it was over, you said it was over
// But your clothes say different on my bedroom floor
// But your clothes say different on my bedroom floor
// But your clothes say different on my bedroom floor, yeah
// You said it was over, you said it was over
// But your clothes say different on my bedroom floor
// But your clothes say different on my bedroom floor, yeah

// [Bridge]
// Oh, my bedroom floor
// Your clothes are saying something different now
// You wanna break up just to fix it now
// Oh, baby
// [Chorus]
// You said it was over, you said it was over
// But your clothes say different on my bedroom floor
// You said it was over (It's over), you said it was over (It's over)
// But your clothes say different on my bedroom floor (Ooh)
// But your clothes say different on my bedroom floor
// But your clothes say different on my bedroom floor, yeah (Yeah)
// You said it was over (It's over), you said it was over (It's over)
// But your clothes say different on my bedroom floor
// But your clothes say different on my bedroom floor, yeah
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
  ll n; cin >> n;
  ll toys[n], boxes[n-1];
  for (ll q = 0; q < n; q++) cin >> toys[q];
  for (ll q = 0; q < n-1; q++) cin >> boxes[q];
  sort(toys, toys+n); sort(boxes, boxes+n-1);
  reverse(toys, toys+n); reverse(boxes, boxes+n-1);
  ll ans = -2, cnt = 0;
  for (ll q = 0; q < n; q++) {
    if (cnt < n-1 && boxes[cnt] >= toys[q]) cnt++;
    else {
      if (ans == -2) ans = toys[q];
      else {
        ans = -1;break;
      }
    }
  }
  if (ans == -2) ans = -1;  
  cout << ans << '\n';  
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}