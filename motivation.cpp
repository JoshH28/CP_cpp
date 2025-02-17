// [Verse 1]
// I can always tell when you're lonely
// When your voice gets sweeter when you want me
// It's so obvious that I want you too
// It's like I feel it worse when I'm sleepin'
// In a strange place with you when I'm dreamin'
// Wishin' I could wake up and be next to you

// [Pre-Chorus]
// When the phone calls ain't enough to get through this
// When you need to feel my love

// [Chorus]
// You can pack up a suitcase
// And hop on an airplane
// Whenever your sunshine turns to rain
// When you're feelin' homesick
// You know where my heart is
// I'm only a thousand miles away (Away)

// [Post-Chorus]
// (Homesick, homеsick, homesick)
// (Homesick, homesick, homesick)
// (Thousand miles away)
// (Homesick, homesick)

// [Chorus]
// You can pack up a suitcase
// And hop on an airplane
// Whenever your sunshine turns to rain
// When you're feelin' homesick
// You know where my heart is
// I'm only a thousand, thousand, thousand miles away

// [Drop]

// [Verse 2]
// We can find a way through the distance
// Make it work, let's speak it to existence
// While we both look up into a diamond sky
// So hard to keep all of the pieces
// So easy to forget the reasons
// But you and me are worth it all (You and me are worth it all)

// [Pre-Chorus]
// When the phone calls ain't enough to get through this
// When you need to feel my love

// [Chorus]
// You can pack up a suitcase
// And hop on an airplane
// Whenever your sunshine turns to rain
// When you're feelin' homesick
// You know where my heart is
// I'm only a thousand miles away (Miles away)

// [Post-Chorus]
// Home, home
// Home, home
// Home, home
// I'm only a thousand miles away

// [Chorus]
// You can pack up a suitcase
// And hop on an airplane
// Whenever your sunshine turns to rain
// When you're feelin' homesick
// You know where my heart is
// I'm only a thousand, thousand, thousand miles away

// [Drop]

// [Outro]
// Home, home
// Home, home
// Home, home
// I'm only a thousand miles away (Away)
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

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ll arr[n], exams[n];
    for (ll q = 0; q < n; q++)
    {
        cin >> arr[q];
        ans += arr[q];
    }
    for (ll q = 0; q < n; q++)
    {
        cin >> exams[q];
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll q = 0; q < n; q++)
    {
        pq.push(arr[q]);
        if (exams[q])
        {
            ans -= pq.top();
            pq.pop();
        }
    }
    cout << ans;
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