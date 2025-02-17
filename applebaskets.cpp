// You can have a friend get their heart broke
// And you can be there when they need it most, but
// You won't be the one falling off the deep end
// You can have a friend lose somebody close
// And you can be there when they need it most, but
// You won't be the one having trouble sleeping
// Somebody loses their somebody every day
// But you'll never really know what it's like
// 'Til you wake up to some real bad news
// You'll never really know how it feels
// 'Til it happens to you
// No, you'll never really know what it's like
// Even if you think you do
// You'll never really know how it feels
// 'Til it happens to you
// You can say sorry a million times
// But even if you try, try to sympathize
// You won't be the one picking up the pieces
// You can do your best, call 'em every night
// Listen to 'em say, say they're alright
// But you know there's a chance they don't really mean it
// Somebody loses their somebody every day
// But you'll never really know what it's like
// 'Til you wake up to some real bad news
// You'll never really know how it feels
// 'Til it happens to you
// No, you'll never really know what it's like
// Even if you think you do
// You'll never really know how it feels
// 'Til it happens to you
// You
// 'Til it happens to you
// You'll never really know what it's like
// 'Til you wake up to some real bad news
// You'll never really know how it feels
// 'Til it happens to you
// No, you'll never really know what it's like
// Even if you think you do
// You'll never really know how it feels
// 'Til it happens to you
// 'Til it happens to you
// You
// Somebody loses their somebody
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
    ll n, k, prev=0, leftover = 0; cin >> n >> k;
    ll arr[n+10]; pll copy[n+10];
    for (ll q = 0; q < n; q++) {
        cin >> arr[q]; copy[q].fi = arr[q];
        copy[q].se = q;
    }
    sort(copy, copy+n);
    for (ll q = 0; q < n; q++) {
        if (k < (copy[q].fi - prev)*(n - q)) {
           prev += k / (n-q);
           leftover = k % (n-q);
           break;
        } else {
            k -= (copy[q].fi - prev) * (n-q);
            prev = copy[q].fi;
            arr[copy[q].se] = 0;
        }
    }
    for (ll q = 0; q < n; q++) {
        if (arr[q] != 0) {
            arr[q] -= prev;
            if (arr[q] != 0 && leftover > 0) {
                leftover--; arr[q]--;
            } 
        }
        cout << arr[q] << " ";
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}