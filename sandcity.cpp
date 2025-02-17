// [Verse 1]
// I get scared of what I want
// And everything it takes to love
// So powerless in my own skin (Ah-ah)
// Got me feeling vulnerable
// And never been so exposed
// Tell me if it's how we slip (Ah-ah)

// [Chorus]
// A burning heart still hurts the same
// We run into the open flame
// And I would do it all again (All again, all again)
// If I dive in deep, will we make it through?
// When the fire turns from orange to blue
// No, I don't wanna know the truth
// If loving you means losing you

// [Drop]
// (Losing you, losing you, losing you)
// If loving you means losing you
// (Losing you, losing you, losing you, losing you)

// [Verse 2]
// Hoping love is worth the risk
// 'Cause I let down my guard for this
// Now I'm all in, no turning back (No turning back, no)
// They tell me love's a losing game
// But I don't wanna feel that way
// You can't replace what we have (What we have)

// [Chorus]
// A burning heart still hurts the same
// We run into the open flame
// And I would do it all again (All again, all again)
// If I dive in deep, will we make it through?
// When the fire turns from orange to blue
// No, I don't wanna know the truth
// If loving you means losing you

// [Drop]
// (Losing you, losing you)
// If loving you means losing you
// (Losing you, losing you)
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

void solve() {
    ll r, c, qn, lol; cin >> r >> c >> qn;
    ll arr[r+1][c+1]; ll dp[r+1][c+1];
    memset(dp, 0, sizeof(dp));
    for (ll q = 1; q <= r; q++) {
        for (ll w = 1; w <= c; w++) {
            cin >> arr[q][w];
            dp[q][w] = arr[q][w] + dp[q-1][w];
        }
    }
    for (ll q = 0; q < qn; q++) {
        ll ans = 0;
        for (ll q = 1; q <= c; q++) {
            cin >> lol;
            ans+=dp[lol][q];
        }
        cout << ans << "\n";
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}