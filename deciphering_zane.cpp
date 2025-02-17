// [Verse 1]
// I've been painting every fence I know
// Every color bleeds into the same
// Cause before you go and walk away
// Yeah, you better know where you're going

// [Chorus]
// Hey yeah, hey yeah
// You're a wanderer just like me
// Hey yeah, hey yeah
// Yeah, you better know where you're going
// Yeah, you better know where you're going

// [Verse 2]
// I've been painting every fence I know
// Every color bleeds into the same
// Cause before you go and walk away
// Yeah, you better know where you're going

// [Chorus]
// Hey yeah, hey yeah
// You're a wanderer just like me
// Hey yeah, hey yeah
// Yeah, you better know where you're going
// You're a wanderer just like me
// Yeah, you better know where you're going
// Hey yeah, hey yeah
// You're a wanderer just like me
// Hey yeah, hey yeah
// Yeah, you better know where you're going
// Yeah, you better know where you're going
// Yeah, you better know where you're going
// You're a wanderer just like me
// Yeah, you better know where you're going
// You're a wanderer just like me
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
#define pq priority_queue
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

void solve() {
    ios_base::sync_with_stdio(false); cin.tie(0); 

    int n; cin>>n;

    string a[12];

    a[1]="no im typing with one hand";

	a[2]="DID U DO UR HW TODAY";	a[3]="when r u confessing";

	a[4]="i will finish my tutorial";

	a[5]="FOUR SCORES AND SEVEN YRS AGO";

	a[6]="In movie alw liddis what";

	a[7]="Victoria";

	a[8]="j i got a function";

	a[9]="what happened to ur productivity";

	a[10]="Actl ltr I will go search ur njc yearbook";

	a[11]="then answer is j brute force all strings?";

	cout<<a[n];
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}