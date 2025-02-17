// [Verse 1]
// When it went down
// It was so hard to breathe
// I gave up everything
// In a slow fall down to the floor
// Life was escaping me
// I couldn't find myself
// 'Til it was all lost
// Not anymore

// [Pre-Chorus]
// I'm holding on to all the pieces of my heart's debris
// 'Til it's time
// I'll, I'll pull it together and fix myself eventually
// And know it's mine

// [Chorus]
// I found gold in the wreckage, put it on a necklace
// Keepin' it 'cause I, I, I, I know that it's mine
// I wear it like a message, so I don't forget it
// Keepin' it 'cause I, I, I, I know that it's mine

// [Post-Chorus]
// I know that it's mine no matter what I do
// I know that it's mine whether I win or lose
// And even though my heart needs to take its time
// I know that it's mine, I know that it's mine

// [Verse 2]
// Facing the change
// But it's still tough to see
// At first, I fought it all
// I was so mean
// I'm still unsure
// How it's supposed to be
// But taking every day now by the skin of my teeth
// Until I learn

// [Pre-Chorus]
// I'm holding on to all the pieces of my heart's debris
// 'Til it's time
// I'll, I'll pull it together and fix myself eventually
// And know it's mine

// [Chorus]
// I found gold in the wreckage, put it on a necklace
// Keepin' it 'cause I, I, I, I know that it's mine
// I wear it like a message, so I don't forget it
// Keepin' it 'cause I, I, I, I know that it's mine

// [Post-Chorus]
// I know that it's mine no matter what I do
// I know that it's mine whether I win or lose
// And even though my heart needs to take its time
// I know that it's mine, I know that it's mine
// [Chorus]
// I found gold in the wreckage, put it on a necklace
// Keepin' it 'cause I, I, I, I know that it's mine
// I wear it like a message, so I don't forget it
// Keepin' it 'cause I, I, I, I know that it's mine

// [Post-Chorus]
// I know that it's mine no matter what I do
// I know that it's mine whether I win or lose
// And even though my heart needs to take its time
// I know that it's mine, I know that it's mine
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
    ll n, k, a, b; cin >> n >> k >> a >> b;
    ll curr = n, ans = 0;
    if (k == 1) {cout << a*(curr-1); return;}
    while (curr > 1) {
        if (curr%k == 0) {
            ans += min(b, (curr - (curr/k))*a);
            curr/=k;
        } else {
            if (curr < k) {
                ans += (curr - 1)*a;
                curr = 1;
            } else {
                ans += (curr%k)*a;
                curr = k*(curr/k);
            }
        }
        //cout << curr << " " << ans << "\n";
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}