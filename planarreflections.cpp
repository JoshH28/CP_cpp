// Some nights, I don't even sleep
// Chest tight with anxiety
// Stay up to see the moon leave the sky
// Some days, I'm not even me
// Same old insecurities
// They tell me there's something going wrong inside
// I've been there, down that road
// When you need me, I'll be here to let you know
// It's gonna be okay
// Everyone needs a bad day
// Remember you told me
// You're not alone, just pick up the phone
// And call me whenever you're feeling lonely
// Remember you told me
// You're not alone, just pick up the phone
// Break down 'cause you're breaking through
// No sky is forever blue
// Things bloom whenever they've seen the rain
// Your thoughts lie, but I know the truth (I know the truth)
// The best days are ahead of you (ahead of you)
// Tomorrow isn't your yesterday
// I've been there, down that road
// When you need me, I'll be here to let you know
// It's gonna be okay
// Everyone needs a bad day
// Remember you told me
// You're not alone, just pick up the phone
// And call me whenever you're feeling lonely
// Remember you told me
// You're not alone, just pick up the phone
// You're not alone, you're not alone
// Pick up the phone, pick up the phone
// You're not alone, you're not alone
// Pick up the phone, pick up the phone (pick up the phone)
// You're not alone, you're not alone (pick up, pick up the phone)
// Pick up the phone, pick up the phone (you're not, you're not alone)
// You're not alone, you're not alone, you're not alone
// It's gonna be okay
// Everyone needs a bad day
// Remember you told me
// You're not alone, just pick up the phone
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

ll dp[1001][1001][2], MOD = 1e9 + 7;
ll n, k;

ll recur(ll plane, ll decay, ll state) {
    if (decay == 1) return 1;
    if (dp[plane][decay][state] != -1) return dp[plane][decay][state];
    ll ans = 2; 
    if (state == 1) {
        if (plane < n) {
            ans += (recur(plane + 1, decay, state) - 1 + MOD) % MOD;
        }
        if (plane > 1) {
            ans += (recur(plane - 1, decay - 1, 1 - state) - 1 + MOD) % MOD;
        }
    } else { 
        if (plane > 1) {
            ans += (recur(plane - 1, decay, state) - 1 + MOD) % MOD;
        }
        if (plane < n) {
            ans += (recur(plane + 1, decay - 1, 1 - state) - 1 + MOD) % MOD;
        }
    }

    ans %= MOD;
    return dp[plane][decay][state] = ans;
}
void solve() {
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << recur(1, k, 1) << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}