// And it feels like (feels like)
// I just wanna be next to you, next to you
// Woo, ooh, ooh, it feels like (feels like)
// I could spend all the rest with you, next to you
// When you wake up at night, don't you wonder why, what does it?
// Is your brain just wired to convince your heart there's something
// Not a book, not a false talk makes sense of it
// You just love it
// And I hope that you
// You're dancing round your room waiting for me
// To come and crash into your life
// But I'm an ocean wave
// I'm still miles away
// And it feels like (feels like)
// I just wanna be next to you, next to you
// Woo, ooh, ooh, it feels like (feels like)
// I could spend all the rest with you, next to you
// When you wake up at night, do you think about my face too? Yeah
// Does your mind see things that your eyes think déjà vu?
// I feel you there, I feel you staring down at me like you're the moon, huh
// Is that you?
// And I know that you
// You're dancing round your room waiting for me
// To come and crash into your life
// But I'm a tidal ocean wave
// I'm still miles away
// And it feels like (feels like)
// I just wanna be next to you, next to you
// Woo, ooh, ooh, it feels like (feels like)
// I could spend all the rest with you, next to you
// Me and you on the stoop shit
// Always feeling brand new shit
// Don't know how, but you do it, do it
// Dreams so vivid they're lucid
// Ending credit type music
// Here's to looking at you kid, you kid
// Woo, ooh, ooh
// And I know that you
// You're dancing round your room waiting for me
// To come and crash into your life like I'm the only wave
// I'm still miles and miles away
// And it feels like (feels like)
// I just wanna be next to you, next to you
// Woo, ooh, ooh, it feels like (feels like)
// I could spend all the rest with you, next to you
// Me and you on the stoop shit
// Always feeling brand new shit
// Don't know how, but you do it, do it
// Dreams so vivid they're lucid
// Ending credit type music
// Here's to looking at you kid, you kid
// Here's looking at you kid
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

bool cmp( pll p1, pll p2) {
    if (p1.se == p2.se) return p1.fi < p2.fi;
    return p1.se < p2.se;
}

void solve() {
    ll n; cin >> n; ll arr[n];
    vector<pll> ans;
    for (ll q = 0; q < n; q++) 
        cin >> arr[q];
    
    for (ll q = n-1; q >= 1; q--) {
        for (ll w = q-1; w >= 0; w--) {
            ans.pub({q+1, w+1});
        }
    }
    for (ll q = 0; q < n; q++) {
        vector<pll> temp;
        for (ll w = q+1; w < n; w++) {
            if (arr[w] > arr[q]) temp.pub({arr[q], arr[w]});
        }
        sort(temp.begin(), temp.end());
        for (auto it: temp) ans.pub(it);
    }
    //sort(ans.begin(), ans.end(), cmp);
    //reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto it: ans) {
        cout << it.fi << " " << it.se << "\n";
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}