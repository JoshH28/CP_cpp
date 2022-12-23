// 告別了我的禮服和迷霧
// 浪漫的情愫
// 帶著我的領悟和地圖
// 吹熄了蠟燭
// 過去的夢
// 已可以塵封
// 喔 長大的我
// 不再懵懂
// 不要想再哄我
// 再見 從城堡出走
// 再見 從童話掙脫
// 再見 從幻境解鎖
// 再見 丟掉公主tone
// 再見 將泡沫戳破
// 再見 讓故事重頭
// 再見 丟掉公主tone
// 再見
// 再見了
// 再見了
// Goodbye Goodbye Goodbye
// My princess past
// Goodbye
// Goodbye
// 告別了我的禮服和迷霧
// 浪漫的情愫
// 帶著我的領悟和地圖
// 吹熄了蠟燭
// 過去的夢
// 已可以塵封
// 喔 長大的我
// 不再懵懂
// 不要想再哄我
// 再見 從城堡出走
// 再見 從童話掙脫
// 再見 從幻境解鎖
// 再見 丟掉公主tone
// 再見 將泡沫戳破
// 再見 讓故事重頭
// 再見 丟掉公主tone
// 再見
// 再見了
// 再見了
// what am i doing
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

struct edge {
    ll a, b, w;
    edge (ll _a=0, ll _b=0, ll _w=0): a(_a), b(_b), w(_w) {}
};
bool cmp (edge x, edge y) { return x.w < y.w; }
ll pa[100000+1];
ll par(ll x) { return (x==pa[x])?x:pa[x]=par(pa[x]); }
vector<edge> edgeList;
vector<pll> adjList[100001];
/* Pre-computation using DFS */
const int MAXN = 100050;
const int LOGN = 17;
pll p[LOGN+1][MAXN]; ll h[MAXN];   //h: number of edges from root
long long d[MAXN];     //dist: sum of edge weight from root
bitset<MAXN> visited;
ll dist[MAXN];

void dfs(int x, int depth) {
    if (visited[x]) return;
    visited[x] = 1;
    h[x] = depth;
    ll mx = p[0][x].se;
    for (int k = 0; k < LOGN; ++k) {
        if (p[k][x].fi == -1) break;
        mx = max(p[k][p[k][x].fi].se, mx);
        p[k+1][x] = MP(p[k][p[k][x].fi].fi, mx);
    }
    for (auto it:adjList[x]) {
        if (visited[it.first]) continue;
        p[0][it.first] = MP(x, it.se);
        dfs(it.first, depth+1);
    }
}

int lca(int a, int b) { //h[a] < h[b]
    if (h[a] > h[b]) swap(a, b);
    /* advance b by h[b] - h[a] parents */
    ll ans = -INT_MAX;
    for (int k = 0, d = h[b] - h[a]; k < LOGN; ++k) {
        if (d & (1<<k))  {ans = max(ans, p[k][b].se);b = p[k][b].fi; };
    }
    if (a == b) return ans;
    for (int k = LOGN; k >= 0; --k) {
        if (p[k][a].fi != p[k][b].fi) {
            ans = max(ans, p[k][a].se); ans = max(ans, p[k][b].se);
            a = p[k][a].fi, b = p[k][b].fi;
        }
    }
    ans = max(p[0][a].se, ans); ans = max(p[0][b].se, ans);
    return ans;
}

void solve() {
  ll nn, en, yes, qn, t1, t2, t3; cin >> nn >> en >> qn;
  for (ll q = 0; q <= nn; q++) {pa[q] = q;}
  memset(h, 0, sizeof(h));
  for (ll q = 0; q <= LOGN; q++) {
    for (ll w = 0; w < 100001; w++) {
      p[q][w] = MP(-1,-1);
    }
  }
  for (ll q = 0; q < en; q++) {
    cin >> t1 >> t2 >> t3;
    edge temp(t1, t2, t3);
    edgeList.push_back(temp);
  }
  sort(edgeList.begin(), edgeList.end(), cmp);
  ll cnt = 0;
  for (vector<edge>::iterator it = edgeList.begin(); it != edgeList.end(); ++it) {
    if (par(it->a) == par(it->b)) continue;
    pa[par(it->a)] = par(it->b); 
    adjList[it->b].push_back(MP(it->a, it->w));
    adjList[it->a].push_back(MP(it->b, it->w));
  }
  h[0] = 0;
  dfs(0, 0);
  for (ll q = 0; q < qn; q++) {
    cin >> t1 >> t2;
    if (t1 == t2) {cout << 0 << "\n"; continue;}
    ll ans = lca(t1, t2);
    cout << ans << "\n";
  }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}
    