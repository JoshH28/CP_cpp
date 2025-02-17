// You couldn't keep your eyes from wandering
// Crazy how you still couldn't see, oh yeah
// Everything you ever wanted
// Was everything that I tried to be, oh yeah
// Do you get high when you kiss her?
// When she leaves, do you miss her?
// If it all feels familiar
// Would you know? Would you know?
// If the one that was meant for you
// The best that you'll ever do
// Was standing right in front of you
// Would you even know? Would you even know? Would you even know?
// Would you even know? Would you even know? Would you even know?
// Would you even know? Would you even know? Would you even know?
// Would you even know? Would you even know? Would you even know?
// Would you even know? Would you even know? Would you even know?
// My heart's bleeding out, it doesn't faze you
// Tell me, baby, were we a lie? Oh
// I still hear the sound of bottles breaking
// And you said, "One day, we'll be fine"
// Do you get high when you kiss her?
// When she leaves, do you miss her?
// If it all feels familiar
// Would you know? Would you know?
// If the one that was meant for you
// The best that you'll ever do
// Was standing right in front of you
// Would you even know? Would you even know? Would you even know?
// Would you even know? Would you even know? Would you even know?
// Would you even know? Would you even know? Would you even
// Would you even know? Would you even know? Would you even know?
// Would you even know? Would you even know?
// Do you get high when you kiss her?
// When she leaves, do you miss her?
// If it all feels familiar
// Would you know? Would you know?
// If the one that was meant for you
// The best that you'll ever do
// Was standing right in front of you
// Would you even know? Would you even know? Would you even know?
#include "graphcraft.h"
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

static int N, C;
static vector< pair<int, int> > V[100000];

ll mod = 1000000007;
// bool vis1[100001], vis2[100001], finalCheck[100001];
vector<pll> adjlist[100001];
// bool dfs(int index){ // returns true if there is a cycle in the disjoint subgraph of index
// 	vis1[index]=1; vis2[index]=1;
// 	for(auto it: adjlist[index]) {
// 		if(!vis1[it.first] && dfs(it.first)) return 1;
// 		else if(vis2[it.first]) return 1;
// 	} 
// 	vis2[index]=0;
// 	return 0;
// } 




// // unordered_map<ll, unordered_set<ll> > children;

// // stack<ll> topo;
// // bool visitedTopo[100001];
// // void topoSort(ll index) {
// //     visitedTopo[index] = true;
// //     for (auto it: adjlist[index]) {
// //         if (visitedTopo[it.first]) continue;
// //         topoSort(it.first);
// //     }
// //     topo.push(index);
// // }


ll dp[100001];
ll n, c;
ll memo(ll cn, ll counter=0) {
    if (cn == 0) return 1;
    if (dp[cn] != 0) return dp[cn];
    ll sum = 0;
    if (counter > 2*n) return -1;
    for (auto it: adjlist[cn]) {
        ll lol = memo(it.first, counter+1);
        if (lol == -1) {return -1;}
        sum += (lol%mod*it.second%mod)%mod;
        sum%=mod;
    }
    return dp[cn] = sum;
}


signed graphcraft(int N, int C, vector< pair<int, int> > V[]) {
    ll ans = 0; ll dp[N+1];
    for (ll q = 0; q < N; q++) {
        for (auto it: V[q]) {
            adjlist[q].pub(it);
        }
    }
    n = N; c = C;
    memset(dp,0, sizeof(dp));
    return memo(C);
    // memset(vis1, 0, sizeof(vis1));
    // memset(vis2, 0, sizeof(vis2));
    // memset(visitedTopo, 0, sizeof(visitedTopo));
    // memset(finalCheck, 0, sizeof(finalCheck));
    // bool checking = dfs(0);
    // if (checking == 1) return -1;
    // // else if (vis1[C] == false) {
    // //     return -1;
    // // }
    // topoSort(0);
    // for (ll q = 0; q < N; q++) {
    //     dp[q] = 0;
    //     //if (vis1[q] == false) {finalCheck[q] = 1;}
    // }
    // dp[0] = 1;
    // //finalCheck[0] = 1;
    // //topo.pop();
    // while(!topo.empty()) {
    //     ll cn = topo.top();
    //     topo.pop();
    //     for (auto it: adjlist[cn]) {
    //         ll tn = it.first, dist = it.second%mod * dp[cn]%mod; dist%=mod;
    //         dp[tn] += dist;
    //         dp[tn]%=mod;
    //         children[tn].erase(cn);
    //     }
    //     //cout << cn << " " << dp[cn] << "\n";
    // }
    // if (!children[C].empty()) return -1;
    // return dp[C];
}

signed main() {
    scanf("%d%d", &N, &C);
    for ( int i = 1; i < N; i++ ) {
        int T;
        scanf("%d", &T);
        for ( int j = 0; j < T; j++ ) {
            int A, B;
            scanf("%d%d", &A, &B);
            V[i].push_back(make_pair(A, B));
        }
    }
    printf("%d\n", graphcraft(N, C, V));
    return 0;
}
