// Da-da
// Da-da, da-da, da-da-nuh
// Yeah, uh
// Drove my car, past your house
// You weren't there, you're far out
// Left a note to your brother
// He called me a motherfucker
// I just hope that you won't really mind
// But I think about you all the time
// You can turn heads like you're a wildfire
// Pain in my chest, you're all I desire
// I've been thinking of you when I'm in the dark
// I could be the one to take you to the stars
// You're beautiful, and I'm a bad liar
// You're all out of luck, and I'm the supplier
// I've been thinking about you whеn I'm all alone
// Do you think of me? I really wanna know, yеah
// Take your time, don't decline
// It would break this heart of mine
// I would take a sucker punch
// To the face, it'd be fun
// I've been fantasizing every night
// I just know that you can make it right
// You can turn heads like you're a wildfire
// Pain in my chest, you're all I desire
// I've been thinking of you when I'm in the dark
// I could be the one to take you to the stars
// You're beautiful, and I'm a bad liar
// You're all out of luck, and I'm the supplier
// I've been thinking about you when I'm all alone
// Do you think of me? I really wanna know
// Take your time, don't decline
// It would break this heart of mine
// And I would take a sucker punch
// To the face, it'd be fun
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
    ll n, m, k, ans=0, extra=0; 
    cin >> n >> m >> k;
    ll arr[n+10];
    for (ll q = 0; q < n; q++) cin >> arr[q];
    sort(arr, arr+n);
    for (ll q = 0; q < n; q++) {
        ans += min(m, k)*(arr[q]+extra);
        extra += m; k -= m;
        if (k <= 0) break;
    }
    cout << ans << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}