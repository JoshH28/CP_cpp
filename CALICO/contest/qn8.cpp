// Monday left me broken
// Tuesday I was through with hopin'
// Wednesday my empty arms were open
// Thursday waiting for love, waiting for love
// Thank the stars it's Friday
// I'm burning like a fire gone wild on Saturday
// Guess I won't be coming to church on Sunday
// I'll be waiting for love
// Waiting for love to come around
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

struct State {
    int packed, moves;
    State(int x, int y, bool can_dash, int moves) : 
        moves(moves) {
        packed = (x << 17) | (y << 1) | can_dash;
    }
    int x() const { return packed >> 17; }
    int y() const { return (packed >> 1) & 0xFFFF; }
    bool can_dash() const { return packed & 1; }
};

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    vector<vector<uint8_t>> visited(n, vector<uint8_t>(m, 0));
    int start_x = -1, start_y = -1, end_x = -1, end_y = -1;
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        if(start_x == -1 || end_x == -1) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'S') {
                    start_x = i, start_y = j;
                } else if(grid[i][j] == 'E') {
                    end_x = i, end_y = j;
                }
            }
        }
    }
    queue<State> q;
    q.push(State(start_x, start_y, true, 0));
    visited[start_x][start_y] |= 2; 
    while(!q.empty()) {
        State curr = q.front(); q.pop();
        int cx = curr.x(), cy = curr.y();
        if(cx == end_x && cy == end_y) {
            return curr.moves;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir], ny = cy + dy[dir];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                bool new_can_dash = curr.can_dash() || grid[nx][ny] == '*';
                int visit_bit = new_can_dash ? 2 : 1;
                
                if(!(visited[nx][ny] & visit_bit)) {
                    visited[nx][ny] |= visit_bit;
                    q.push(State(nx, ny, new_can_dash, curr.moves + 1));
                }
            }
        }
        if(curr.can_dash()) {
            for(int dir = 0; dir < 4; dir++) {
                int nx = cx, ny = cy;
                bool found_crystal = false;
                for(int step = 0; step < k; step++) {
                    int next_x = nx + dx[dir];
                    int next_y = ny + dy[dir];
                    if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m || grid[next_x][next_y] == '#')
                        break;
                    nx = next_x;
                    ny = next_y;
                    found_crystal |= (grid[nx][ny] == '*');
                }
                
                if(nx != cx || ny != cy) {
                    int visit_bit = found_crystal ? 2 : 1;
                    if(!(visited[nx][ny] & visit_bit)) {
                        visited[nx][ny] |= visit_bit;
                        q.push(State(nx, ny, found_crystal, curr.moves + 1));
                    }
                }
            }
        }
    }
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        cout << solve() << '\n';
    }
    return 0;
}