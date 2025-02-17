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

ll H, W, D;
vector<vector<char>> S;

bool is_humidified(ll i, ll j, ll i_, ll j_) {return (abs(i - i_) + abs(j - j_)) <= D;}

ll sussy() {
    ll max_humidified = 0;
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            if (S[i][j] == '.') {
                ll humidified = 0;
                for (ll i_ = 0; i_ < H; i_++) {
                    for (ll j_ = 0; j_ < W; j_++) {
                        if (is_humidified(i, j, i_, j_)) humidified++;
                    }
                }
                max_humidified = max(max_humidified, humidified);
            }
        }
    }
    return max_humidified;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> H >> W >> D;
    S.resize(H, vector<char>(W));
    for (int i = 0; i < H; i++) {for (int j = 0; j < W; j++) cin >> S[i][j];}
    cout << sussy();
}