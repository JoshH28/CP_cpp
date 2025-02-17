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
  ll target, num; cin >> target >> num;
  ll coin[num]; pll dp[target+1];
  for (ll q = 0; q < num; q++) {
    cin >> coin[q];
  }
  dp[0] = make_pair(1, 1);
  for (ll q = 1; q <= target; q++) {
    dp[q] = MP(-1,0);
  }
  for (ll w = 0; w < num; w++) {
    ll curr = coin[w];
    for (ll q = 0; q <= target; q++) {
      ll c1 = dp[q].first;
      ll c2 = dp[q].second;
      if (dp[q].first != -1 && q+curr <= target) {
        ll h1 = dp[q+curr].first;
        ll h2 = dp[q+curr].second;
        if (h1 != -1 && h1 > c1+1) {
          dp[q+curr] = MP(c1+1,c2);
        } else if (h1 != -1 && h1 == c1+1) {
          dp[q+curr] = MP(h1, h2+c2);
        } else if (h1 == -1) {
          dp[q+curr] = MP(c1+1, c2);
        }
      }
    }
  }
  if (dp[target].first == -1) {cout << -1;}
  else {
    cout << dp[target].first-1 <<"\n"<< dp[target].second << "\n";
  }
}

int main() {ios_base::sync_with_stdio(false);
  cin.tie(NULL);ll tc=1; /*cin >> tc;*/ for (ll q = 0; q < tc; q++) {solve();}}