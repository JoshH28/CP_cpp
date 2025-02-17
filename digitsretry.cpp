// [Verse 1]
// Wonder what it's gonna take
// To fix this feeling
// Too many hours in a day
// Wasted on daydreams
// Of somebody that I can lean on
// Holds me up when I don't feel strong
// I got a lot of empty space
// Savin' it for something

// [Pre-Chorus]
// But each night, I'm on my own
// I'm closer to a breakdown
// Tell me, 'cause I don’t know
// And I'm tired of being let down

// [Chorus]
// My heart is getting heavy from hoping
// And it's got a lot of battle scars
// I kinda wish somebody had told me
// That this was gonna be so hard
// And maybe I was made to be lonely
// 'Cause I'm standing here with open arms
// Oh, I just want somebody to hold me
// When I'm falling apart

// [Post-Chorus]
// When I'm falling apart
// When I'm falling apart

// [Drop]
// When I'm falling apart
// When I'm falling apart
// When I'm falling apart

// [Verse 2]
// All the shadows that I hide
// Wish that I could show them
// Could you bring a little light
// And see where I've been broken?
// Not lookin' for you to fix me
// Just want someone to do this with me
// Tired of keeping it inside
// All these words unspoken

// [Pre-Chorus]
// But each night, I'm on my own
// I'm closer to a breakdown
// Tell me, 'cause I don’t know
// And I'm tired of being let down

// [Chorus]
// My heart is getting heavy from hoping
// And it's got a lot of battle scars
// I kinda wish somebody had told me
// That this was gonna be so hard
// And maybe I was made to be lonely
// 'Cause I'm standing here with open arms
// Oh, I just want somebody to hold me
// When I'm falling apart
// [Post-Chorus]
// (When I'm falling, when I'm falling)
// Apart, apart
// When I'm falling apart

// [Drop]
// (When I'm falling, when I'm falling)
// Apart
// When I'm falling apart
// (When I'm falling, when I'm falling)
// When I'm falling apart

// [Outro]
// (When I'm falling apart)
// (When I'm falling apart)
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

ll n, mod, qn, c1, c2, c3;
string num;
ll powers[200001];

void powerComputation()
{
    powers[0] = 1;
    for (ll q = 1; q < 200001; q++)
    {
        powers[q] = 10 * powers[q - 1] % mod;
        powers[q] %= mod;
    }
}

struct node
{
    ll start, end, mid, value;
    node *r, *l; // initialising the left and right nodes of this level
    node(ll __start, ll __end)
    {
        start = __start;
        end = __end;
        mid = (start + end) / 2;
        value = 0;
        if (start != end)
        {
            l = new node(start, mid);
            r = new node(mid + 1, end);
        }
    }
    void pointUpdate(ll nodePos, ll newVal)
    {
        if (start == end)
        {
            value = newVal;
            return;
        }
        if (nodePos <= mid)
        {
            l->pointUpdate(nodePos, newVal);
        }
        else
        {
            r->pointUpdate(nodePos, newVal);
        }
        ll bruh = r->end - r->start + 1;
        ll why = powers[bruh];
        value = (l->value * why) % mod + (r->value) % mod;
        value %= mod;
    }

    ll rangeQuery(ll left, ll right)
    {
        if (left == start && right == end)
        {
            return value;
        }
        if (left > mid)
        {
            return r->rangeQuery(left, right);
        }
        else if (right <= mid)
        {
            return l->rangeQuery(left, right);
        }
        else
        {
            ll ans = (l->rangeQuery(left, mid)) * (powers[right - mid]);
            ans %= mod;
            ans += r->rangeQuery(mid + 1, right);
            ans %= mod;
            return ans;
        }
    }
} *root;

void solve()
{
    cin >> n >> mod >> num >> qn;
    root = new node(0, n + 1);
    powerComputation();
    for (ll q = 0; q < n; q++)
    {
        ll currDigit = num[q] - '0';
        root->pointUpdate(q + 1, currDigit);
        // cout << root->rangeQuery(q + 1, q + 1) << " ";
    }
    // cout << "\n";
    // cout << root->rangeQuery(2, 4);
    for (ll q = 0; q < qn; q++)
    {
        cin >> c1 >> c2 >> c3;
        if (c1 == 1)
        { // query answering time!
            ll ans = root->rangeQuery(c2, c3);
            cout << ans << "\n";
        }
        else
        {
            root->pointUpdate(c2, c3);
        }
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