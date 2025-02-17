// I know I'm the reason you're hurting
// And I know that I still don't deserve it
// And you know that I'll never be perfect
// I'm trying though
// I see what I am and I hate it
// You give me your heart and I break it
// I don't know how long you can take this
// I need to know
// Do you have faith in me
// Or did I let you down too many times?
// You know I'm trying to be
// A little better now, I never get it right
// And you say it's hard to believe me
// That you can't afford to need me
// I cut you deep, you're running dry
// But do you still have faith in me?
// But do you still have faith in me?
// Do you still have faith in me?
// Faith in me
// Faith in me
// I know that I'm stealing your best years
// Not fair that I ask you to be here
// I'm scared that I'll drown you in my tears
// It's what I do
// I see what I am and I hate it
// Keep failing when I try to change it
// I don't know how long I can take this
// 'Cause it's killing you
// Do you have faith in me
// Or did I let you down too many times?
// You know I'm trying to be
// A little better now, I never get it right
// And you say it's hard to believe me
// That you can't afford to need me
// I cut you deep, you're running dry
// But do you still have faith in me?
// But do you still have faith in me?
// Do you still have faith in me?
// Faith in me
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
    ll n, m, ans = 0, it = 0; cin >> n >> m;
    ll arr[n]; pll vouchers[m];
    priority_queue<ll> pq;
    for (ll q = 0; q < n; q++) {cin >> arr[q]; }
    for (ll q = 0; q < m; q++) {cin >> vouchers[q].first >> vouchers[q].second;}
    sort(vouchers, vouchers+m);
    sort(arr, arr+n);
    //priority_queue<pll, vector<pll>, greater<pll>> pq;
    //ll ans = 0, it = 0;
    for (ll q = 0; q < n; q++) {
        ll discount = 0;
        while(it < m && vouchers[it].first <= arr[q]) {
            pq.push(vouchers[it].second); it++;
            //cout << it << " ";
        }
        ans += arr[q];
        if (!pq.empty()) {
            discount = pq.top(); 
            ans -= discount;
            pq.pop();
        }
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}