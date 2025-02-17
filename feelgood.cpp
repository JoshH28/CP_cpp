// We got too busy just getting older
// I hardly see you anymore
// Both in the city, you should come over
// I'm still at the same place as before
// Tell me all about your life
// Did you finally see the Northern Lights?
// Drunk on seven dollar wine
// So bittersweet
// I know everything has changed
// We're no longer who we used to be
// So take me to the glory days
// And let's hold on tight to nights like these
// We may never feel the same
// Tomorrow this'll be a memory
// So do it for the glory days
// And let's hold on tight to nights like these
// I've had some good times, bet you've got stories
// So much has happened through the years
// Let's make up for lost time, stay up 'til the morning
// We'll still be laughing through our tears
// Tell you all about my life
// I finally grew up, crazy, right?
// Drunk on seven dollar wine
// So bittersweet
// I know everything has changed
// We're no longer who we used to be
// So take me to the glory days
// And let's hold on tight to nights like these
// We may never feel the same
// Tomorrow this'll be a memory
// So do it for the glory days
// And let's hold on tight to nights like these
// To nights like these
// Tell me all about your life
// You finally see the Northern Lights
// We're drunk on seven dollar wine
// Tell you all about my life
// I finally grew up, crazy, right?
// So baby, here's to you and I
// Tell me all about your life
// You finally see the Northern Lights
// We're drunk on seven dollar wine
// Tell you all about my life
// I finally grew up, crazy, right?
// So baby, here's to you and I
// To you and I
// To you and I
// To you and I
// I know everything has changed
// We're no longer who we used to be
// So take me to the glory days
// And let's hold on tight to nights like these
// We may never feel the same
// Tomorrow this'll be a memory
// So do it for the glory days
// And let's hold on tight to nights like these
// To nights like these
// To nights like these
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

string num, upper, lower;
ll lo, hi;

ll dp[21][21][10][2][2];

ll recur(ll cl, ll cnt, ll digit, ll bounded, ll leadzero)
{
    if (cl == num.size()-1)
    {
        if (bounded) return cnt;
        return 0;
    }
    if (dp[cl][cnt][digit][bounded][leadzero] != -1)
    {
        return dp[cl][cnt][digit][bounded][leadzero];
    }
    ll ans = 0;
    if (!leadzero) ans += recur(cl+1, cnt + ll(digit == 0), 0, 1, 0);
    else ans += recur(cl+1, cnt + ll(digit == 0), 0, 1, 1);
    for (ll q = 1; q <= num[cl]; q++) {
        ans += recur(cl+1, cnt + ll(q == digit), digit, 1, 1);
    }
    for (ll q = num[cl]+1; q < 10; q++) {
        ans += recur(cl+1, cnt + ll(q == digit), digit, bounded, 1);
    } 
    return dp[cl][cnt][digit][bounded][leadzero] = ans;
}

void solve()
{
   ll ans[10];
   cin >> lo >> hi; lo--;
   lower = to_string(lo), upper = to_string(hi);
   num = upper;
   memset(dp, -1, sizeof(dp));
   for (ll q = 0; q < 10; q++) {
    ans[q] = recur(0, 0, q, 0, 0);
   }
   num = lower;
   memset(dp, -1, sizeof(dp));
   for (ll q = 0; q < 10; q++) {
    ans[q] -= recur(0, 0, q, 0, 0);
    cout << ans[q] << "\n";
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