// I fall too often
// And I love to complicate until there's nothing
// My feet get cold
// So, no more talking
// Let's just let it go, the way that it's been going
// You keep me close
// I wanna feel like this forever
// A little reckless, babe
// We can do whatever we like
// Yeah, we could feel like this forever
// I want you front and center
// I could be your nine to five, ooh
// Ooh, you're all I want
// Give me all your love around the clock
// AM:PM
// Ooh, you're all I want
// We're going and we never gonna stop
// AM:PM
// AM:PM
// No seconds wasted
// And I feel the night fading
// But I'm wide awake, and I don't wanna go
// So, let's not waste this
// Go ahead, take the shot my lips will be a chaser
// I ain't going home
// I wanna feel like this forever
// A little reckless, babe
// We can do whatever we like
// Yeah, we could feel like this forever
// I want you front and center
// I could be your nine to five, ooh
// Ooh, you're all I want
// Give me all your love around the clock
// AM:PM
// Ooh, you're all I want
// We're going and we never gonna stop
// AM:PM
// AM:PM
// I wanna feel like this forever
// A little reckless, babe
// We can do whatever we like
// Yeah, we could feel like this forever
// I want you front and center
// I could be your nine to five, ooh
// Ooh, you're all I want
// Give me all your love around the clock
// AM:PM
// Ooh, you're all I want
// We're going and we never gonna stop
// AM:PM
// AM:PM
// AM:PM
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


vector<ll> adjlist[200005];

ll preorder[200005], postorder[200005], dist[200005];
ll counter = 0;

void prepost(ll x, ll p) {
    preorder[x] = ++counter;
    for (auto it: adjlist[x]) {
        if (it == p) continue;
        dist[it] = dist[x]+1;
        prepost(it, x);
    }
    postorder[x] = counter;
}

bool cmp(ll x, ll y) {
    return dist[x] > dist[y];
}

typedef long long ll;
struct node {
    int s, e;
    ll mn, mx, sum;
    bool lset;
    ll add_val, set_val;
    node *l, *r;
    node (int _s, int _e, int A[] = NULL): s(_s), e(_e), mn(0), mx(0), sum(0), lset(0), add_val(0), set_val(0), l(NULL), r(NULL) {
        if (A == NULL) return;
        if (s == e) mn = mx = sum = A[s];
        else {
            l = new node(s, (s+e)>>1, A), r = new node((s+e+2)>>1, e, A);
            combine();
        }
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
    void set(int x, int y, ll v) {
        if (s == x && e == y) { self_set(v); return; }
        int m = (s+e)>>1;
        create_children(); lazy_propagate();
        if (x <= m) l->set(x, min(y, m), v);
        if (y > m) r->set(max(x, m+1), y, v);
        combine();
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

ll solve() {
    memset(preorder, 0, sizeof(preorder));
    memset(postorder, 0, sizeof(preorder));
    memset(dist, 0, sizeof(dist));
    ll n, qn, a, b, t1, ans=0; cin >> n >> qn >> a >> b;
    counter = 0;
    root = new node(0, n+10);
    for (ll q = 0; q < 200005; q++) {
        adjlist[q].clear();
    }
    for (ll q = 1; q < n; q++) {
        cin >> t1;
        adjlist[t1].push_back(q);
    }
    dist[0] = 0;
    prepost(0, -1);
    ll queries[qn+5];
    for (ll q = 0; q < qn; q++) {
        queries[q] = (a*q + b)%n; // idk what they are asking for but wtv
        //cout << queries[q] << " ";
    }
    for (ll q = 0; q < n ;q++) {
        root->set(preorder[q], preorder[q], q);
        //cout << root->rq(preorder[q], preorder[q]).first << " ";
    }
    sort(queries, queries+qn, cmp); 
    for (ll q = 0; q < qn; q++) {
        ll queryAns = root->range_max(preorder[queries[q]], postorder[queries[q]]);
        //cout << "query " << queries[q] << " ";
        if (queryAns < 0) continue;
        ans += queryAns;
        //cout << queryAns.first << "\n";
        //cout << preorder[queries[q]] << " " << postorder[ques[q]] << "\n";
        root->set(preorder[queryAns], preorder[queryAns], -1000000000000);
    }
    return ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {cout << "Case #" <<  to_string(q+1) << ": " << solve() << "\n";}
  return 0;
}