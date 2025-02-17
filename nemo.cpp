// Seven days, thousand ways (mm)
// To believe in fairy tales, don't think it's just a phase
// Lately (lately), I've been dreaming
// Been praying for some love, one you get from high above
// So, bye-ye-ye, bye, bye, bye
// To all the nasty vibes in my mind (ooh)
// I'm saying bye-ye-ye, bye, bye, bye
// I'm gonna leave 'em behind (behind)
// I'm just living my life
// No matter what they say, try a million times
// My daddy told me, "Keep on living your life"
// No matter where your days go
// Baby, don't you let go, let go
// Love rules (mm) without rules (ah-ay)
// Playing hide and seek with someone that used to keep me
// So high (so high), so low (so low)
// Was chasing everything, so I can feel a thing
// So, bye-ye-ye, bye, bye, bye
// To all the nasty vibes in my mind
// I'm saying bye-ye-ye, bye, bye, bye
// I'm gonna leave 'em behind (I'm leaving them behind)
// I'm just living my life
// No matter what they say, try a million times
// My daddy told me, "Keep on living your life"
// No matter where your days go
// Baby, don't you let go, let go
// People come and people go away
// I might break but memories always stay
// I'm just living my life
// No matter what they say, try a million times
// My daddy told me, "Keep on living your life"
// No matter where your days go
// Baby, don't you let go, let go
// I'm just living my life
// Try a million times
// Keep on living your life
// No matter where your days go
// Baby, don't you let go, let go
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
#define rep(x, start, end)                                                     \
  for (auto x = (start) - ((start) > (end)); x != (end) - ((start) > (end));   \
       ((start) < (end) ? x++ : x--))
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
//#define INT_MAX LONG_LONG_MAX
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset; // upper_bound and lower_bound swap functions in multi
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template <class K, class V>
using ht = gp_hash_table<
    K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>,
    hash_standard_resize_policy<hash_exponential_size_policy<>,
                                hash_load_check_resize_trigger<>, true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace
// doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is
// ht<ll,null_type>, all other operations are same as regular

struct DSU {
  const ll MAXN = 100001;
  ll parent[100001];
  ll size[100001];
  ll sizeOfMax = 1;
  DSU(ll n) {
    for (ll q = 1; q <= n; q++) {
      parent[q] = q;
      size[q] = 1;
    }
  }

  ll par(ll x) {
    if (parent[x] == x) {
      return x;
    } else {
      ll pathCompression = par(parent[x]);
      parent[x] = pathCompression;
      return pathCompression;
    }
  }

  void merge(ll x, ll y) {
    if (par(x) == par(y))
      return;
    if (size[par(x)] < size[par(y)]) {
      size[par(y)] += size[par(x)];
      parent[par(x)] = par(y);
      sizeOfMax = max(sizeOfMax, size[par(y)]);
    } else {
      size[par(x)] += size[par(y)];
      parent[par(y)] = par(x);
      sizeOfMax = max(sizeOfMax, size[par(x)]);
    }
  }

  bool isSameSet(ll x, ll y) {
    return par(x) == par(y);
  }
};

void solve() {
  ll nn, en, qn, t1, t2, t3, t4;
  cin >> nn >> en;
  // vector <pair<ll, pll>> adjlist[nn];
  vector<pair<ll, pll>> openEdges;
  vector<pair<ll, pll>> closedEdges;
  for (ll q = 0; q < en; q++) {
    cin >> t1 >> t2 >> t3 >> t4;
    openEdges.push_back(MP(t3, MP(t1, t2)));
    closedEdges.push_back(MP(t4, MP(t1, t2)));
  }
  sort(openEdges.begin(), openEdges.end());
  sort(closedEdges.begin(), closedEdges.end());
  reverse(closedEdges.begin(), closedEdges.end());
  cin >> qn;
  DSU open(nn - 1);
  DSU closed(nn - 1);
  priority_queue<pair<pll, pll>, vector<pair<pll, pll>>,
                 greater<pair<pll, pll>>>
      query;
  for (ll q = 0; q < qn; q++) {
    cin >> t1 >> t2 >> t3;
    query.push(MP(MP(t3, q), MP(t1, t2)));
  }
  string ansArr[qn];
  for (auto it : openEdges) {
    ll openingTime = it.first, a = it.second.first, b = it.second.second;

    while (!query.empty() && query.top().first.first < openingTime) {
      if (open.isSameSet(query.top().second.second, query.top().second.first)) {
        ansArr[query.top().first.second] = "Y";
      } else {
        ansArr[query.top().first.second] = "N";
      }
      query.pop();
    }
    open.merge(a, b);
  }
  priority_queue<pair<pll, pll>> pq;
  while (!query.empty()) {
    pq.push(query.top());
    query.pop();
  }
  for (auto it : closedEdges) {
    ll closingTime = it.first, a = it.second.first, b = it.second.second;
    while (!pq.empty() && pq.top().first.first > closingTime) {
      if (closed.isSameSet(pq.top().second.second, pq.top().second.first)) {
        ansArr[pq.top().first.second] = "Y";
      } else {
        ansArr[pq.top().first.second] = "N";
      }
      pq.pop();
    }
    closed.merge(a, b);
  }
  while (!pq.empty()) {
    if (closed.isSameSet(pq.top().second.second, pq.top().second.first)) {
      ansArr[pq.top().first.second] = "Y";
    } else {
      ansArr[pq.top().first.second] = "N";
    }
    pq.pop();
  }
  for (ll q = 0; q < qn; q++) {
    cout << ansArr[q] << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll tc = 1;
  // cin >> tc;
  for (ll q = 0; q < tc; q++) {
    solve();
  }
}