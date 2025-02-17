// [Verse 1]
// We caught a cab to buy the cheapest bottle
// And without a doubt, felt like a million dollars
// Yeah we loved to fight but hated to admit
// That we would fall apart with nothing but each other

// [Pre-Chorus]
// 'Cause you got me so rich off your love, baby
// You turn ashes into gold, but lately
// Oh, oh, oh, lately

// [Chorus]
// I'm broke, so broke, I'm counting change
// In Chicago for a train
// That I've missed anyway
// Missed anyway, I've missed anyway
// Yeah, I'm broke
// Broke, so broke, I'm counting change
// In Chicago for a train
// That I've missed anyway
// Missed anyway, I've missed anyway
// Yeah, I'm broke

// [Verse 2]
// You're running wild in circles in my head with every breath I take
// I'm back to your old Chevy like a brand new car
// With you it's only fancy unsteady rides
// With nothing but each other

// [Pre-Chorus]
// 'Cause you got me so rich off your love, baby
// You turn ashes into gold, but lately

// [Chorus]
// Broke, so broke, I'm counting change
// In Chicago for a train
// That I've missed anyway
// Missed anyway, I've missed anyway
// Yeah, I'm broke

// [Instrumental Interlude]

// [Post-Chorus]
// Boy, you got me rich
// Rich off your love (Love)
// Boy, you got me rich
// So rich off your love
// Boy, you got me rich
// Rich off your love (Love)
// Rich off your love
// So rich off your love

// [Chorus]
// I'm broke, so broke I'm counting change
// In Chicago for a train
// That I've missed anyway
// Missed anyway, I've missed anyway
// Yeah, I'm broke
// Broke, so broke, I'm counting change
// In Chicago for a train
// That I've missed anyway
// Missed anyway, I've missed anyway
// Yeah, I'm broke
// [Instrumental Interlude]

// [Bridge]
// Boy, you got me rich
// Rich off your love (Love)
// Boy, you got me rich
// So rich off your love
// Boy, you got me rich
// Rich off your love (Love)
// So rich off your love
// So rich off your love

// [Outro]
// I'm broke, so broke, I'm counting change
// In Chicago for a train
// That I've missed anyway
// Missed anyway, I've missed anyway
// Yeah, I'm broke
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
    ll n, en, t1, t2, t3;
    cin >> n >> en;
    vector<pll> adjlist[n + 1];
    stack<ll> parents;
    for (ll q = 0; q < en; q++)
    {
        cin >> t1 >> t2 >> t3;
        adjlist[t1].push_back(MP(t2, t3));
        adjlist[t2].push_back(MP(t1, t3));
    }
    ll dist[n + 1], par[n + 1];
    for (ll q = 0; q <= n; q++)
    {
        dist[q] = INT_MAX;
        par[q] = q;
    }
    par[1] = -1;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    q.push(make_pair(0, 1));
    while (!q.empty())
    {
        pll cur = q.top();
        q.pop();
        int x = cur.second, d = cur.first;
        if (d > dist[x])
            continue;
        for (vector<pll>::iterator it = adjlist[x].begin(); it != adjlist[x].end(); ++it)
        {
            int nx = it->first, nd = d + it->second;
            if (dist[nx] != -1 && dist[nx] <= nd)
                continue;
            dist[nx] = nd;
            q.push(make_pair(nd, nx));
            par[nx] = x;
        }
    }
    ll curr = n;
    while (curr >= 0)
    {
        // cout << curr << " ";
        parents.push(curr);
        curr = par[curr];
    }
    ll od = dist[n];
    // cout << od;
    ll fd = 0;
    while (parents.size() > 1)
    {
        for (ll q = 0; q <= n; q++)
        {
            dist[q] = INT_MAX;
        }
        ll t1 = parents.top();
        parents.pop();
        ll t2 = parents.top();
        memset(dist, -1, sizeof(dist));
        dist[1] = 0;
        q.push(make_pair(0, 1));
        while (!q.empty())
        {
            pll cur = q.top();
            q.pop();
            int x = cur.second, d = cur.first;
            if (d > dist[x])
                continue;
            for (vector<pll>::iterator it = adjlist[x].begin(); it != adjlist[x].end(); ++it)
            {

                int nx = it->first, nd = d + it->second;
                if (x == t1 && nx == t2)
                {
                    if (dist[nx] != -1 && dist[nx] <= nd + it->second)
                        continue;
                    dist[nx] = nd + it->second;
                    q.push(make_pair(nd + it->second, nx));
                }
                else
                {
                    if (dist[nx] != -1 && dist[nx] <= nd)
                        continue;
                    dist[nx] = nd;
                    q.push(make_pair(nd, nx));
                }
            }
        }
        fd = max(fd, dist[n]);
    }
    cout << fd - od;
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