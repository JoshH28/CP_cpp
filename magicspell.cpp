// [Verse 1]
// You said, "Don't look back and don't look down"
// But here I am, replaying every sound and second since you found me

// [Pre-Chorus]
// All packed up, headed out
// I hate to say I need you now
// Here I am, turn around
// One more time, I need you now

// [Chorus]
// Oh, said that I'd be fine without you
// It's not true
// I move, but can't move on without you
// I'm looking back, looking down
// Hate to say I need you now, ooh
// Said that I'd be fine without you

// [Drop]
// Ooh
// Looking down—You now
// Ooh
// (I'd be fine without you)
// Ooh
// Looking down—You now
// Ooh
// (I'd be fine without you)
// Ooh
// Looking down—You now
// Ooh
// (I'd be fine without you)
// Ooh
// Looking down—You now
// Ooh
// (I'd be fine without you)

// [Verse 2]
// Making sure you're safe and sound
// How your voice sang the songs that make me wanna live forevеr

// [Pre-Chorus]
// All packed up, headed out
// I hatе to say I need you now
// Here I am, turn around
// One more time, I need you now

// [Chorus]
// Oh, said that I'd be fine without you
// It's not true
// I move, but can't move on without you
// I'm looking back, looking down
// Hate to say I need you now, ooh
// Said that I'd be fine without you

// [Drop]
// Ooh
// Looking down—You now
// Ooh
// (I'd be fine without you)
// Ooh
// Looking down—You now
// Ooh
// (I'd be fine without you)
// [Outro]
// I'm looking back, looking down
// Hate to say I need you now, ooh
// Said that I'd be fine without you
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
    ll n, small;
    cin >> n >> small;
    ll psum[n + 1], arr[n + 1];
    psum[0] = 0;
    for (ll q = 1; q <= n; q++)
    {
        cin >> arr[q];
        psum[q] = arr[q] + psum[q - 1];
    }
    ll lo = 0, hi = n + 1;
    ll ans = INT_MAX;
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        ll lss = INT_MAX; // stores the largest sum of consequtive segments of length mid
        for (ll q = 1; q <= n - mid + 1; q++)
        {
            ll curr = (psum[q + mid - 1] - psum[q - 1]) / 2 + (psum[q - 1] - psum[0]) + (psum[n] - psum[q + mid - 1]);
            lss = min(lss, curr);
        }
        if (small >= lss)
        { // this value of L can, try for smaller L
            hi = mid;
            ans = min(ans, mid);
        }
        else
        {
            lo = mid + 1;
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