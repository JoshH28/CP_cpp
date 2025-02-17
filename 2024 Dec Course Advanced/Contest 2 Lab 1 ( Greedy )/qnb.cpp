// # Another hour just slipped away
// # It's hard to tell you when I haven't all this time
// # Maybe if I wear it on my face
// # Someone else will let you know I'm not all right

// # With nothing to lose
// # But all this to drink
// # I'm drowning in you
// # I can't help but think

// # What if?
// # What if I didn't know
// # Letting you let me go
// # Would leave me here all alone
// # Missing you?

// # And what if I didn't run
// # The second our second chance wasn't gone?
// # What if you were the one?
// # What if I wasn't done loving you?

// # I wonder if you ever feel the same
// # Intimidated by the way you seem just fine
// # I know I told you it'd be better this way

// # I didn't know that it would it hurt me like that
// # Should've known that it'd be hard to go back

// # With nothing to lose
// # But all this to drink
// # I'm drowning in you
// # I can't help but think

// # What if?
// # What if I didn't know
// # Letting you let me go
// # Would leave me here all alone
// # (Leave me alone)
// # Missing you?

// # And what if I didn't run
// # (Didn't run)
// # The second our second chance wasn't gone
// # (Wasn't gone)
// # What if you were the one?
// # What if I wasn't done loving you?

// # Loving you
// # Loving you
// # Loving you
// # What if I wasn't done loving you?
// # What if I wasn't done loving you?

// # And maybe I should have known
// # Letting you let me go
// # Would leave me here all alone missing you

// # And what if I didn't run
// # The second our second chance wasn't gone?
// # What if you were the one? 
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

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll max_product = LLONG_MIN; 
    ll current_max = 1, current_min = 1;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) {
            current_max = 1;
            current_min = 1;
            max_product = max(max_product, 0LL); 
        } else {
            ll temp = current_max; 
            current_max = max({a[i], current_max * a[i], current_min * a[i]});
            current_min = min({a[i], temp * a[i], current_min * a[i]});
            max_product = max(max_product, current_max);
        }
    }
    cout << max_product << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}

