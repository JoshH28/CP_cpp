#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,fma,bmi,bmi2,abm,lzcnt,popcnt")

// Your heart for takeaway, yeah, yeah, yeah, yeah
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Hey, hey, hey
// Where do you think you're going?
// It's so late, late, late
// What's wrong?
// I said, "I can't stay, do I have to give a reason?
// It's just me, me, me, it's what I want
// So how did we get here?
// Three weeks now, we've been so caught up
// Better if we do this on our own
// Before I love you (nah, nah, nah)
// I'm gonna leave you (nah, nah, nah)
// Before I'm someone you leave behind
// I'll break your heart so you don't break mine
// Before I love you (nah, nah, nah)
// I'm gonna leave you (nah, nah, nah)
// Even if I'm not here to stay
// I still want your heart
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Your heart for takeaway
// Your heart for takeaway, yeah, yeah, yeah yeah
// Fate, fate, fate
// Is that what came between us?
// Or did we do this on our own?
// So how did we get here?
// I'm asking myself why I'm so caught up
// Better if we do this on our own
// Before I love you (nah, nah, nah)
// I'm gonna leave you (nah, nah, nah)
// Before I'm someone you leave behind
// I'll break your heart so you don't break mine
// Before I love you (nah, nah, nah)
// I'm gonna leave you (nah, nah, nah)
// Even if I'm not here to stay
// I still want your heart
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Your heart for takeaway
// Your heart for takeaway, yeah, yeah, yeah, yeah
// Before I love you (nah, nah, nah)
// I'm gonna leave you (nah, nah, nah)
// Before I'm someone you leave behind
// I'll break your heart so you don't break mine
// Before I love you (nah, nah, nah)
// I'm gonna leave you (nah, nah, nah)
// Even if I'm not here to stay
// I still want your heart
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
#define pq priority_queue
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

struct DSU {
    const ll MAXN = 100001;
    ll parent[1001][10001]; // reminder to change this to 1001 10001 before submission
    ll size[1001][10001]; // this also
    DSU(ll nn, ll cn) {
        for (ll q = 1; q <= nn; q++) {
          for (ll w = 1; w <= cn; w++) {
            parent[q][w] = q;
            size[q][w] = 1;
          }
        }
    }
    ll par(ll x, ll y) {
        if (parent[x][y] == x) {
            return x;
        } else {
            ll pathCompression = par(parent[x][y], y); 
            parent[x][y] = pathCompression; // path compression;
            return pathCompression;
        }
    }
    void merge(ll x, ll y, ll childN) {
        if (par(x, childN) == par(y, childN)) return;
        parent[par(x,childN)][childN] = parent[par(y, childN)][childN]; 
        if (size[par(x, childN)][childN] < size[par(y, childN)][childN]) {
            size[par(y, childN)][childN] += size[par(x, childN)][childN];
            parent[par(x, childN)][childN] = par(y, childN);
        } else {
            size[par(x, childN)][childN] += size[par(y, childN)][childN];
            parent[par(y, childN)][childN] = par(x, childN);
        }
    }

  bool isSameSet(ll x, ll y, ll childN) {
    if (par(x, childN) == par(y, childN)) {return true;}
    return false;
  }

}*ufds;

void solve() {
  ll nn, en, cn, t1, t2, t3;
  cin >> nn >> en >> cn;
  vector< pair<pll, pll> > edges;
  ll ans[en+1]; memset(ans, 0, sizeof(ans));
  for (ll q = 0; q < en; q++) {
    cin >> t1 >> t2 >> t3;
    edges.push_back(MP(MP(t3, q), MP(t2, t1)));
  }
  sort(edges.begin(), edges.end()); 
  reverse(edges.begin(), edges.end()); 
  ufds = new DSU(nn, cn);
  for (auto it: edges) {
    ll value = it.first.first; ll a = it.second.first; ll b = it.second.second;
    ll lo = 1, hi = cn+1, lowest = INT_MAX; //bsearching for the lowest child that can actually take the railway
    while(lo < hi) {
      ll mid = (lo+hi)/2;
      if (ufds->isSameSet(a, b, mid) == false) {// this guy can, go lower
        hi = mid;
        lowest = min(lowest, mid);
      } else { // this guy can't, go higher
        lo = mid+1; 
      }
    }
    if (lowest == INT_MAX) {ans[it.first.second] = 0; continue;}
    ans[it.first.second] = lowest;
    ufds->merge(a, b, lowest);
  }
  for (ll q = 0; q < en; q++) {
    cout << ans[q] << "\n";
  }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}