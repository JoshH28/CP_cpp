// Written in these walls are the stories that I can't explain
// I leave my heart open, but it stays right here empty for days
// She told me in the mornin' she don't feel the same about us in her bones
// It seems to me that when I die, these words will be written on my stone

// And I'll be gone, gone tonight (Oh-oh-oh)
// The ground beneath my feet is open wide (Oh-oh-oh)
// The way that I've been holding on too tight (Oh-oh-oh)
// With nothing in between

// The story of my life, I take her home
// I drive all night to keep her warm
// And time is frozen (The story of, the story of)
// The story of my life, I give her hope
// I spend her love until she's broke inside
// The story of my life (The story of, the story of)

// Written on these walls are the colors that I can't change
// Leave my heart open, but it stays right here in its cage
// I know that in the mornin', I'll see us in the light up on the hill
// Although I am broken, my heart is untamed still

// And I'll be gone, gone tonight (Oh-oh-oh)
// The fire beneath my feet is burning bright (Oh-oh-oh)
// The way that I've been holding on so tight (Oh-oh-oh)
// With nothing in between

// The story of my life, I take her home
// I drive all night to keep her warm
// And time is frozen (The story of, the story of)
// The story of my life, I give her hope
// I spend her love until she's broke inside
// The story of my life (The story of, the story of)

// And I've been waiting for this time to come around
// But, baby, running after you is like chasin' the clouds

// The story of my life, I take her home
// I drive all night to keep her warm
// And time is frozen

// The story of my life, I give her hope (I give her hope)
// I spend her love until she's broke inside ('Til she's broke inside)
// The story of my life (The story of, the story of)
// The story of my life
// The story of my life (The story of, the story of)
// The story of my life
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
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
typedef long double ld;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

const ll N = 500001;

typedef long long ll;
struct node {
int s, e;
ll mn, mx, sum; bool lset; ll add_val, set_val;
node *l, *r;
node (int _s, int _e, int A[] = NULL): s(_s), e(_e), mn(0), mx(0), sum(0), lset(0), add_val(0), set_val(0), l(NULL), r(NULL) {
    if (A == NULL) return;
    if (s == e) mn = mx = sum = A[s];
    else {l = new node(s, (s+e)>>1, A), r = new node((s+e+2)>>1, e, A);combine();}
}
void create_children() {
    if (s == e) return;
    if (l != NULL) return;
    int m = (s+e)>>1;
    l = new node(s, m);
    r = new node(m+1, e);
}
void self_set(ll v) {
   lset = 1;
   mn = mx = set_val = v;
   sum = v * (e-s+1);
   add_val = 0;
}
void self_add(ll v) {
   if (lset) { self_set(v + set_val); return; }
   mn += v, mx += v, add_val += v;
   sum += v*(e-s+1);
}
void lazy_propagate() {
   if (s == e) return;
   if (lset) {
       l->self_set(set_val), r->self_set(set_val);
       lset = set_val = 0;
   }
   if (add_val != 0) {
       l->self_add(add_val), r->self_add(add_val);
       add_val = 0;
   }
}
void combine() {
   if (l == NULL) return;
   sum = l->sum + r->sum;
   mn = min(l->mn, r->mn);
   mx = max(l->mx, r->mx);
}
void add(int x, int y, ll v) {
   if (s == x && e == y) { self_add(v); return; }
   int m = (s+e)>>1;
   create_children(); lazy_propagate();
   if (x <= m) l->add(x, min(y, m), v);
   if (y > m) r->add(max(x, m+1), y, v);
   combine();
}
void set(int x, int y, ll v) {
   if (s == x && e == y) { self_set(v); return; }
   int m = (s+e)>>1;
   create_children(); lazy_propagate();
   if (x <= m) l->set(x, min(y, m), v);
   if (y > m) r->set(max(x, m+1), y, v);
   combine();
}
ll range_sum(int x, int y) {
   if (s == x && e == y) return sum;
   if (l == NULL || lset) return (sum / (e-s+1)) * (y-x+1);
   int m = (s+e)>>1;
   lazy_propagate();
   if (y <= m) return l->range_sum(x, y);
   if (x > m) return r->range_sum(x, y);
   return l->range_sum(x, m) + r->range_sum(m+1, y);
}
ll range_min(int x, int y) {
   if (s == x && e == y) return mn;
   if (l == NULL || lset) return mn;
   int m = (s+e)>>1;
   lazy_propagate();
   if (y <= m) return l->range_min(x, y);
   if (x > m) return r->range_min(x, y);
   return min(l->range_min(x, m), r->range_min(m+1, y));
}
ll range_max(int x, int y) {
   if (s == x && e == y) return mx;
   if (l == NULL || lset) return mx;
   int m = (s+e)>>1;
   lazy_propagate();
   if (y <= m) return l->range_max(x, y);
   if (x > m) return r->range_max(x, y);
   return max(l->range_max(x, m), r->range_max(m+1, y));
}
~node() {
   if (l != NULL) delete l;
   if (r != NULL) delete r;
}
} *root;

void solve() {
  ll n, m; cin >> n >> m; ll arr[n], psum[n+10];
  psum[0] = 0;  for (ll q = 0; q < n; q++) cin >> arr[q];
  for (ll q = 1; q <= n; q++) {psum[q] = psum[q-1]%m + arr[q-1]%m; psum[q]%=m;}
  ll sus = 0, ans = 0;
  root = new node(0, m+10);
  for (ll q = 1; q <= n; q++) {
    ans = ans + psum[q]*q - sus + root->range_sum(psum[q]+1, m)*m;
    sus += psum[q]; root->add(psum[q], psum[q], 1);
  }
  cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}