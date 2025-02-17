/*
I'm in the thick of it, everybody knows
They know me where it snows, I skied in and they froze
I don't know no nothin' 'bout no ice, I'm just cold
Forty somethin' milli' subs or so, I've been told
...previous lyrics remain the same...
*/
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;

void solve() {
    ll n,m; 
    cin >> n >> m; 
    vector<ll> arr(n), sushi(m);  
    vector<ll> binsearch; 
    unordered_map<ll, ll> mp;
    for (ll q = 0; q < n; q++) {
        cin >> arr[q];
        if (binsearch.empty() || -binsearch.back() > arr[q]) {
          binsearch.push_back(-arr[q]);  mp[-arr[q]] = q+1;
        }
    }
    for (ll q = 0; q < m; q++) {
        cin >> sushi[q];
        auto indeed = upper_bound(binsearch.begin(), binsearch.end(), -sushi[q]) - binsearch.begin();
        if (indeed >= 1) {
          indeed--;
          if (-binsearch[indeed] != sushi[q]) indeed++;
        }
        //cout << indeed << ' ';
        if (indeed >= binsearch.size()) {
            cout << -1 << "\n";
        } else {
            cout << mp[binsearch[indeed]] << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc=1;
    for (ll q = 0; q < tc; q++) {
        solve();
    }
    return 0;
}