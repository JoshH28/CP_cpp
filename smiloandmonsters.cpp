// Good Morning China
// Now i have Bing Chi- Bing Chilling
// bing bing bing bing bing bing bing bing bing
// But Fast and Furious 9 is a very very good movieeeeeeeeeeeeeeeeeeeee
// now it's music time
// infinite Bing
// Bing Chi- Bing Chilling
// infinite Bing again
// Bing Chilling
// Hello Weibo
// rest and eating
// I use my phone to take pictures of many many Lao Gan ma
// Chinese say Laoganma is a culture, so I eat broccoli
// But I have mistakes you have to understand
// im a Laoganma not an AD
// But Fast and Furious and Bing Chilling are ADs
// I don't know Laoganma is a culture, broccoli sus your mom
// I love China and Chinese ok?
// Banned (rly?)
// Every morning, i eat Laoganma
// After 2 weeks, Fast and Furious 9
// I must say now, Fast and Furious 9 have a lot a lot Laoganma
// The movie is so bad
// But you watch Fast and Furious 9 i will give you a lots Bing Chilling and Laoganma
// Good morning China, now i have Bing Chilling Bing Chilling
// But Fast and Furious 9 is better(NB) than Bing Chilling
// I love China and Chinese, There's no problem with that
// Don't forget to watch Fast and Furious
// Because is very good
// I'm Chinese, I love China, I eat Bing Chilling
// But Fast and Furious 9 is better(NB) than Bing Chilling
// Because Fast and Furious 9 is very very good movie
// Music time, All in (Bing Bing Bing Bing)
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
    ll n, lo, ans, hi, cnt;  cin >> n; ll arr[n];
    for (ll q = 0; q < n; q++) cin >> arr[q];
    sort(arr, arr+n); ll bruh = 0; ans=0;
    for (ll q = 0; q < n; q++) bruh+=arr[q];
    ll gay = (bruh+1) / 2, sad = 0;
    for (ll q = 0; q < n; q++) {
        sad += arr[q];
        if (sad > gay) ans++;
    }
    cout << ans + gay << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}