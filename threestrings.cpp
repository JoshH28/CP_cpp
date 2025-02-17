// I think we're over-bored
// Fighting in the backseat, saying things we don't mean
// We can't keep score no more
// Write our names in concrete, drunk at after-parties
// I turned my hotel room
// Into a garden, into a garden
// Flying to France, Toulouse
// I was too honest, a little too honest
// 21 when I told her love's like an atom bomb
// Pressing down on your shoulders
// Put my thoughts in a folder, bury them 'til I'm dead and gone
// Don't read them out, they're way too dumb
// Lost myself intoxicated
// Everybody wants to be somebody but nobody's there for you
// Guess I-I, love you and I hate it
// If you loved me then why would you leave? I'm stuck, all I see is you
// Slow dancing on your bed
// Kissing you to Coldplay, love me in the same way
// I've pictured in my head
// Take me into your place, throw me out the same day
// I turned my hotel room
// Into a garden, into a garden
// Flying to France, Toulouse
// I was too honest, a little too honest
// 21 when I told her love's like an atom bomb
// Pressing down on your shoulders
// Put my thoughts in a folder, bury them 'til I'm dead and gone
// Don't read them out, they're way too dumb
// Lost myself intoxicated
// Everybody wants to be somebody but nobody's there for you
// Guess I-I, love you and I hate it
// If you loved me then why would you leave? I'm stuck, all I see is you
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
    string a, b, c;
    cin >> a >> b >> c;
    ll n = a.length(), m = b.length();
    ll dp[n + 1][m + 1];
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= m; j++) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= m; j++) {
            if (i < n) {
                int cost = (a[i] == c[i + j]) ? 0 : 1;
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost);
            }
            if (j < m) {
                int cost = (b[j] == c[i + j]) ? 0 : 1;
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + cost);
            }
        }
    }
    cout << dp[n][m] << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}
