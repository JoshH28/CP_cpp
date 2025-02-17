// [Verse 1]
// Darling
// You never really got the best of me
// When we were running through the garden
// We were living on the ecstasy
// So say it
// Just like you said it on the balcony
// You got a tendency to laugh it off
// Tryna hide the insecurities

// [Pre-Chorus]
// I used to open every single door
// But I won't do it anymore
// You told me, now I'm sinking through the floor
// Somehow I knew it

// [Chorus]
// Hold tight
// This could be the last time
// Listening to "Landslide"
// Kissing on the roof (Ooh-oh)
// It's okay
// Even if my hеart breaks
// There's still timе for mistakes
// Burning all the proof (Ooh)

// [Post-Chorus]
// Talking to me, talking to you
// Until my lips are blue
// Fall out of love, fall out of you

// [Verse 2]
// Pardon me
// But were you ever really part of me?
// 'Cause you would leave me in a snap
// And I would never do that

// [Pre-Chorus]
// I used to open every single door
// But I won't do it no more
// You told me, now I'm sinking through the floor
// Somehow I knew it

// [Chorus]
// Hold tight
// This could be the last time
// Listening to "Landslide"
// Kissing on the roof (Ooh-oh)
// It's okay
// Even if my heart breaks
// There's still time for mistakes
// Burning all the proof (Burning all the proof)
// [Post-Chorus]
// Talking to me, talking to you
// Until my lips are blue (Until my lips are blue)
// Fall out of love, fall out of you

// [Outro]
// Yeah, talking to me, I'm talking to you
// Until my lips are blue
// Fall out of love, fall out of you
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
    vector<pair<pll, ll>> spares; 
    ll curr = 0, n, l, r; cin >> n;
    pll arr[n]; ll minn=0, maxx=0;
    for (ll q = 0; q < n; q++) {
        cin >> l >> r;
        arr[q] = {l, r};
        minn += l; maxx += r;
    }
    if (minn>0 || maxx<0) {cout << "No"; return;}
    cout << "Yes\n";
    for (ll q = 0; q < n; q++) {
        ll distance = min(arr[q].se-arr[q].fi, -minn);
        minn += distance;
        cout << arr[q].fi+distance << ' ';
    }

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}