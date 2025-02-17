// [Verse 1: Jelly House]
// You got a lot of rizz, don't you, baby?
// I only hawk tuah 'cause you made me
// You're tellin' all your sigmas I'm skibidi
// Like I'm the goated blud
// Why'd you boom or doom if you
// Double chocolate chunk with a chicken bake too
// Livin' in Ohio with the view
// I thought you knew

// [Chorus: Jelly House]
// I had to jelq
// It ain't like I can edge this kinda gyatt all by myself
// Don't act like Ava Tyson doesn't like 'em under twelve
// Been goonin' every weekend if you couldn't tell
// They say, "Mewin' makes the bops twerk"
// Hell, I had to jelq (Jelq)

// [Post-Chorus: Jelly House]
// (Jelq)

// [Verse 2: Elliot Cox]
// You thought I'd break my streak to gеt a blumpkin
// Pick up the phone, can't you see John Pork is callin'?
// Already moggеd the betas, you been muntin'
// Gyatts are gonna have to do
// You think that you got sigma rizz
// We dropped this song before GTA 6
// I ain't a beta, I know how to edge
// Goated like Duke Dennis

// [Chorus: Jelly House]
// I had to jelq
// It ain't like I can edge this kinda gyatt all by myself
// Don't act like Ava Tyson doesn't like 'em under twelve
// Been goonin' every weekend if you couldn't tell
// They say, "Mewin' makes the bops twerk"
// Hell, I had to jelq (Jelq)

// [Post-Chorus: Jelly House]
// (Jelq)
// (Jelq)
// (Jelq)

// [Bridge: Elliot Cox, Jelly House]
// Crash out in the goofy-ahh Backrooms, ooh
// Baby, you bag the fries and, baby, I'll bag 'em too
// Kai Cenat 'bouta goon

// [Chorus: Jelly House]
// I had to jelq
// It ain't like I can edge this kinda gyatt all by myself
// Don't act like Ava Tyson doesn't like 'em under twelve
// Been goonin' every weekend if you couldn't tell
// They say, "Mewin' makes the bops twerk"
// Hell, I had to jelq (Jelq)
// [Post-Chorus: Jelly House]
// (Jelq)
// (Jelq)
// (Jelq)
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
    ll n, m; cin >> n >> m;  ll a[n], b[m];
    for (ll q = 0; q < n; q++) cin >> a[q];
    for (ll q = 0; q < m; q++) cin >> b[q];
    sort(b, b+m); a[0] = min(b[0] - a[0], a[0]);
    for (ll q = 1; q < n; q++) {
        ll diff = a[q] + a[q-1];
        ll wow = lower_bound(b, b+m, diff)-b;
        if (wow == m && a[q] < a[q-1]) {cout << "NO\n"; return;}
        if(a[q] >= a[q-1]) {
            if(wow < m) a[q] = min(a[q], b[wow] - a[q]);
        } else a[q] = b[wow] - a[q];
    }
    //for (ll q = 0; q < n; q++) cout << a[q] << " ";
    cout << "YES\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}