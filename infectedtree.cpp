// [Verse 1: Andrew Taggart]
// We were stayin' in Paris
// To get away from your parents
// And I thought, "Wow
// If I could take this in a shot right now
// I don't think that we could work this out"
// Out on the terrace
// I don't know if it's fair, but I thought, "How
// Could I let you fall by yourself
// While I'm wasted with someone else?"

// [Chorus: Andrew Taggart]
// If we go down, then we go down together
// They'll say you could do anything
// They'll say that I was clever
// If we go down, then we go down together
// We'll get away with everything
// Let's show them we are better

// [Refrain: Andrew Taggart]
// Let's show them we are better
// Let's show them we are better

// [Verse 2: Andrew Taggart]
// We were stayin' in Paris
// To get away from your parents
// You look so proud
// Standing there with a frown and a cigarette
// Postin' pictures of yourself on the Internet
// Out on the terrace
// We breathe in the air of this small town
// On our own, cuttin' class for the thrill of it
// Gettin' drunk on the past we were livin' in

// [Chorus: Andrew Taggart & Emily Warren]
// If we go down, then we go down together
// They'll say you could do anything
// They'll say that I was clever
// If we go down, then we go down together
// We'll get away with everything
// Let's show them we are better

// [Bridge: Emily Warren & Andrew Taggart]
// Let's show them we are, show them we are
// Let's show them we are, show them we are
// Let's show them we are better
// We were stayin' in Paris
// Let's show them we are better
// Let's show them we are, show them we are
// Let's show them we are, show them we are
// Let's show them we are better

// [Chorus: Andrew Taggart & Emily Warren]
// If we go down, then we go down together
// They'll say you could do anything
// They'll say that I was clever
// If we go down, then we go down together
// We'll get away with everything
// Let's show them we are better
// [Post-Chorus: Andrew Taggart & Emily Warren]
// We were stayin' in Paris (If we go down)
// We were stayin' in Paris (If we go down)
// We were stayin' in Paris (If we go down)
// We were stayin' in Paris (If we go down)
// Let's show them we are better
// We were stayin' in Paris

// [Drop: Andrew Taggart & Emily Warren]
// Let's show them we are better
// Let's show them we are better
// If we go down
// Let's show them we are better
// If we go down
// Let's show them we are better
// If we go down
// Let's show them we are better
// Let's show them we are better
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

vector<ll> adjlist[500005];

ll preorder[500005], postorder[200005], dist[500005];
ll counter = 0;

ll dfs(ll x, ll p) {
    if (dist[x] != -1) return dist[x];
    ll size = 1;
    for (auto it: adjlist[x]) {
        if (it == p) continue;
        size += dfs(it, x);
    }
    dist[x] = size;
    return size;
}

ll memo(ll currnode, ll par) {
    ll ans = 0;
    vector<ll> sizes;
    for (auto it: adjlist[currnode]) {
        if (it == par) continue;
        sizes.pub(dfs(it, currnode) - 1);
    }
    if (sizes.size() == 1) {
        ans += (sizes[0]);
    } else if (sizes.size()) {
        ll gay = 1;
        for (auto it:adjlist[currnode]) {
            if (it == par) continue;
            ans = max(ans, memo(it, currnode) + sizes[gay]);
            gay--;
        }
    } else {
        return 0;
    }
    //cout << currnode << " " << ans << "\n";
    return ans;
}

void solve() {
    ll n, t1, t2; cin >> n;
    memset(dist, -1, sizeof(dist));
    for (ll q = 0; q <= n+10; q++) {
        adjlist[q].clear();
    }
    for (ll q = 0; q < n-1; q++) {
        cin >> t1 >> t2;
        adjlist[t1].pub(t2);
        adjlist[t2].pub(t1);
    }
    // cout << "\n";
    // cout << dfs(4, 1) << " " << dfs(2, 4) << "\n";
     cout << memo(1, -1) << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}