// Written in these walls are the stories that I can't explain
// I leave my heart open, but it stays right here empty for days
// She told me in the mornin' she don't feel the same about us in her bones
// It seems to me that when I die, these words will be written on my stone

// And I'll be gone, gone tonight (Oh-oh-oh)
// The ground beneath my feet is open wide (Oh-oh-oh)
// The way that I've been holding on too tight (Oh-oh-oh)
// With nothing in between

// The story of my life, I take her home
// I drive all night to keep her warm
// And time is frozen (The story of, the story of)
// The story of my life, I give her hope
// I spend her love until she's broke inside
// The story of my life (The story of, the story of)

// Written on these walls are the colors that I can't change
// Leave my heart open, but it stays right here in its cage
// I know that in the mornin', I'll see us in the light up on the hill
// Although I am broken, my heart is untamed still

// And I'll be gone, gone tonight (Oh-oh-oh)
// The fire beneath my feet is burning bright (Oh-oh-oh)
// The way that I've been holding on so tight (Oh-oh-oh)
// With nothing in between

// The story of my life, I take her home
// I drive all night to keep her warm
// And time is frozen (The story of, the story of)
// The story of my life, I give her hope
// I spend her love until she's broke inside
// The story of my life (The story of, the story of)

// And I've been waiting for this time to come around
// But, baby, running after you is like chasin' the clouds

// The story of my life, I take her home
// I drive all night to keep her warm
// And time is frozen

// The story of my life, I give her hope (I give her hope)
// I spend her love until she's broke inside ('Til she's broke inside)
// The story of my life (The story of, the story of)
// [Outro: All & Harry]
// The story of my life
// The story of my life (The story of, the story of)
// The story of my life
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
    ll n, qn, t1, t2; cin >> n;
    map<ll, pll> mp;
    for (ll q = 0; q < n; q++) {
        cin >> t1 >> t2;
        mp[q+1] = {t1, t2};
    }
    cin >> qn;
    for (ll q = 0; q < qn; q++) {
        cin >> t1 >> t2;
        ll mod = mp[t1].fi, remainder = mp[t1].se;
        if (t2%mod <= remainder) {
            cout << t2 + (remainder - t2%mod) << "\n";
        } else {
            cout << t2 + mod - (t2%mod - remainder) << "\n";
        }
    }

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}