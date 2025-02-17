// [Verse 1]
// I'll never forget the songs we used to play
// And when I put 'em on
// The feeling never fades out my body
// I hope you're thinkin' of me (Mmm)
// There won't be a night, there won't be a place
// Where you don't cross my mind
// Where I don't see your face in somebody (Mmm)
// I hope you're thinkin' of me (Mmm)

// [Pre-Chorus]
// People say we're foolish, people say we're dumb
// People say we're caught up in temporary love
// We don't know what we're doin', they say we're too young
// But they don't know a thing about us

// [Chorus]
// I'll wait forever, that's what we said
// 16th of September, lyin' in my bed
// I'll wait forever, it's never too late
// Couple thousand miles is just a little space

// [Post-Chorus]
// I'll wait (Mmm)
// I'll wait (Mmm)
// I'll wait (Mmm)
// Couple thousand miles is just a little space
// I'll wait

// [Drop]
// I'll wait

// [Verse 2]
// There won't be an end, can't forget the start
// When you're far away, it's like we're not apart
// I'd burn my money
// Just to hear you say you love me again

// [Pre-Chorus]
// People say we're foolish, people say we're dumb
// People say we're caught up in temporary love
// We don't know what we're doin', they say we're too young
// But they don't know a thing about us

// [Chorus]
// I'll wait forever, that's what we said
// 16th of September, lyin' in my bed
// I'll wait forever, it's never too late
// Couple thousand miles is just a little space

// [Post-Chorus]
// I'll wait (Mmm)
// I'll wait (Mmm)
// I'll wait (Mmm)
// Couple thousand miles is just a little space
// I'll wait
// [Drop]
// Far away (Mmm)
// Far away (Mmm)
// Far away (Mmm)
// Couple thousand miles is just a little space

// [Outro]
// I'll wait forever, that's what we said
// 16th of September, lyin' in my bed
// I'll wait forever, it's never too late
// Couple thousand miles is just a little space
// I'll wait
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

ll arr[500001];
ll n, qn;

struct node {
  ll start, end, mid, value=0; 
  node *l, *r;
  node (ll s, ll e) {
    start = s; end = e; mid = (start + end)/2;
  } 

  void create_children() {
    if (start!=end) {
      l = new node(start, mid);
      r = new node(mid+1, end);
    }
  }

  void update(ll pos, ll uv) {
    if (l == nullptr) {create_children();}
    if (start == end) {
      value += uv;
      return;
    }
    if (pos <= mid) {l->update(pos, uv);}
    else {r->update(pos, uv);}
    value = r->value + l->value;
  }
  ll rangeQuery(ll left, ll right) {
    if (l == nullptr) {create_children();}
    if (start == left && end == right) {
      return value;
    } else {
      if (left > mid) {
        return r->rangeQuery(left, right);
      } else if (right <= mid) {
        return l->rangeQuery(left, right);
      } else {
        return l->rangeQuery(left, mid) + r->rangeQuery(mid+1, right);
      }
    }
  }

}*root;


void solve() {
  cin >> n >> qn;
  string bruh; ll t1, t2;
  root = new node(0, 1e9+1);
  for (ll q = 0; q < n; q++) {
	  cin >> arr[q];
    root->update(arr[q], 1);
  }
  for (ll q = 0; q < qn; q++) {
    cin >> bruh >> t1 >> t2;
    if (bruh == "!") {
      root->update(arr[t1-1], -1); root->update(t2, 1);
      arr[t1-1] = t2;
	} else {
      cout << root->rangeQuery(t1, t2) << "\n";
    }
  }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}