// Oh, it's been heavy
// Life's bringing me down
// I'm a little unsteady
// Heart's beating too loud
// And I keep forgetting
// Things will always turn around
// Should be counting my blessings
// I'm too busy stressing and hiding from all of my doubts
// It's only dark when your eyes are closed
// Tell yourself that you're all alone
// If you never look, then you'll never know
// It's only dark when your eyes are closed
// Only feels like you're far away
// Hanging hopes onto better days
// If you never look, then you'll never know
// It's only dark when your eyеs are closed
// It's only dark when your еyes are closed
// I've been looking for shelter
// But it never feels safe
// Wishing I could remember
// It wasn't always this way
// Bottle up the good times
// And save 'em for a rainy day
// 'Cause when I'm falling to pieces
// There's plenty of reasons for me not to feel so afraid
// It's only dark when your eyes are closed
// Tell yourself that you're all alone
// If you never look, then you'll never know
// It's only dark when your eyes are closed
// Only feels like you're far away
// Hanging hopes onto better days
// If you never look, then you'll never know
// It's only dark when your eyes are closed
// (Oh, oh-oh-oh)
// (It's only dark when your eyes are closed)
// (Oh, oh-oh-oh)
// It's only dark when your eyes are closed
// It's only dark when your eyes are closed
// It's only dark when your eyes are closed
// (Oh, oh-oh-oh)
// (Oh, oh-oh-oh)
// (Only dark when your eyes are closed)
// (Oh, oh-oh-oh)
// (Oh, oh-oh-oh)
// (Only dark when your eyes are closed)
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int, long long int>
#define pq priority_queue
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; // upper_bound and lower_bound swap functions in multi
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template <class K, class V>
using ht = gp_hash_table<K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>, hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<>, true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

const ll MTN = 1e6 + 1;
ll dp[MTN][11];

const ll MOD = 1e9 + 7;

ll mod(ll num)
{
    while (num >= MOD)
    {
        num -= MOD;
    }
    return num;
}

ll recur(ll turnno, ll pn)
{
    if (turnno == 0)
    {
        return 1;
    }
    if (dp[turnno][pn] != -1)
    {
        return dp[turnno][pn];
    }
    ll ans = 0;
    if (pn < 9)
    {
        ans = mod(recur(turnno - 1, pn + 1));
    }
    else
    {
        ans = recur(turnno - 1, 0) + recur(turnno - 1, 1);
        ans = mod(ans);
    }
    ans = mod(ans);
    dp[turnno][pn] = ans;
    return ans;
}

void solve()
{
    string num;
    cin >> num;
    ll turns;
    cin >> turns;
    ll ans = 0;
    for (ll q = 0; q < num.length(); q++)
    {
        ll bruh = num[q] - '0';
        ans += dp[turns][bruh];
        ans = mod(ans);
    }
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    for (ll q = 0; q <= 9; q++)
    {
        ll sus = recur(MTN - 1, q);
    }
    ll tc;
    cin >> tc;
    for (ll q = 0; q < tc; q++)
    {
        solve();
    }
}