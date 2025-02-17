// Youngblood thinks there's always tomorrow
// I miss your touch on nights when I'm hollow
// I know you crossed a bridge that I can't follow
// Since the love that you left is all that I get
// I want you to know
// That if I can't be close to you
// I'll settle for the ghost of you
// I miss you more than life (more than life)
// And if you can't be next to me
// Your memory is ecstasy
// I miss you more than life
// I miss you more than life
// Youngblood thinks there's always tomorrow
// I need more time but time can't be borrowed
// I'd leave it all behind if I could follow
// Since the love that you left is all that I get
// I want you to know
// That if I can't be close to you
// I'll settle for the ghost of you
// I miss you more than life (yeah)
// And if you can't be next to me
// Your memory is ecstasy (oh)
// I miss you more than life
// I miss you more than life
// Whoa
// Na, na-na
// More than life
// (Oh)
// So if I can't get close to you
// I'll settle for the ghost of you
// But I miss you more than life
// And if you can't be next to me
// Your memory is ecstasy
// I miss you more than life
// I miss you more than life
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
    ll n, budget, type, price; cin >> n >> budget;
    vector<ll> yes, no;
    for (ll q = 0; q < n; q++) {
        cin >> type >> price;
        if (type == 1) yes.pub(price);
        else no.pub(price);
    }
    sort(yes.begin(), yes.end()); sort(no.begin(), no.end());
    if (yes.size() && yes[0] <= budget) cout << "Pan will buy a laptop made by Papple that will cost him " << to_string(yes[0]) << ".";
    else if (no.size() && no[0] <= budget) cout << "Pan will buy a laptop not made by Papple that will cost him " << to_string(no[0]) << ".";
    else cout << "NA";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}