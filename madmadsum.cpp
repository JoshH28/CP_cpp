// It's a cold world
// But I'm all right
// I got you, I got you
// To keep me warm like
// Ah, yeah
// Ah, yeah

// Like a long drag
// Off the last hit
// If you're the new pack
// Then I just can't quit
// Ah, yeah
// Ah, yeah

// I spend too much time
// Yeah, all my time
// Worrying about yesterday and
// I've spent all my life
// Hoping things would stay the same

// Baby, everything could change
// In the middle of the night so
// If we make it through today
// Say you'll stay with me tomorrow
// Knowing you could slip away
// Is the hardest pill to swallow
// If we make it through today
// Say you'll stay with me tomorrow
// Tomorrow...

// It's that old car
// It's that dark drive
// Looking back, back on you
// You're the street lights
// Ah, yeah
// Ah, yeah

// And if the hands turn
// If they don't wait
// Tell me this won't burn out
// When the moon fades
// Ah, yeah
// Ah, yeah

// I spend too much time
// Yeah, all my time
// Worrying about yesterday and
// I've spent all my life
// Hoping things would stay the same

// Baby, everything could change
// In the middle of the night so
// If we make it through today
// Say you'll stay with me tomorrow
// Knowing you could slip away
// Is the hardest pill to swallow
// If we make it through today
// Say you'll stay with me tomorrow
// Tomorrow...

// Baby, everything could change
// In the middle of the night so
// If we make it through today
// Say you'll stay with me tomorrow
// Knowing you could slip away
// Is the hardest pill to swallow
// If we make it through today
// Say you'll stay with me tomorrow
// Tomorrow 
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
    ll n, cmax=0; cin >> n; ll arr[n+10], ans=0;
    for (ll q = 0; q < n; q++) cin >> arr[q];
    //do the steps 2 times lol
    unordered_map<ll, ll> one;
    for (ll q = 0; q < n; q++) ans += arr[q];
    for (ll q = 0; q < n; q++) {
        if (one[arr[q]] != 0) {
            cmax = max(cmax, arr[q]);
        }
        one[arr[q]]++;
        arr[q] = cmax;
    }
    unordered_map<ll, ll> two; cmax = 0;
    for (ll q = 0; q < n; q++) ans += arr[q];
    for (ll q = 0; q < n; q++) {
        if (two[arr[q]] != 0) {
            cmax = max(cmax, arr[q]);
        }
        two[arr[q]]++;
        arr[q] = cmax;
    }
    for (ll q = 0; q < n; q++) {
        ans += arr[q] * (n-q);
    }
    cout << ans << "\n";

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}