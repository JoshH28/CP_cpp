// [Verse 1]
// All of us
// Running 'round the circles till we're out of luck
// Keep on driving, wheels are falling off the bus
// I just can't wrap my head around it, yeah

// [Verse 2]
// Why did I
// See you crying while the trains are passing by?
// Like you don't remember we were feeling high
// Shaking in my arms, yeah, we're falling, hey

// [Pre-Chorus]
// Nights like this, I wish there was some nights like this

// [Chorus]
// Sometimes sunshine, go away
// Don't lie, it's all on your face
// Baby, I know you're cut open
// When the tears fall, I'm leaving you roses
// Sometimes I cry, in the rain
// I don't know why, I'm okay
// Baby, I try not to show it
// Whеn the tears fall, I'm leaving you rosеs

// [Verse 3]
// I can't lie
// It hurts to see you hurting while I'm by your side
// Ceilings caving in inside your room tonight
// You're not picking up when I'm calling
// Yeah, yeah, yeah

// [Verse 4]
// It's cold tonight
// The sky is painted black and now it's closing time
// Wish that you could see yourself through my eyes
// Shaking in your arms, yeah, we're falling, yeah

// [Pre-Chorus]
// Nights like this, I wish there was some nights like this, woo!

// [Chorus]
// Sometimes sunshine, go away
// Don't lie, it's all on your face (It's all on your face)
// Baby, I know you're cut open (Baby, I know you're cut open)
// When the tears fall, I'm leaving you roses (I'm leaving you roses)
// Sometimes I cry, in the rain
// I don't know why, I'm okay
// Baby, I try not to show it (I try not to show it)
// When the tears fall, I'm leaving you roses (Roses)

// [Post-Chorus]
// Sunshine, I leave you roses
// Baby, I know you're cut open
// When the tears fall, I'm leaving you roses

// [Outro]
// Sometimes sunshine, go away
// Don't lie, it's all on your face
// Baby, I know you're cut open
// When the tears fall, I'm leaving you roses
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
    ll n, m, t1; cin >> n >> m;
    priority_queue< ll, vector<ll>, greater<ll> > pq;
    for (ll q = 0; q < n; q++) {
        cin >> t1; pq.push(t1);
    }
    ll ans = 0;
    while (pq.size() && m > 0) {
        if (pq.top() > m) break;
        ans += (pq.top()+1);
        m -= pq.top(); pq.pop();
    }
    cout << ans + m;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}