#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
#define gcd(x,y) __gcd(x, y)
#define ALL(x) x.begin(),x.end()
#define pll pair<long long,long long>
#define debug(x) cerr<<#x<<':'<<x<<endl
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--)
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
    ll h, w, d;
    cin >> h >> w >> d;
    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<bool>> vis(h, vector<bool>(w, false));

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    ll dx[4] = {1, -1, 0, 0};
    ll dy[4] = {0, 0, 1, -1};
    queue<pair<pair<ll, ll>, ll>> bfs;

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            if (grid[i][j] == 'H') {
                bfs.push({{i, j}, 0});
                vis[i][j] = true; 
            }
        }
    }

    ll ans = 0;

    while (!bfs.empty()) {
        auto [pos, dist] = bfs.front();
        ll x = pos.first, y = pos.second;
        bfs.pop();
        ans++;
        if (dist == d) continue; 

        for (ll k = 0; k < 4; k++) {
            ll nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (!vis[nx][ny] && grid[nx][ny] != '#') {
                    vis[nx][ny] = true;
                    bfs.push({{nx, ny}, dist + 1});
                }
            }
        }
    }

    cout << ans << '\n';
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
