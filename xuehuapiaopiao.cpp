// It's like a one way ticket somewhere far away
// It's like the calm in the eye of a hurricane
// It's on the edge of heart beat fast and a heart break
// I wanna take your hand
// I wanna leave tonight
// I don't know what this is
// But it just feels right
// Breathing you in so high
// Think I might crash and die
// 'Cause it feels like falling in love
// Yeah it feels like falling in love
// Yeah it feels like falling in love
// Yeah it feels like falling in love
// And it feels like I wanna jump
// Baby every time that we touch
// 'Cause it feels like falling in love
// Yeah it feels like falling in love
// It feels like falling in love
// It feels like falling in love
// Like falling in love
// Standing still but It's all so fast
// Think you can hold my world in just your hands
// It's on the edge of a burning room and a slow dance
// I wanna take your hand
// And I wanna leave tonight
// I don't know what this is
// But it just feels right
// Breathing you in so high
// Think I might crash and die
// 'Cause it feels like falling in love
// Yeah it feels like falling in love
// Yeah it feels like falling in love
// Yeah it feels like falling in love
// And it feels like I wanna jump
// Baby every time that we touch
// 'Cause it feels like falling in love
// Yeah it feels like falling in love
// It feels like falling in love
// It feels like falling in love
// Like falling in love
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
  unordered_map<ll, vector<ll> > mp;
  ll n, qn, l, r, type; cin >> n;
  for (ll q = 1; q <= n; q++) {
    cin >> type;
    mp[type].pub(q);
  }
  cin >> qn;
  for (ll q = 0; q < qn; q++) {
    cin >> l >> r >> type;
    ll lob = upper_bound(mp[type].begin(), mp[type].end(), l-1)-mp[type].begin();
    ll upb = upper_bound(mp[type].begin(), mp[type].end(), r)-mp[type].begin();
    //cout << lob << " " << upb <<" ";
    cout << upb - lob << "\n";
  }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}