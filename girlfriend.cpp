// I close all the curtains
// Feeling like a burden
// Lying under gray skies
// Just until they pass by
// (Pass by, pass by, pass by, pass by)
// Wonder what it'd be like, just to feel alive
// (Alive, alive, alive, alive)
// Battle in my own mind
// Pray I'll make it this time
// (This time, this time, this time, this time)
// But I fall in my own premonition
// Tracing scars became my addiction
// Can't reach out
// 'Cause nobody listens
// Keep you at a distance
// I miss the dreams of a young mind
// Head in the clouds for the first time
// Replaying memories to get by
// The dream fades, and I'm stuck in real life
// And I sense that I'll never get back
// A box full of good days from my past
// Replaying memories to get by
// And I'm stuck in real life
// [Pre-Drop]
// (Real life, real life, real life, real life)
// (Real life, real life, real life, real life)
// And I'm stuck in real life
// And I'm stuck in real life
// Look for the horizon, but I can never find it
// And I'm stuck in real life
// Sitting on the sunsets
// Off into the deep end
// Look for the horizon, but I can never find it
// (Find it, find it, find it, find it)
// I wonder how it happened
// All my wounds came crashing, oh
// (All my wounds came crashing, oh)
// Life became so tragic, worse than I imagined
// (Imagine, imagine, imagine, imagined)
// But I fall in my own premonition
// Tracing scars became my addiction
// Can't reach out
// 'Cause nobody listens
// Keep you at a distance
// I miss the dreams of a young mind
// Head in the clouds for the first time
// Replaying memories to get by
// The dream fades, and I'm stuck in real life
// And I sense that I'll never get back
// A box full of good days from my past
// Replaying memories to get by
// And I'm stuck in real life
// And I'm stuck in real life
// Look for the horizon, but I can never find it
// And I'm stuck in real life
// And I'm stuck in real life
// And I'm stuck in real life
// And I'm stuck in real life
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

const int MAXN = 1e5 + 1;
vector<pll> al[MAXN];
ll visited[MAXN], dist[MAXN];
ll en, nn, t1, t2, t3, sn, tn;
queue<ll> ts;
unordered_set<ll> vis;

bool vis1[100001], vis2[100001];

bool dfs(int index)
{ // returns true if there is a cycle in the disjoint subgraph of index
    vis1[index] = 1;
    vis2[index] = 1;
    for (auto bruh : al[index])
    {
        ll it = bruh.first;
        if (!vis1[it] && dfs(it))
            return 1;
        else if (vis2[it])
            return 1;
    }
    vis2[index] = 0;
    return 0;
}

void chkp(ll ci)
{
    if (visited[ci])
    {
        return;
    }
    visited[ci] = 1;
    for (auto bruh : al[ci])
    {
        ll it = bruh.first;
        if (!visited[it])
        {
            chkp(it);
        }
    }
}

void topo(ll ci)
{
    if (visited[ci])
    {
        return;
    }
    visited[ci] = 1;
    for (auto bruh : al[ci])
    {
        ll it = bruh.first;
        if (!visited[it])
        {
            topo(it);
        }
    }
    ts.push(ci);
}

ll solve()
{
    cin >> nn >> en >> sn >> tn;
    for (ll q = 0; q < MAXN; q++)
    {
        visited[q] = 0;
        dist[q] = -INT_MAX;
    }
    for (ll q = 0; q < en; q++)
    {
        cin >> t1 >> t2 >> t3;
        al[t1].push_back(MP(t2, t3));
    }
    chkp(sn);
    if (visited[tn] == 0)
    {
        return -1;
    }
    // up to here correct i think
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    if (dfs(sn) == true)
    {
        return -2;
    }
    ll dist[nn];
    for (ll q = 0; q < nn; q++)
    {
        dist[q] = -1;
    }
    queue<pll> que;
    que.push(MP(0, sn));
    while (!que.empty())
    {
        ll cd = que.front().first;
        ll cn = que.front().second;
        que.pop();
        if (dist[cn] >= cd)
        {
            continue;
        }
        dist[cn] = cd;
        for (auto it : al[cn])
        {
            ll nd = it.second + cd;
            ll nn = it.first;
            if (dist[nn] < nd)
            {
                que.push(MP(nd, nn));
            }
        }
    }
    return dist[tn];
    // for (ll q = 0; q < MAXN; q++)
    // {
    //     visited[q] = 0;
    // }
    // topo(sn);
    // // for (ll q = 1; q <= nn; q++)
    // // {
    // //     if (!visited[q])
    // //     {
    // //         topo(q);
    // //     }
    // // }
    // dist[sn] = 0;
    // while (!ts.empty())
    // {
    //     ll curr = ts.front();
    //     ts.pop();
    //     for (auto bruh : al[curr])
    //     {
    //         ll it = bruh.first;
    //         dist[it] = max(dist[curr] + bruh.second, dist[it]);
    //     }
    // }
    // return dist[tn];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll q = 0; q < tc; q++)
    {
        cout << solve();
    }
}