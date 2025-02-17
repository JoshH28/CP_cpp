// Another night
// I can't sleep
// Wishing I could
// Skip to my dreams
// Cause the same day
// Stuck on repeat

// I push away from the edge
// Push away all my friends
// I should reach out instead
// But I can't right now
// No, I can't right now

// I've been lost in my head
// Over something that I said
// All these feelings've got me down
// In the deep end
// Trying not to pretend
// Am I losing it again?
// Nothing's even wrong
// There's no reason

// To take it this far
// Till I'm falling apart
// Maybe I'll feel better in the morning?
// Am I making this up?
// Did I fall or did I jump?
// Could you pull me out
// Of the deep end?

// Could you pull me out
// Of the deep end?
// Could you pull me out
// Of the deep end?

// Holding back
// All my tears
// I've been trying
// To face my fears
// Wondering how I keep on
// Finding myself here

// I push away from the edge
// Push away all my friends
// I should reach out instead
// But I can't right now
// No, I can't right now

// I've been lost in my head
// Over something that I said
// All these feelings've got me down
// In the deep end
// Trying not to pretend
// Am I losing it again?
// Nothing's even wrong
// There's no reason

// To take it this far
// Till I'm falling apart
// Maybe I'll feel better in the morning?
// Am I making this up?
// Did I fall or did I jump?
// Could you pull me out
// Of the deep end?

// Could you pull me out
// Of the deep end?
// Could you pull me out
// Of the deep end?

// I've been losing my head
// Over something that I said
// Could you pull me out
// Of the deep end?
// Trying not to pretend
// Am I losing it again?
// Could you pull me out
// Of the deep end? 
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

void solve() {
    ll n, d, sumoftaste=0; cin >> n >> d;
    ll cost[n+10], taste[n+10];
    for (ll q = 0; q < n; q++) {
        cin >> cost[q] >> taste[q];
        sumoftaste += taste[q];
    }
    ll dp[n+10][sumoftaste+10];
    memset(dp, inf, sizeof(dp));
    dp[0][0] = 0;
    for (ll q = 0; q < n; q++) {
        for (ll w = 0; w < sumoftaste; w++) {
            if (dp[q][w]== inf) continue;
            dp[q+1][w] = min(dp[q+1][w], dp[q][w]); // no take case
            dp[q+1][w+taste[q]] = min(dp[q+1][w+taste[q]], cost[q] + dp[q][w]);
        }
    }
    ll ans = -INT_MAX;
    for (ll q = 0; q <= sumoftaste; q++) {
        if (dp[n][q] <= d) {
            ans = max(ans, q);
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