#pragma GCC optimize("Ofast,unroll-loops")
// Fighting flames with fire
// Hang onto burning wires
// We don't care anymore
// Are we fading lovers?
// We keep wasting colors
// Maybe we should let this go

// We're falling apart, still we hold together
// We've passed the end, so we chase forever
// 'Cause this is all we know
// This feeling's all we know

// I'll ride my bike up to the road
// Down the streets right through the city
// I'll go everywhere you go
// From Chicago to the coast
// You tell me, "Hit this and let's go
// Blow the smoke right through the window"
// 'Cause this is all we know

// 'Cause this is all we know
// 'Cause this is all we know

// Never face each other
// One bed, different covers
// We don't care anymore
// Two hearts still beating
// On with different rhythms
// Maybe we should let this go

// We're falling apart, still we hold together
// We've passed the end, so we chase forever
// 'Cause this is all we know
// This feeling's all we know

// I'll ride my bike up to the road
// Down the streets right through the city
// I'll go everywhere you go
// From Chicago to the coast
// You tell me, "Hit this and let's go
// Blow the smoke right through the window"
// 'Cause this is all we know

// 'Cause this is all we know
// 'Cause this is all we know
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

ll dirx[4] = {-1, 0, 0, 1};
ll diry[4] = {0, -1, 1, 0};


bool cmp(pll p1, pll p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

void solve() {
    ll childn, fann, r, c, ans=0; cin >> childn >> fann >> r >> c; pll children[childn]; 
    for (ll q = 0; q < childn; q++) cin >> children[q].first >> children[q].second;
    queue<pair<pll, ll>> bfs; ll dist[r][c];
    for (ll q = 0; q < r; q++) {
        for (ll w = 0; w < c; w++) {
            dist[q][w] = INT_MAX;
        }
    }
    sort(children, children+childn, cmp);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    queue<ll> lol;
    for (ll q = 0; q < fann; q++) {
        ll t1, t2; cin >> t1 >> t2;
        t1--; t2--;
        bfs.push({{t1, t2}, 0});
        dist[t1][t2] = 0;
        lol.push(0);
    }  
    //cout << "\n";
    while(!bfs.empty()) {
        ll curry = bfs.front().first.first, currx = bfs.front().first.second, currd = bfs.front().second;
        bfs.pop(); 
        if (dist[curry][currx] != currd) continue;
        //dist[curry][currx] = currd;
        if (curry + 1 < r) {
            if (currd+1 < dist[curry+1][currx]) {
                dist[curry+1][currx] = currd+1;
                bfs.push({{curry+1, currx}, currd+1});
                lol.push(currd+1);
            }
        }
        if (curry - 1 >= 0) {
            if (currd+1 < dist[curry-1][currx]) {
                dist[curry-1][currx] = currd+1;
                lol.push(currd+1);
                bfs.push({{curry-1, currx}, currd+1});
            }
        }
        if (currx + 1 < c) {
            if (currd+1 < dist[curry][currx+1]) {
                lol.push(currd+1);
                dist[curry][currx+1] = currd+1;
                bfs.push({{curry, currx+1}, currd+1});
            }
        }
        if (currx - 1 >= 0) {
            if (currd+1 < dist[curry][currx-1]) {
                lol.push(currd+1);
                dist[curry][currx-1] = currd+1;
                bfs.push({{curry, currx-1}, currd+1});
            }
        }
    }
    ll ptr = 0;
    while (!lol.empty()) {
        while (ptr<childn && children[ptr].first <= lol.front()) {
            pq.push(children[ptr].second); ptr++;
        } 
        while (pq.size() && pq.top()<lol.front()) pq.pop();
        if (pq.size()) {
            ans++; pq.pop();
        }
        lol.pop();
    }
    cout << ans;

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}