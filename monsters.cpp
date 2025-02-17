// [Verse 1]
// Oh, oh, I'm gonna use every heartbeat
// Oh, oh, today not tomorrow
// Oh, oh, I'm diving in so deep
// Oh, oh, far from the shallows

// [Chorus]
// Baby, I'm all about headlights
// Blinded by, blinded by headlights
// Running in, running in the headlights
// Light me up, light me up, headlights
// Baby, I'm all about headlights
// Blinded by, blinded by headlights
// Running in, running in the headlights
// Light me up, light me up, headlights

// [Drop]
// Baby, I'm all about headlights
// Hela, hela, headlights
// Hela, hela, headlights
// Hela, hela, headlights
// Baby, I'm all about headlights
// Hela, hela, headlights
// Hela, hela, headlights
// Hela, hеla, headlights

// [Verse 2]
// Oh, oh, I got a taste of the good lifе
// Oh, oh, I'll never let it go
// A wild cat gotta use all my nine lives
// Oh, oh, I'm gonna do it all

// [Bridge]
// And oh, I'm tipping on the edge
// And oh, I don't wanna be saved
// And oh, don't you pull a breaks
// And oh, just take me all the way

// [Chorus]
// Baby, I'm all about headlights
// Blinded by, blinded by headlights
// Running in, running in the headlights
// Light me up, light me up, headlights
// Baby, I'm all about headlights
// Blinded by, blinded by headlights
// Running in, running in the headlights
// Light me up, light me up, headlights

// [Drop]
// Baby, I'm all about headlights
// Hela, hela, headlights
// Hela, hela, headlights
// Hela, hela, headlights
// Baby, I'm all about headlights
// Hela, hela, headlights
// Hela, hela, headlights
// Hela, hela, headlights
// [Outro]
// Oh, oh, I got a taste of the good life
// Oh, oh, I'll never let it go
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

bool cmp(pll a, pll b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void solve() {
    ll n, lvl=0, cnt=0; cin >> n; pll arr[n];
    for (ll q = 0; q < n; q++) {cin >> arr[q].first >> arr[q].second;}
    sort(arr, arr+n);
    priority_queue<pll, vector<pll>, greater<pll>>pq; 
    while(1) {
        while(cnt < n && arr[cnt].first == lvl) {
            pq.push(arr[cnt].second); cnt++;
        }
        while(!pq.empty() && pq.top() < lvl) {pq.pop();}
        if (pq.empty()) break;
        pq.pop(); lvl+=1;
    }
    cout << level;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}