// Hmm-mmm-mmm
// Woah-oh-oh-oh
// It's always a good time
// Woah-oh-oh-oh
// It's always a good time

// Woke up on the right side of the bed
// What's up with this Prince song inside my head?
// Hands up, if you're down to get down tonight (Hmm-mmm-mmm)
// 'Cause it's always a good time
// Slept in all my clothes, like I didn't care
// Hopped into a cab, take me anywhere
// I'm in if you're down to get down tonight
// 'Cause it's always a good time

// Good morning and goodnight
// I wake up at twilight
// It's gonna be alright
// We don't even have to try, it's always a good time (Woo!)

// Woah-oh-oh-oh, oh-oh-oh
// Woah-oh-oh-oh
// It's always a good time
// Woah-oh-oh-oh, oh-oh-oh
// We don't even have to try, it's always a good time
// (Good time, good time, it's always a good time)
// (Woah-oh-oh-oh)

// Freaked out, dropped my phone in the pool again
// Checked out of my room, hit the ATM
// Let's hang out if you're down to get down tonight
// 'Cause it's always a good time

// Good morning and goodnight
// I wake up at twilight
// It's gonna be alright
// We don't even have to try, it's always a good time (Woo!)

// Woah-oh-oh-oh, oh-oh-oh
// Woah-oh-oh-oh
// It's always a good time
// Woah-oh-oh-oh, oh-oh-oh
// We don't even have to try, it's always a good time
// Woah-oh-oh-oh, oh-oh-oh
// Woah-oh-oh-oh
// It's always a good time
// Woah-oh-oh-oh, oh-oh-oh
// We don't even have to try, it's always a good time

// Doesn't matter when
// It's always a good time then
// Doesn't matter where
// It's always a good time there
// Doesn't matter when
// It's always a good time then
// (It's always a good time!)

// Woah-oh-oh-oh, oh-oh-oh
// Woah-oh-oh-oh
// It's always a good time
// Woah-oh-oh-oh, oh-oh-oh
// We don't even have to try, it's always a good time
// Woah-oh-oh-oh, oh-oh-oh (Doesn't matter where)
// Woah-oh-oh-oh
// It's always a good time
// Woah-oh-oh-oh, oh-oh-oh (Doesn't matter where)
// We don't even have to try, it's always a good time

// Woah-oh-oh-oh, oh-oh-oh
// Woah-oh-oh
// It's always a good time
// Woah-oh-oh-oh, oh-oh-oh
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
// typedef long double ld;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update>  multi_pbds;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

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

ll n, ptr=0; pll arr[200001], temp[200001]; ll ans[200001];
pair<pll, ll> query[200001];

bool cmp(pll p1, pll p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1; cin >> n;
  multi_pbds pbds;
  for (ll q = 0; q < n; q++) {cin >> arr[q].first; arr[q].second = q; }
  for (ll q = 0; q < n; q++) {temp[q] = arr[q];}
  cin >> tc; sort(arr, arr+n, cmp);
  for (ll q = 0; q < tc; q++) {
    cin >> query[q].first.first >> query[q].first.second;
    query[q].second = q; 
  }
  sort(query, query+tc); 
  for (ll q = 0; q < tc; q++) {
    ll x = query[q].first.second, leng = query[q].first.first; 
    ll initialorder = query[q].second;
    while(ptr < leng) {
        pbds.insert(arr[ptr].second); ptr++;
    }
    ans[initialorder] = temp[*pbds.find_by_order(x-1)].first;
  }
  for (ll q = 0; q < tc; q++) cout << ans[q] << "\n";
}