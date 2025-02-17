// Drinking, talking, lying up
// Seeing stars reflected in red cups
// We fall in and out of love
// Just to wind up on the same bus

// And I don't wanna be the one who's gonna point it out (But I know, yeah, I know)
// You've got a tendency to love someone to let 'em down (So when you let me down)

// Take it easy, break me or keep me
// I'll be any shape that you need me
// Tease me, please me, just to release me
// Drove all night to be underneath your bones
// They were shaking, you were cold
// Guess we both need someone to hold
// Is it the worst thing? I don't know
// But when you go

// We've been spinning out these wheels
// Just along for the ride and cheap thrills
// Drop me off and leave me here
// Always counting on the "this time next year"

// 'Cause I don't wanna be the one who's gonna drag it out (No, I don't, no, I don't; ooh), no, no
// I don't need you, I don't blame you when you let me down
// Let me down (Let me down)

// Take it easy, break me or keep me
// I'll be any shape that you need me
// Tease me, please me, just to release me
// Drove all night to be underneath your bones
// They were shaking, you were cold
// Guess we both need someone to hold
// Is it the worst thing? I don't know
// But when you go

// Take it easy
// Just take it easy
// Take it easy
// Just take it easy

// And I don't wanna be the one who's gonna point it out, no
// You've got a tendency to love someone to let 'em down, let me down

// Take it easy, break me or keep me
// I'll be any shape that you need me
// Tease me, please me, just to release me
// Drove all night to be underneath your bones
// They were shaking, you were cold
// Guess we both need someone to hold
// Is it the worst thing? I don't know
// But when you go

// Take it easy
// Just take it easy 
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

vector<vector<ll>> ans;   
vector<vector<ll>> adj;
vector<ll> vis;   
map<ll, ll> mp;           
vector<ll> lol;           

void dfs(ll curr, ll par) {
    if (vis[curr] == 0) lol.pub(curr);
    vis[curr] = 1;              
    for (auto it : adj[curr]) {
        if (it == par || vis[it] == 1) continue;
        dfs(it, curr);     
    }
}

void solve() {
    ll n, t1;
    cin >> n;
    adj = vector<vector<ll>> (n+10);
    vis = vector<ll> (n+10, 0);
    for (ll q = 0; q < n; q++) {
        cin >> t1;
        mp[t1] = q;
    }
    t1 = 0;  
    for (auto it : mp) {
        adj[t1].pub(it.second);
        adj[it.second].pub(t1);
        t1++;
    }
    for (ll q = 0; q < n; q++) {
        if (vis[q] == 0) {
            lol.clear();  
            dfs(q, -1);   
            ans.pub(lol); 
        }
    }
    cout << ans.size() << "\n";  
    for (auto it1 : ans) {
        cout << it1.size() << " ";
        for (auto it2 : it1) {
            cout << it2+1 << " "; 
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for (ll q = 0; q < tc; q++) {
        solve();
    }
}
