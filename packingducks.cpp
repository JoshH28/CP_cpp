// [Verse 1]
// Another night, I can't sleep
// Wishing I could skip to my dreams
// 'Cause the same day's stuck on repeat (Oh)

// [Pre-Chorus]
// I push away from the edge
// Push away all my friends
// I should reach out instead
// But I can't right now
// No, I can't right now

// [Chorus]
// I've been lost in my head
// Over something I said
// All these feelings got me down
// In the deep end
// Trying not to pretend
// I'm not losing it again
// When nothing's even wrong
// There's no reason

// [Post-Chorus]
// To take it this far, 'til I'm falling apart
// Maybe I'll feel better in the morning
// Am I making this up?
// Did I fall or did I jump?
// Could you pull me out of the deep end?

// [Drop]
// (Ooh, ooh)
// Could you pull me out of the deep end?
// (Ooh, ooh)
// Could you pull me out of the deep end?

// [Verse 2]
// Been holding back all my tears
// While I've been trying to face my fears
// Wondering how I keep on finding myself here (Oh)

// [Pre-Chorus]
// I push away from the edge
// Push away all my friends
// I should reach out instead
// But I can't right now
// No, I can't right now

// [Chorus]
// I've been lost in my head
// Over something I said
// All these feelings got me down
// In the deep end
// Trying not to pretend
// I'm not losing it again
// When nothing's even wrong
// There's no reason
// [Post-Chorus]
// To take it this far, 'til I'm falling apart
// Maybe I'll feel better in the morning
// Am I making this up?
// Did I fall or did I jump?
// Could you pull me out of the deep end?

// [Drop]
// (Ooh, ooh)
// Could you pull me out of the deep end?
// (Ooh, ooh)
// Could you pull me out of the deep end?

// [Outro]
// I've been lost in my head
// Over something I said
// Could you pull me out of the deep end?
// Trying not to pretend
// I'm not losing it again
// Could you pull me out of the deep end?
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

ll n, mw;
ll dp[201][50001];
ll weights[201];
const ll mod = 1000000007;

ll recur(ll ci, ll cw)
{
    if (ci == n)
    {
        return 1;
    }
    if (dp[ci][cw] != -1)
    {
        return dp[ci][cw];
    }
    ll ans = 0;
    if (cw + weights[ci] <= mw)
    {
        ans = recur(ci + 1, cw + weights[ci]) % mod;
    }
    ans += (recur(ci + 1, cw) % mod);
    ans %= mod;
    return dp[ci][cw] = ans;
}

void solve()
{
    cin >> n >> mw;
    memset(dp, -1, sizeof(dp));
    for (ll q = 0; q < n; q++)
    {
        cin >> weights[q];
    }
    ll ans = recur(0, 0);
    cout << ans % mod;
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