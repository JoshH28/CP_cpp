// Drake drake, go away
// Rizz up kids another day
// Daddy says it's not okay
// Drake drake, go away

// Drake drake, go away
// Rizz up kids another day
// Mommy says it’s not okay
// Drake drake, go away

// Drake drake, go away
// Rizz up kids another day
// Skibidi says it's not okay
// Drake drake, go away

// Drake drake, go away
// Rizz up kids another day
// Unc says it's not okay
// Drake drake, go away
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
    pll a[n], b[n], c[n];
    for (ll q = 0; q < n; q++) {
        cin >> a[q].fi >> b[q].fi >> c[q].fi;
        a[q].se = q; b[q].se = q; c[q].se = q;
    }
    sort(a, a+n); reverse(a, a+n);
    sort(b, b+n); reverse(b, b+n);
    sort(c, c+n); reverse(c, c+n);
    ll p1=0, p2=0, p3=0, ans=-1;
    while (true) {
        if (p1 >= n || p2 >= n || p3 >= n) break;
        if (a[p1].se == b[p2].se && b[p2].se == c[p3].se) {
            p1++; p2++; p3++;
        } else if (a[p1].se == b[p2].se && b[p2].se != c[p3].se) {
            p1++; p2++;
        } else if (a[p1].se != b[p2].se && b[p2].se == c[p3].se) {
            p2++; p3++;
        } else if (a[p1].se == c[p3].se && b[p2].se != c[p3].se) {
            p1++; p3++;
        } else {
            ans =  a[p1].fi + b[p2].fi + c[p3].fi; break;
        }
    }
    cout << ans;

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}