//Super idol 的笑容都没你的甜
//八月正午的阳光都没你耀眼
//热爱105度的你
//滴滴清纯的蒸馏水
//你不知道你有多可爱
//跌倒后会傻笑着再站起来
//你从来都不轻言失败
//对梦想的执着一直不曾更改
//很安心
//当你对我说
//不怕有我在
//放着让我来
//勇敢追自己的梦想
//那坚定的模样
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pii pair<int,int>
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
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MAXN = 100050;
const int LOGN = 18;
int p[LOGN+1][MAXN];
vector<int> adjList[MAXN];
bitset<MAXN> visited;
void dfs(int x) {
    if (visited[x]) return;
    visited[x] = 1;
    for (int k = 0; k < LOGN; ++k) {
        if (p[k][x] == -1) break; // if the ancestor does not exist stop
        p[k+1][x] = p[k][p[k][x]]; // otherwise continue checking for the ancestor of the node
    }
    for (auto it:adjList[x]) {
        if (visited[it]) continue;
        p[0][it] = x;
        dfs(it);
    }
}

/* Per query, d-th ancestor of x */
int ancestor(int x, int d) {
    for (int k = 0; k <= LOGN && x != -1; ++k) {
        if (d & (1<<k)) 
            x = p[k][x];
    }
    return x;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1, qn, t1, t2;
  memset(p, -1, sizeof(p));
  cin >> tc;
  for (ll q = 0; q < tc-1; q++) {
    cin >> t1 >> t2;
    adjList[t1].push_back(t2);
    adjList[t2].push_back(t1);
  }
  dfs(0);
  cin >> qn;
  for (ll q = 0; q < qn; q++) {
    cin >> t1 >> t2;
    cout << ancestor(t1, t2) << "\n";
  }
}