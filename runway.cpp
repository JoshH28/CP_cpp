// [Verse 1]
// I know there's ten thousand miles between us now
// Like the light of the moon looking down
// I wish that I could reach you
// Wish that I could crash upon your shore
// How your waves made me love to drown

// [Verse 2]
// I need your touch but I don't know how
// To write a line in the silver clouds
// But you can reach me with your mind
// We can cross the borderline
// Wish I could fly at the speed of sound

// [Chorus]
// If we're ten thousand miles apart
// When we're standing in the dark
// We're still looking at the same stars
// I'd cross oceans and galaxies for you
// Oh, there's nothing I wouldn't do
// Ten thousand miles apart
// We'll never be too far

// [Drop]
// We'll never be too far
// Ten thousand miles apart

// [Chorus]
// If we're ten thousand miles apart
// When we're standing in the dark
// We're still looking at the same stars
// I'd cross oceans and galaxies for you
// Oh, there's nothing I wouldn't do
// Ten thousand miles apart
// We'll never be too far (We'll never be too far)

// [Bridge]
// (I'd cross oceans and galaxies for you)
// I'd cross oceans and galaxies for you
// (Oh, oh woah)
// (Oh, oh woah)
// We'll never be too far

// [Drop]
// We'll never be too far
// (We'll never be too far)
// (Woah, oh woah)
// Ten thousand miles apart
// We'll never be too far
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
  ll n, en, k, t1, t2, t3;
  cin >> n >> en >> k;
  vector<pll> adjlist[n+1];
  for (ll q = 0;  q < en; q++) {
    cin >> t1 >> t2 >> t3;
    adjlist[t1].push_back(MP(t2, t3));
    adjlist[t2].push_back(MP(t1, t3));
  }
  deque<ll> bfs;
  bfs.push_back(1); // handle the case where may have path shorter than k
  ll dist[n+1]; 
  for (ll q = 0; q <= n; q++) {dist[q] = INT_MAX;}
  dist[1] = 0;
  while(!bfs.empty()) {
    ll cn = bfs.front(); bfs.pop_front();
    for (auto it: adjlist[cn]) {
        ll tn = it.first; ll weight = it.second;
        if (dist[tn] <= dist[cn]+1) continue;
        bfs.push_back(tn);
        dist[tn] = dist[cn]+1;
    }
  }
  //cout << dist[n] << " ";
  if (dist[n] < k) {cout << -1; return;}
  ll lo = 1, hi = 1e9, ans = INT_MAX;
  while (lo < hi) {
    ll mid = (lo+hi)/2;
    for (ll q = 0; q <= n; q++) {dist[q] = INT_MAX;}
    dist[1] = 0;
    bfs.push_front(1);
    while(!bfs.empty()) {
        ll cn = bfs.front(); bfs.pop_front();
        for (auto it: adjlist[cn]) {
            ll tn = it.first; ll weight = it.second;
            if (weight > mid) {weight = 1;}
            else {weight = 0;}
            if (dist[tn] <= dist[cn]+weight) continue;
            if (weight == 0) {
                bfs.push_front(tn);
                dist[tn] = dist[cn];
            } else {
                bfs.push_back(tn);
                dist[tn] = dist[cn]+1;
            }
        }
    }
    if (dist[n] < k) {// this value of mid can, go lower
        ans = min(ans, mid);
        hi = mid;
    } else {
        lo = mid+1;
    }
  }
  cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}