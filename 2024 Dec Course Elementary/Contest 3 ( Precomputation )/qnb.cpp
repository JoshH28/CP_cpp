// It's a cold world, but I'm alright
// I got you, I got you, keep me warm like
// Like a long drag off the last hit
// If you're the new pack, then I just can't quit
// I spend too much time
// All my time worryin' bout yesterday and
// I've spent all my life
// Hopin' things will stay the same

// Baby, everything could change
// In the middle of the night, so
// If we make it through today
// Say you'll stay with me tomorrow
// Knowing you could slip away
// Is the hardest pill to swallow
// If we make it through today
// Say you'll stay with me tomorrow
// Tomorrow

// It's that old car, it's that dark drive
// Lookin' back, back on you, you're the streetlights
// And if the heads turn, if they don't wait
// Tell me this won't burn out when the moon fadеs
// I spend too much time
// All my time worryin' bout yеsterday and
// I've spent all my life
// Hopin' things will stay the same

// Baby, everything could change
// In the middle of the night, so
// If we make it through today
// Say you'll stay with me tomorrow
// Knowing you could slip away
// Is the hardest pill to swallow
// If we make it through today
// Say you'll stay with me tomorrow
// Tomorrow

// Baby, everything could change
// In the middle of the night, so
// If we make it through today
// Say you'll stay with me tomorrow
// Knowing you could slip away
// Is the hardest pill to swallow
// If we make it through today
// Say you'll stay with me tomorrow
// Tomorrow
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
    ll N, Q; cin >> N >> Q;
    vector<ll> A(N), prefix(N + 1, 0);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        prefix[i + 1] = prefix[i] + A[i];
    }
    while (Q--) {
        ll l, r; cin >> l >> r;
        ll cycles_l = l / N, cycles_r = r / N;
        l %= N; r %= N;
        ll sum = 0;
        if (cycles_l == cycles_r) sum = prefix[r + 1] - prefix[l];
        else sum = prefix[N] - prefix[l] + (cycles_r - cycles_l - 1) * prefix[N] + prefix[r + 1];
        cout << sum << "\n";
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}