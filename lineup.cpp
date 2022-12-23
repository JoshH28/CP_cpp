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
typedef long long int ll;
void solve() {
  ll num, t1,t2, lp = 0, rp = 1;
  cin >> num;
  vector <pair<ll,ll>> arr;
  unordered_set<ll> cu;
  for (ll q = 0; q < num; q++) {
    cin >> t1 >> t2;
    arr.push_back(MP(t1,t2));
    cu.insert(t2);
  }
  ll ut = cu.size();
  sort(arr.begin(), arr.end());
  unordered_set<ll> ac;
  ac.insert(arr[0].second);
  unordered_map<ll,ll> mp;
  mp[arr[0].second] = 1;
  ll ans = INT_MAX;
  while (lp < rp) {
     if (ac.size() < ut && rp < num ){
       mp[arr[rp].second] += 1;
       ac.insert(arr[rp].second);
       //cout << mp[arr[rp].second] << " ";
       rp+=1;
     } else {
       mp[arr[lp].second] -= 1;
       //cout << mp[arr[lp].second] << " ";
       if (mp[arr[lp].second] <= 0) {
         ac.erase(arr[lp].second);
       }
       lp+=1;
     }
      if (ac.size() >= ut && arr[rp].first - arr[lp].first >= 1) {
       ans = min(ans, arr[rp-1].first - arr[lp].first);
      }
      //cout << lp << " " << rp << " " << arr[rp-1].first - arr[lp].first << endl;
    }
  cout << ans;
}

int main() {ios_base::sync_with_stdio(false);
  cin.tie(NULL);ll tc=1; for (ll q = 1; q <= tc; q++) {solve();}}