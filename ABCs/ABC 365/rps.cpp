// Monday left me broken
// Tuesday I was through with hopin'
// Wednesday my empty arms were open
// Thursday waiting for love, waiting for love
// Thank the stars it's Friday
// I'm burning like a fire gone wild on Saturday
// Guess I won't be coming to church on Sunday
// I'll be waiting for love
// Waiting for love to come around
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

string winner(char bruh) {
    if (bruh == 'S') return "R";
    else if (bruh == 'R') return "P";
    else return "S";
}

void solve() {
    ll n; cin >> n; string arr; cin >> arr;
    string choices = "RPS"; ll dp[n+10][5];
    unordered_map<string, ll> mp; mp["R"] = 0;
    mp["P"] = 1; mp["S"] = 2;
    memset(dp, 0, sizeof(dp));
    dp[0][mp[winner(arr[0])]] = 1;
    for (ll w = 0; w < 3; w++) {
        if (choices[w] == winner(arr[0])[0]) continue;
        else if (choices[w] == arr[0]) dp[0][w] = 0;
    }
    for (ll q = 1; q < n; q++) {
        for (ll w = 0; w < 3; w++) {
            if (choices[w] == winner(arr[q])[0]) {
                for (ll r = 0; r < 3; r++) {
                    if (w == r) continue;
                    dp[q][w] = max(dp[q][w], (dp[q-1][r] +1));
                }
            } else if (choices[w] == arr[q]) {
                for (ll r = 0; r < 3; r++) {
                    if (w == r) continue;
                    dp[q][w] = max(dp[q][w], dp[q-1][r]);
                }
            }
        }
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}