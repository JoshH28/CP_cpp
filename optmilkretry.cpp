// [Verse 1]
// I wish I knew why it's different now
// Why it feels like we’re turning to strangers
// Nothing happened so why are we fading out?

// And I know that you feel it too
// I think we're both scared of breaking the silence
// So instead we keep trying to hide the truth

// [Pre-Chorus]
// Oh baby we keep lying every night
// While we're lying right next to each other
// And we know it isn’t right
// But we don't wanna admit that it's over

// Cause ooh, we know it's love to lose
// Running from the truth
// By lying every night
// While wе're lying right next to each othеr

// [Chorus]
// Lie lie lie, lie to each other
// While we lie lie lie next to one another
// Lie lie lie, lie to each other tonight
// I don't know why we
// Lie lie lie, lie to each other
// While we lie lie lie next to one another
// Lie lie lie, lie to each other tonight
// I don't know why we

// [Drop]
// I don't know why we
// Lie lie lie, lie to each other
// While we lie lie lie next to one another
// Lie lie lie, lie to each other tonight
// I don’t know why we

// [Verse 2]
// And I wish there was an excuse
// A reason our feelings are changing
// What’s to blame? Baby it wasn't me or you, no no no

// You’re so distant, holding me close
// It's like we're miles apart in the same room
// Got no reason to stay, does that mean I should go?
// No no

// [Pre-Chorus]
// Oh baby we keep lying every night
// While we're lying right next to each other
// And we know it isn’t right
// But we don't wanna admit that it's over

// Cause ooh, we know it's love to lose
// Running from the truth
// By lying every night
// While we're lying right next to each other
// [Chorus]
// Lie lie lie, lie to each other
// While we lie lie lie next to one another
// Lie lie lie, lie to each other tonight
// I don't know why we
// Lie lie lie, lie to each other
// While we lie lie lie next to one another
// Lie lie lie, lie to each other tonight
// I don't know why we

// [Drop]
// I don't know why we
// Lie lie lie, lie to each other
// While we lie lie lie next to one another
// Lie lie lie, lie to each other tonight
// I don't know why we
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

struct node {
  ll start, end, mid, left=0, right=0, both=0, none=0;
  node *l, *r;
  node(ll s, ll e) {
    start = s; end = e;
    mid = (start+end)/2;
    if (start != end) {
      l = new node(start, mid);
      r = new node(mid+1, end);
    }
  }
  void pointUpdate(ll pos, ll val) {
    if (start == end) {
      both = val;
      return;
    } else{
      if (pos > mid) {
        r->pointUpdate(pos, val);
      } else {
        l->pointUpdate(pos, val);
      }
      left = max(l->left + r->left, r->none + l->both);

      right = max(l->right + r->right, l->none + r->both);
      
      both = max(l->left + r->both, r->right + l->both);
      
      none =  max(r->left + l->none, l->right + r->none);
    }
  }

  ll rangeQuery() {
    return max({left, right, both, none});
    // if (start == begin && last == end) {
    //   return max({left, right, both, none});
    // } else {
    //   if (begin > mid) {
    //     return r->rangeQuery(begin, last);
    //   } else if (end <= mid) {
    //     return l->rangeQuery(begin, last);
    //   } else {
    //     return max(l->rangeQuery(begin, mid), r->rangeQuery(mid+1, last));
    //   }
    // }
  }
}*root;

void solve() {
  ll n, d, t1, t2; cin >> n >> d;
  root = new node(0, n-1);
  for (ll q = 0; q < n; q++) {
    cin >> t1;
    root->pointUpdate(q, t1);
  }
  ll ans= 0;
  for (ll q = 0; q < d; q++) {
    cin >> t1 >> t2;
    root->pointUpdate(t1-1, t2);
    ans+= root->rangeQuery();
  }
  cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}