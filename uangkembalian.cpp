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
inline int readInt() {
  long long int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9' ) ch = getchar_unlocked();
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar_unlocked();
  }
  return x;
}
void solve() {
  ll target, cn; cin >> cn;
  ll coin[cn]; for (ll q = 0; q < cn; q++) {cin >> coin[q];}
  cin >> target;
  ll dp[target+1];
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (ll q = 0; q < target; q++) {
    if (dp[q] != -1) {
      for (ll w = 0; w < cn; w++) {
        if (q+coin[w] <= target) {
          if (dp[q+coin[w]] == -1) {
            dp[q+coin[w]] = dp[q]+1;
          } else {
            dp[q+coin[w]] = min(dp[q+coin[w]], dp[q]+1);
          }
        }
      }
    }
  }
  cout << dp[target];
}

int main() {ios_base::sync_with_stdio(false);
  cin.tie(NULL);ll tc=1; /*cin >> tc*/; for (ll q = 0; q < tc; q++) {solve();}}