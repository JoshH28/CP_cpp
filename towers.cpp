// [Verse 1]
// It feels like make or break
// Don't rush or hesitate
// Let the world decide your fate
// These fears, they fade away
// These skies, a shade of grey
// All these heights will guide your way

// [Pre-Chorus 1]
// Across the misty valley
// With its clear blue lakes
// Lies the promised land you know, oh
// You know your heart aches

// [Chorus]
// Across the Golden Gate
// Shining through the mist
// The dizzy twist of fate
// That keeps us dreaming
// Take a leap of faith
// Into the blue sky
// You know it's not too late
// It's your time to fly

// [Drop]

// [Post-Chorus]
// Yeah it's your time to fly
// Yeah it's your time to fly
// Yeah it's your time to fly

// [Verse 2]
// Right now it's black and white
// But when you start to fly
// The spark inside awakes
// Let it take you high
// So spread your tired wings
// And open your eyes
// When your heartbeat sings
// Yeah you touch the sky

// [Pre-Chorus 2]
// You've got through this storm now
// The sun starts to shine
// As you leave this world behind
// With your head held high

// [Chorus]
// Across the Golden Gate
// Shining through the mist
// The dizzy twists of fate
// That keeps us dreaming
// Take a leap of faith
// Into the blue sky
// You know it's not too late
// It's your time to fly
// [Drop]

// [Post-Chorus]
// It's your time to fly
// It's your time to fly
// It's your time to fly
// It's your time to fly
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

struct node{
    int s,e,m;
    pair<int,int>val;
    bool lset;
    pair<int,int> set_val;
    node *l, *r;
    node(int _s, int _e, pair<int,int> A[] = NULL): s(_s), e(_e), m((_e+_s)>>1), set_val(make_pair(0,0)), l(NULL), r(NULL){
        if(A==NULL)return;
        if(s==e) val = A[s];
        else{
            l = new node(s,m,A);
            r = new node(m+1,e,A);
            combine();
        }
    }
    void create_children(){
        if(s==e)return;
        if(l != NULL) return;
        l = new node(s,m);
        r = new node(m+1,e);
    }
    void self_set(pair<int,int>valx){
        lset = 1;
        set_val = val = valx;
    }
    void lazy_propagate(){
        if(s==e)return;
        if(lset){
            l->self_set(set_val);
            r->self_set(set_val);
            lset = 0;
            set_val = make_pair(0,0);
        }
    }
    void combine(){
        if(l==NULL)return;
        val = max(l->val,r->val);
    }
    void set(int x, int y, pair<int,int>valx){
        if(s==x&&e==y){
            self_set(valx);
            return;
        }
        create_children();
        lazy_propagate();
        if(x<=m)l->set(x,min(y,m),valx);
        if(y>m)r->set(max(m+1,x),y,valx);
        combine();
    }
    pair<int,int> query(int x, int y){
        if(s==x&&e==y)return val;
        if(l==NULL||lset)return val;
        lazy_propagate();
        if(y<=m)return l->query(x,y);
        if(x>m)return r->query(x,y);
        return max(l->query(x,m),r->query(m+1,y));
    }
    ~node() {
        if (l != NULL) delete l;
        if (r != NULL) delete r;
    }
} *root;

const ll maxn = 1000000000000001;

void solve() {
  ll n, d; cin >> n >> d;
  ll arr[n+10], dp[n+10];
  memset(dp, -1, sizeof(dp));
  root = new node(0ll, 1000000000000000ll);
  for (ll q = 1; q <= n; q++) {
    cin >> arr[q];
  }
  dp[1] = -1; root->set(arr[1], arr[1], {1ll, 1ll});
  for (ll q = 2; q <= n; q++) {
    ll lower = arr[q] - d, upper = arr[q] + d;
    pll ans = root->query(upper, maxn);
    if (lower>=0) ans=max(ans, root->query(0, lower));
    if (ans.second != 0) dp[q] = ans.second;
    else dp[q] = -1;
    root->set(arr[q], arr[q], {ans.first+1, q});
  }
  pll ans = {0, 0};
  for (ll q = 1; q <= n; q++) {
    ans = max(ans, root->query(arr[q], arr[q]));
  }
  cout << ans.first << "\n";
  ll end = ans.second;
  stack<ll> rt;
  while(end!=-1) {
    rt.push(end); 
    end = dp[end];
  }
  while(rt.size()) {
    cout << rt.top() << " "; rt.pop();
  }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  for (ll q = 0; q < tc; q++) {solve();}
}