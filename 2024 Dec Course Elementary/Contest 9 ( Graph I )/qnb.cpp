// Gyatt, I was in Ohio before I met you
// I rizzed too much and that's an issue, but I'm Grimace Shake
// Gyatt, tell your friends it was nice to rizz them
// But I hope I never edge again
// I know it breaks your Fanum
// Taxin' in Ohio and I'm still not sigma
// Four years, no Livvy
// Now you're looking pretty on Adin Ross's Twitchy
// And I-I-I-I-I can't rizz
// No, I-I-I-I-I can't mew
// So Baby-Gronk me closer
// In the back Skibidi Toilet
// That I know you can't afford
// Kai Cenat tatted on my shoulder
// Pull the gyatt right off the corner
// From that Fanum that you taxed
// From your roommate back in Ohio
// We ain't ever not the rizzler
// We ain't ever not the rizzlеr
// We ain't ever not thе rizzler
// You rizz as good as the day I met you
// I forget just why I edged you, I was insane
// Slay and play that Blink-180-Mew song
// That we gooned to death in Ohio, okay
// I know you love this gyatt
// I moved to Ohio in a brainrot car and
// Four years, no griddy
// Now I'm lookin' Livvy and you're not skibidi
// And I-I-I-I-I can't rizz
// No, I-I-I-I-I can't mew
// So Baby-Gronk me closer
// In the back Skibidi Toilet
// That I know you can't afford
// Kai Cenat tatted on my shoulder
// Pull the gyatt right off the corner
// From that fanum that you taxed
// From your roommate back in Ohio
// We ain't ever not the rizzler
// We ain't ever not the rizzler
// We ain't ever not the rizzler
// So Baby-Gronk me closer
// In the back Skibidi Toilet
// That I know you can't afford
// Kai Cenat tatted on my shoulder
// Pull the gyatt right off the corner
// From that fanum that you taxed
// From your roommate back in Ohio
// We ain't ever not the rizzler
// We ain't ever not the rizzler
// Oh, we ain't ever not the rizzler
// We ain't ever not the rizzler
// Oh, we ain't ever not the rizzler
// We ain't ever not the rizzler
// Oh, we ain't ever not the rizzler
// We ain't ever not the rizzler
// Oh, we ain't ever not the rizzler ('Er)
// We ain't ever not the rizzler ('Er)
// No, we ain't ever not the rizzler
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int, long long int>
#define gcd(x, y) __gcd(x, y)
#define ALL(x) x.begin(), x.end()
#define pll pair<long long, long long>
#define debug(x) cerr << #x << ':' << x << endl
#define rep(x, start, end) for (auto x = (start) - ((start) > (end)); x != (end) - ((start) > (end)); ((start) < (end) ? x++ : x--))
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; // upper_bound and lower_bound swap functions in multi
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template <class K, class V>
using ht = gp_hash_table<K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>, hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<>, true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; // to do 4dir skip every odd index
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; // to do 4dir skip every odd index

ll r, c, a, b, qn, cnt=0; char gay;
char grid[2001][2001];

void ffill(ll h, ll w) {
    char ch = grid[h][w];
    if (ch == '.') return;
    if (ch == '?') {cnt++; grid[h][w] = '.';}
    else if (ch == 'U' && grid[h-1][w] == '.') {cnt++; grid[h][w] = '.'; }
    else if (ch == 'D' && grid[h+1][w] == '.') {cnt++; grid[h][w] = '.'; }
    else if (ch == 'L' && grid[h][w-1] == '.') {cnt++; grid[h][w] = '.'; }
    else if (ch == 'R' && grid[h][w+1] == '.') {cnt++; grid[h][w] = '.'; }
    else return;
    if (h > 0) ffill(h-1, w);
    if (h <= r) ffill(h+1, w);
    if (w > 0) ffill(h, w-1);
    if (w <= c) ffill(h, w+1);
}

void solve() {
    ll n, qn; cin >> n >> qn;
    r = n; c = n;
    stack<pair<pll, char>> arr;
    stack<ll> ans;
    for (ll q = 0; q < n+2; q++) {
        for (ll w = 0; w < n+2; w++) {
            grid[q][w] = '?';
        }
    }
    for (ll q = 0; q < qn; q++) {
        cin >> a >> b >> gay;
        grid[a][b] = gay;
        arr.push({{a, b}, gay});
    }
    ffill(0, 0);
    ll total = (r+2)*(c+2);
    while (!arr.empty()) {
        ans.push(total-cnt);
        ll a = arr.top().fi.fi, b = arr.top().fi.se;
        arr.pop();
        if (grid[a][b] != '.') {
            grid[a][b] = '?';
            if (grid[a-1][b] == '.') ffill(a, b);
            else if (grid[a+1][b] == '.') ffill(a, b);
            else if (grid[a][b+1] == '.') ffill(a, b);
            else if (grid[a][b-1] == '.') ffill(a, b);
        }
    }
    while (ans.size()) {
        cout << ans.top() << "\n"; ans.pop();
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll q = 0; q < tc; q++)
    {
        solve();
    }
}

//editorial at https://www.youtube.com/watch?v=I01gyUvu19o&ab_channel=AlphaStarUSACOTraining