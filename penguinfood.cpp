// [Intro]
// (Oh, ah)

// [Verse 1]
// I'm drownin' in my thoughts again tonight
// Not sure that I'm gonna make it out alive
// I broke my heart in pieces, now I'm feelin' like I lost my mind
// Don't know how to keep on going but I'll try

// [Pre-Chorus]
// I lost my perspective, sometimes it's hard
// See how far I've made it out of the dark
// 'Cause half of my world just ran out of my arms
// And healin's the hardest part

// [Chorus]
// I'm breakin' free, I'll cut the tether
// That tried to hold me down
// I got a taste of feelin' better
// Like I could live somehow
// One step, one day at a time
// Getting close, I can see the light
// I'll keep on tryna find my center
// Until I'm back together

// [Drop]
// (Oh, ooh)
// Until I'm back together
// (Yeah, oh-oh)
// Until I'm back together
// (Oh, oh, yeah, no, ooh)
// Until I'm back together
// (Ooh-ooh, ooh)

// [Verse 2]
// Nothing's gonna help to heal the hurt (Ah)
// Long as I keep on believin' I deserve it (Believin' I deserve it)
// Maybe today's the day I'll walk away from takin' all the blame
// 'Cause if I carry it then none of this will change, oh

// [Chorus]
// I'm breakin' free, I'll cut the tether
// That tried to hold me down
// I got a taste of feelin' better
// Like I could live somehow
// One step, one day at a time (One day at a time)
// Getting close, I can see the light (Light)
// I'll keep on tryna find my center
// Until I'm back together (No, ooh)

// [Drop]
// Until I'm back together
// (Yeah)
// (Yeah, oh-oh)
// Until I'm back together
// (Oh, no, oh, ooh, no, oh, ooh)
// Until I'm back together

// [Outro]
// I'll keep on tryna find my center
// Until I'm back together
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

struct node{
    ll start, end, mid; ll value[4];
    node *l, *r;
    node(ll s, ll e) {
        start = s; end =e; mid = (start+end)/2;
        memset(value, 0, sizeof(value));
        if (start != end) {
            l = new node(start, mid);
            r = new node(mid+1, end);
        }
    }

    void pointUpdate(ll pos, ll v) {
        if (start == end) {
            value[0] = v;
            return;
        }
        if (pos <= mid) {l->pointUpdate(pos, v);}
        if (pos > mid) {r->pointUpdate(pos, v);}
        value[0] = l->value[0]+r->value[0]; //value[0] means take both left and right node
        value[1] = max({l->value[0] + r->value[1], l->value[0], l->value[1]});
        value[2] = max({l->value[2] + r->value[0], r->value[0], r->value[2]});
        value[3] = max({l->value[2], r->value[1], r->value[1] + l->value[2], l->value[3], r->value[3]});
    }

    ll query() {
        ll ans = 0;
        for (ll q = 0; q < 4; q++) {ans = max(ans, value[q]);}
        return ans;
    }
}*root;

void solve() {
    ll n, m, t1, t2; cin >> n;
    root = new node(0 ,n-1);
    for (ll q = 0; q < n; q++) {
        cin >> t1; root->pointUpdate(q, t1);
    }
    cout << root->query() << "\n";
    cin >> m;
    for (ll q = 0; q < m; q++) {
        cin >> t1 >> t2;
        root->pointUpdate(t1, t2);
        cout << root->query() << "\n";
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}