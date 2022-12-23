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

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
ll r, c, fr, fc, br, bc; cin >> r >> c;
  char grid[r][c]; ll dp[r][c]; ll yes[r][c];
  for (ll q = 0; q < r; q++) {
    for (ll w = 0; w < c; w++) {
      cin >> grid[q][w];
      if (grid[q][w] == 'B') {
        br = q; bc = w;
      } else if (grid[q][w] == 'F') {
        fr = q; fc = w;
      }
      dp[q][w] = INT_MAX;
      yes[q][w] = INT_MAX;
    }
  }
  queue<pair<pair<ll,ll>,ll>>bfs; bfs.push(MP(MP(fr, fc), 0));
  while (!bfs.empty()) {
    ll cy = bfs.front().first.first; ll cx = bfs.front().first.second; ll cnt = bfs.front().second;
    bfs.pop();
    if (dp[cy][cx] <= cnt) {continue;}
    else {
      dp[cy][cx] = cnt;
      if (cy-1 >=0) {bfs.push(MP(MP(cy-1, cx), cnt+1));}
      if (cy+1 < r) {bfs.push(MP(MP(cy+1, cx), cnt+1));}
      if (cx-1 >=0) {bfs.push(MP(MP(cy, cx-1), cnt+1));}
      if (cx+1 < c) {bfs.push(MP(MP(cy, cx+1), cnt+1));}
    }
  }
  bfs.push(MP(MP(br, bc), 0));
  while (!bfs.empty()) {
    ll cy = bfs.front().first.first; ll cx = bfs.front().first.second; ll cnt = bfs.front().second;
    bfs.pop();
    if (yes[cy][cx] <= cnt) {
        continue;
    } else {
      yes[cy][cx] = cnt;
      if (cy-1 >=0 && grid[cy-1][cx] != '@') {bfs.push(MP(MP(cy-1, cx), cnt+2));}
      if (cy+1 < r && grid[cy+1][cx] != '@') {bfs.push(MP(MP(cy+1, cx), cnt+2));}
      if (cx-1 >=0 && grid[cy][cx-1] != '@') {bfs.push(MP(MP(cy, cx-1), cnt+2));}
      if (cx+1 < c && grid[cy][cx+1] != '@') {bfs.push(MP(MP(cy, cx+1), cnt+2));}
    }
  }
  ll ans = INT_MAX;
  for (ll q = 0; q < r; q++) {
    for (ll w = 0; w < c; w++) {
      if (q == 0|| w == 0|| q == r-1 || w == c-1) {
        if (grid[q][w] != '@' && yes[q][w]+2 <= dp[q][w]) {
          ans = min(ans, yes[q][w]+2);
        } 
      }
    }
  }
  if (ans == INT_MAX) {
    cout << -1;
  } else {cout << ans;}
}