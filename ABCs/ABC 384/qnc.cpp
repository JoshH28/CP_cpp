/*
Skibidi Skibidi Hawk tuah hawk. 
Skibidi king who gives out blumpkins. 
Edging and Gooning and learning to mint. 
Dropping cheese all over my lunch(ly). 
Skibidi Skibidi Hawk tuah hawk. 
Skibidi boom or Skibidi doom. 
Edging and Gooning in Ohio square. 
Stinky backshot air🔥🔥🔥🗣️
On my grind time, drinkin prime time to mog the ohio away 
Balkan rage time low taper fade time, we go rizzing in the sigma's way 
Griddy up sigma horse stretch out ya meat, griddy around the opps 
Knee surgery's tomorrow and I feel skibidy,
Like a skibidi gyatt
Skibidi Skibidi Hawk tuah hawk. 
Skibidi king who gives out blumpkins. 
Edging and Gooning and learning to mint. 
Dropping cheese all over my lunch(ly). 
Skibidi Skibidi Hawk tuah hawk. 
Skibidi boom or Skibidi doom. 
Edging and Gooning in Ohio square. 
Stinky backshot air🔥🔥🔥🗣️
*/
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

bool cmp(pair<ll, string> p1, pair<ll, string> p2) {
    if (p1.fi == p2.fi) return p1.se < p2.se;
    else return p1.fi > p2.fi;
}

void solve() {
    vector<ll> scores(5);
    for (ll i = 0; i < 5; i++) cin >> scores[i];
    vector<pair<ll, string>> participants;
    string problems = "ABCDE";
    for (ll mask = 1; mask < (1 << 5); mask++) { // bruteforce 2 ^ (1 to 31)
        ll totalScore = 0;
        string name = "";
        for (ll i = 0; i < 5; i++) {
            if (mask & (1 << i)) { // If bit `i` is set
                totalScore += scores[i];
                name += problems[i];
            }
        }
        participants.pub({totalScore, name});
    }
    sort(participants.begin(), participants.end(), cmp);
    for (auto &p : participants) cout << p.second << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}