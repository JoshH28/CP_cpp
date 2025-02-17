// Saw your favorite band play and they
// Skipped your favorite song
// You were really hungry and he got your order wrong
// Went in for a haircut and you took a risk
// Now you're in the car cryin' 'bout how bad it is
// Yeah, we all have days like this
// Any time you wanna curse
// Just remember it could be worse
// So, don't go cryin' over spilled milk
// And makin' mountains out of molehills
// And when you can't see the sun
// Just remember it'll come up, so don't lose sleep
// Take it from me, it's not that deep
// Oh, it's not that deep
// Finally got your nails done and one of them just broke
// Wanted to watch TV and you lost the remote
// Swore you'd have a good round, hand over your heart
// Now you're in the rough and you're ten strokes over par
// Yeah, some days we fall apart
// But any time you wanna curse
// Just remember it could be worse
// So don't go cryin' over spilled milk
// And makin' mountains out of molehills
// And when you can't see the sun
// Just remember it'll come up, so don't lose sleep
// Take it from me, it's not that deep
// Oh, it's not that deep
// (It's not that deep)
// Any time you wanna curse
// Just remember it could be worse
// So don't go cryin' over spilled milk
// And makin' mountains out of molehills
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
    ll n; string s; cin >> n >> s;
    vector<ll> sum(n + 1, 0); string ans = "";
    for (ll i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + i * ll(s[i - 1] - '0');
    }
    for (ll i = n; i >= 1; i--) {
        ans = char(sum[i] % 10 + '0') + ans;
        sum[i - 1] += sum[i] / 10;
    }
    while (sum[0]) {
        ans = char(sum[0] % 10 + '0') + ans;
        sum[0] /= 10;
    }
    cout << ans << '\n';
}


signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}