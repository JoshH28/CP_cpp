// I told you I would come back home
// I know you hate to be alone
// Instead of kissing you goodnight, I'm kissing strangers
// Always listen, but I never learn
// Should've been hanging on your every word
// I was taking you for granted, never realized the danger
// And now I took too long
// And now she's gone
// If I only knew right from wrong
// She'd be right back in my arms
// All I got is you
// All I got is you
// All I got is you
// I always meant to hold you closer
// But I don't always do what I'm supposed to
// Now you're slipping through my fingers, and I don't know what to do
// And I keep hoping you'd call back
// Can we forget about the past
// 'Cause baby all I really want is you
// And now I took too long
// And now she's gone
// If I only knew right from wrong
// She'd be right back in my arms
// All I got is you
// All I got is you
// All I got is you
// 4 A.M. and I can not say goodbye
// Crawling back home, I'd do anything for you
// And I'm sitting up awake, and now I can't forget you
// And I don't know what to do
// All I got is you
// All I got is you
// All I got is you
// All I got is you
// All I got is you
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

unordered_map<ll, ll> lol;
unordered_set<ll> sus;

void solve() {
    ll n, div=1, cnt=0, ans =0, bruh=0; cin >> n >> div;
    ll arr[n], cut[div+1];
    for (ll q = 0; q < n; q++) cin >> arr[q];
    for (ll q = 0; q < div; q++) {cin >> cut[q]; cut[q]-=1;}
    cut[div] = n; sort(cut, cut+div+1);
    for (ll q = 0; q < cut[0]; q++) {
        cnt+=arr[q]; if (cnt == 0) ans++;
    }
    for (ll q = 0; q < div; q++) {
        ll ptr = cut[q],  maxn=0;
        while(ptr < cut[q+1]) {
            cnt+=arr[ptr];
            sus.insert(cnt);
            lol[cnt]++; ptr++;
        } 
        for (auto it: sus) {
            maxn = max(lol[it], maxn);
            lol[it] = 0;
        }
        sus.clear();
        ans+=maxn;
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}