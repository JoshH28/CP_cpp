// [Verse 1]
// I know I haven't called you
// And it's been a few months since I tried to
// Maybe I'm scared I'll say the wrong thing
// My apartment's been shaking
// From the weight of a heart that's breaking
// Pretend I don't care, but it's killing me

// [Pre-Chorus]
// I'd be happy for you
// If you say you're happier with someone else
// But I'll be honest with you
// Just the thought of it hurts like hell

// [Chorus]
// All this time you've been thinking I moved on
// But you should know I waited for you
// Even if I tried, I could never let you go
// You should know I waited, I'm always waiting for you

// [Drop]
// Oh oh, I'm always waiting for you
// Oh oh, you should know, I waited

// [Verse 2]
// I know it ain't my business
// 'Cause I'm the one who asked for the distance
// But are you alone? Are you alright?
// And maybe you would judge me
// If I said that I hope you still love me
// Feels like you don't, but I'm scared that I'm right

// [Pre-Chorus]
// I'd be happy for you
// If you say you're happier with someone else
// But I'll be honest with you
// Just the thought of it hurts like hell

// [Chorus]
// All this time you've been thinking I moved on
// But you should know I waited for you
// Even if I tried, I could never let you go
// You should know I waited, I'm always waiting for you

// [Drop]
// Oh oh, I'm always waiting for you
// Oh oh, you should now I waited

// [Bridge]
// Ummm, umm

// [Chorus]
// All this time you've been thinking I moved on
// But you should know I waited for you
// Even if I tried, I could never let you go
// You should know I waited, I'm always waiting for you

// [Drop]
// Oh oh, I'm always waiting for you
// Oh oh, you should know I waited
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

void solve() {
  ll n, e, t1, t2, t3, mod = 1000000007; cin >> n >> e;
  vector<pll> adjlist[n];
  pll dist[n];
  for (ll q = 0; q < n; q++) {
    dist[q] = MP(INT_MAX, 0);
  }
  for (ll q = 0; q < e; q++) {
    cin >> t1 >> t2 >> t3;
    adjlist[t1].push_back(MP(t2, t3));
  }
  priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair <ll, pll> > > pq;
  dist[0] = make_pair(0, 1);
  pq.push(MP(0, MP(0, 1)));
  while(!pq.empty()) {
    ll cd = pq.top().first;
    ll cn = pq.top().second.first;
    ll cc = pq.top().second.second;
    pq.pop();
    if (dist[cn].first < cd) {
      continue;
    }
    for (auto it: adjlist[cn]) {
      ll tn = it.first;
      ll td = it.second + cd;
      ll tc = dist[cn].second % mod;
      if (dist[tn].first > td) {
        dist[tn] = MP(td, tc);
        pq.push(MP(td, MP(tn, tc)));
      } else if (dist[tn].first == td) {
        dist[tn] = MP(td, (tc + dist[tn].se)%mod);
      } 
    }
  }
  cout << dist[n-1].se;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}