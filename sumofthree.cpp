// Oh, oh, oh, oh
// Oh, oh, oh, oh (ah, ah, ah, ah, ah)
// Oh, oh, oh, oh
// Oh, oh, oh, oh (ah, ah, ah, ah, ah)
// I must look dumb, my hands feel clammy
// (Ah, ah, ah, ah, ah)
// Are your cheeks numb from blushing at me?
// (Ah, ah, ah, ah, ah)
// Well, your bangs fit well and your moms alright
// So we talk, talk, talk and we go all night
// If the place clears out, then we can't stay here
// So we walk, walk, walk till we disappear
// Back into the ways things were before
// We change like the weather, apart or together
// It's been 20 years now, it felt like forever
// Well, you come around and I'll pick up where we left her
// Feels like we only get better
// Oh, oh, oh, oh
// Oh, oh, oh, oh (ah, ah, ah, ah, ah)
// My playboy phase, you bought a bunny
// (Ah, ah, ah, ah, ah)
// I dye my grays (I dye my grays) and you think that's funny
// (Ah, ah, ah, ah, ah)
// Well, the rain cuts on and it's bout 3:10
// So we run, run, run like we used to when
// You would turn to me and it all felt fine
// Now it's lost on me 'cause you can't turn time
// Back into the ways things were before
// We change like the weather (weather), apart or together
// It's been 20 years now, it felt like forever
// Well, you come around and I'll pick up where we left her
// Feels like we only get better
// And better, you're my favorite sweater
// And we'll go on forever like weekends in December
// When the snow falls then you call to
// Talk about the weather together
// Oh, oh, oh, oh
// Oh, oh, oh, oh (ah, ah, ah, ah, ah)
// Oh, oh, oh, oh
// Oh, oh, oh, oh (ah, ah, ah, ah, ah)
// We change like the weather, apart or together
// It's been 20 years now, it felt like forever
// When you come around it's just like I remember
// Feels like we only get better
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
    ll n; cin >> n;
    if (n % 3 == 0) {
        if (n <= 9) {cout << "NO\n"; return;}
        cout << "YES\n";
        cout << 1 << " " << 4 << " " << n - 5 << "\n";
    } else if (n % 3 == 1) {
        if (n <= 6) {cout << "NO\n"; return;}
        cout << "YES\n";
        cout << 1 << " " << 2 << " " << n - 3 << "\n";
    } else {
        if (n <= 6) {cout << "NO\n"; return;}
        cout << "YES\n";
        cout << 1 << " " << 2 << " " << n - 3 << "\n";
    }

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}