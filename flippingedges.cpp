// When things are right, then you just know
// There is something in your eyes that brings me home
// 'Cause when there's love, you don't let go
// So as long as you're with me you're not alone, you'll never be
// I wanna tell you what I feel and really mean it
// I wanna shout it from the rooftops to the sky
// 'Cause if you ever need a friend, you know I'll be it
// From tonight until we see the end of time
// I'll cross my heart
// And hope to die
// We're always and forever, I'll be by your side
// When days are dark
// And stars don't line
// We're always and forever 'til the end, the end of time
// When we look back, to when we're old
// We'll see your footprints next to mine along the road
// And I don't know, what the future holds
// But as long as you're with me, you're not alone, you'll never be
// I wanna tell you what I feel and really mean it
// I wanna shout it from the rooftops to the sky
// 'Cause if you ever need a friend, you know I'll be it
// From tonight until we see the end of time
// I'll cross my heart
// And hope to die
// We're always and forever, I'll be by your side
// When days are dark
// And stars don't line
// We're always and forever 'til the end, the end of time
// Put your hands to the sky
// Always and forever by our side
// Always and forever 'til the end of time
// I'll cross my heart
// And hope to die
// We're always and forever, I'll be by your side
// When days are dark
// And stars don't line
// We're always and forever 'til the end, the end of time
// The end of time
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
    ll n, en, maxLength, t1, t2, t3, ans = -1; cin >> n >> en >> maxLength;
    vector<pair<ll, pll>> adjlist[n+10];
    for (ll q = 0; q < en; q++) {
        cin >> t1 >> t2 >> t3;
        adjlist[t1].pub({t2, {0, t3}});
        adjlist[t2].pub({t1, {1, t3}});
    }
    ll dist[n+10][en+10];
    priority_queue< pair<pll, ll>, vector<pair<pll, ll>>, greater<pair<pll, ll>> > pq; 
    for (ll q = 0; q <= n; q++) {
        for (ll w = 0; w <= en; w++) {
            dist[q][w] = INT_MAX;
        }
    }
    pq.push({{0, 0}, 1});
    dist[1][0] = 0; 
    while(pq.size()) {
        ll cd = pq.top().first.first, flipn = pq.top().first.second, cn = pq.top().second;
        //cout << cn << " " << flipn << " " << cd << "\n";
        pq.pop(); 
        if (dist[cn][flipn] < cd) continue;
        for (auto it: adjlist[cn]) {
            ll tn = it.first, tf = flipn+it.second.first, td = cd + it.second.second;
            if (dist[tn][tf] <= td) continue;
            if (tf > en) continue;
            dist[tn][tf] = td;
            pq.push({{td, tf}, tn}); 
        }
    }
    //cout << n;
    for (ll q = 0; q <= en; q++) {
        //cout << dist[n][q] << " ";
        if (dist[n][q] <= maxLength) {
            if (ans == -1) ans = q;
            else ans = min(ans, q);
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