// [Verse 1]
// We were both unc when I clip farmed you
// I bagged my fries and said, "Senator, I'm Singaporean"
// On a balcony that's [?]
// See the gyatts, "FE!N" with Carti, the crash outs
// See Ye Squad link up with Bop House
// And say, "Ohio"
// A friggin' packet yo

// [Pre-Chorus]
// That you were DomTheTroll, you were throwing mangoes
// Batman daddy said, "I'm so fucking pissed"
// And I was Burger King for lettuce
// Edging you, those who know, and I said

// [Chorus]
// Skibidi rizz me, John Pork please pick up the phone
// I'll be mewing, rizzing up the sigma huzz
// You'll be chopped chin and I'll be Chris VFX
// It's a rizz story, baby, just say ts

// [Verse 2]
// I jelq it out in Ohio to meme you
// We keep clickin' 'cause the commеnts are blue
// So bag your fries
// Gifting galaxiеs on TikTok Live, Ohio

// Jelly House
// [Pre-Chorus]
// 'Cause you were DomTheTroll, I was a fade, low taper
// Batman daddy said, "I'm so fucking pissed"
// But you were FN green to me
// I was edging you, those who know, and I said

// [Chorus]
// Skibidi rizz me, John Pork please pick up the phone
// I'll be mewing, rizzing up the sigma huzz
// You'll be chopped chin and I'll be Chris VFX
// It's a rizz story, baby, just say ts
// Skibidi rizz me, they're trying to meme Shaqkoi O'Neil
// RedNote is difficult, but I'll scroll Reels
// Mousepay prepaid, we'll quit it, too many sweats
// It's a rizz story, baby, just say ts

// [Post-Chorus]
// Ohio

// [Bridge]
// I got tired of rage baiting
// Wondering if you were landing Tomato Town
// My low taper was fading
// When I bought property in Egypt now, and I said

// [Chorus]
// "Skibidi rizz me, that's how aura farming goes
// I'm chicken baking for you, but you never boom
// Locked-in alien, it's Prime, what I drink"
// He used TikTok sounds and pulled up a meme, and said
// "Johnnie Walker, Tristan Tate, you'll never have to sip alone
// I hawk tuah and that's all I really know
// I talked to your dad, go pick you up from Asher's house
// It's a rizz story, baby, just say ts"
// [Outro]
// Ohio
// Ohio
// 'Cause we were both unc when I clip farmed you
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

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; //to do 4dir skip every odd index
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //to do 4dir skip every odd index

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

ll findsumofdigits(ll num) {
    ll ans = 0;
    while (num > 0) {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

void solve() {
    ll n, qn; cin >> n >> qn;
    root = new node(0, n+10); ll arr[n+10];
    for (ll q = 1; q <= n; q++) cin >> arr[q];
    for (ll q = 1; q <= qn; q++) {
        ll one, two, three; cin >> one;
        if (one == 1) {
            cin >> two >> three;
            root->add(two, three, 1);
        } else {
            cin >> two; 
            for (ll q = 0; q < root->range_sum(two, two); q++) {
                arr[two] = findsumofdigits(arr[two]);
                if (arr[two] == findsumofdigits(arr[two])) break;
            }
            root->set(two, two, 0); cout << arr[two] << "\n";
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}