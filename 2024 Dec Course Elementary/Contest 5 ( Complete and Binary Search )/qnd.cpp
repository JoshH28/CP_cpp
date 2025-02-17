// We looked in the streets and we looked in the woods
// Walked 'til we couldn't no more
// Hung flyers all over the neighborhood
// Left food by the front door

// We told everybody to keep an eye out
// Drove around calling your name
// I can't help but feel like I let you down I miss you every day
// I hope you know how much you mean to me

// It breaks my heart thinking about you out there all alone
// All that I do now is sit by the phone
// Waiting for someone to call
// And tell me they found you in some flowers
// And they'll drop you off in a couple of hours
// It breaks my heart thinking about you alone
// Please come home

// I like to imagine you're doing just fine living the life you deserve
// When I start to think you might not be alright that's when it starts to hurt
// All of your toys are all over our room your blanket is still in the bed
// It hurts 'cause it all just reminds me of you but I can't throw 'em away just yet

// 'Cause it breaks my heart thinking about you
// Out there all alone
// All that I do now is sit by the phone
// Waiting for someone to call
// And tell me they found you in some flowers
// And they'll drop you off in a couple of hours
// It breaks my heart thinking about you alone

// Please come home
// Please come home
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
    ll x, y, z, v; ll ans = 0; 
    cin >> x >> y >> z >> v;
    for (ll q = 1; q <= x; q++) {
        for (ll w = 1; w <= y; w++) {
            if (v % q == 0 && v/q % w == 0) {
                ll mid = (v/(q*w));
                if (mid > z) continue;
                ans = max(ans, (z - mid + 1)*(y - w + 1)*(x - q + 1));    
            }
        }
    }
    for (ll q = 1; q <= x; q++) {
        for (ll w = 1; w <= z; w++) {
            if (v % (w*q) == 0) {
                ll mid = (v / (q*w));
                if (mid > y) continue;
                ans = max(ans, (y- mid + 1)*(z - w + 1)*(x - q + 1)); 
            }
        }
    }
    for (ll q = 1; q <= z; q++) {
        for (ll w = 1; w <= y; w++) {
            if (v % (w*q) == 0) {
                ll mid = (v / (q*w));
                if (mid > x) continue;
                ans = max(ans, (z - q + 1)*(y - w + 1)*(x - mid + 1));
            }
        }
    }
    cout << ans<< "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}