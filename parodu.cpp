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
typedef pair<long long int, long long int> pi;
void solve() {
  ll r,c; 
  cin >> c >> r;
  ll grid[r][c]; ll dp[r][c];
  for (ll q = 0; q < r; q++) {
    for (ll w = 0; w < c; w++) {
      cin >> grid[q][w]; 
      dp[q][w] = -1;
    }
  }
  priority_queue<pair<ll,pi>, vector<pair<ll,pi>>, greater<pair<ll,pi>> > bfs;
  bfs.push(MP(0,MP(0,0)));
  dp[0][0] = 0;
  while (!bfs.empty()) {
    ll d = bfs.top().first; 
    ll y = bfs.top().second.first; 
    ll x = bfs.top().second.second; 
    //cout << d << y << x << "\n";
    bfs.pop();
    if (d > dp[y][x] && dp[y][x] != -1) continue;
    if (y-1 >= 0) {
      ll nd = d;
      if (grid[y][x] == 1) {
        nd+=1;
      }
      if (dp[y-1][x] == -1 || dp[y-1][x] > nd) {
        dp[y-1][x] = nd;
        bfs.push(MP(nd,MP(y-1,x)));
      }
    }
    if (y+1 < r) {
      ll nd = d;
      if (grid[y][x] == 1) {
        nd+=1;
      }
      if (dp[y+1][x] == -1 || dp[y+1][x] > nd) {
        dp[y+1][x] = nd;
        bfs.push(MP(nd,MP(y+1,x)));
      }
    }
    if (x+1 < c) {
      ll nd = d;
      if (grid[y][x] == 0) {
        nd += 1;
      }
      if (dp[y][x+1] == -1 || dp[y+1][x] > nd) {
        dp[y][x+1] = nd;
        bfs.push(MP(nd,MP(y,x+1)));
      }
    } 
    if (x-1 >= 0) {
      ll nd = d;
      if (grid[y][x] == 1) {
        nd+=1;
      }
      if (dp[y][x-1] == -1 || dp[y][x-1] > nd) {
        dp[y][x-1] = nd;
        bfs.push(MP(nd,MP(y,x-1)));
      }
    }
}
  cout << dp[r-1][c-1];
}

int main() {ios_base::sync_with_stdio(false);
  cin.tie(NULL);ll tc=1; /*cin >> tc;*/ for (ll q = 0; q < tc; q++) {solve();}}
