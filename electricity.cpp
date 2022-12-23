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
void solve(ll tcn) {
    ll nn, t1, t2, gm=0; cin >> nn;
    ll capacity[nn+1]; ll visited[nn+1]; 
    ll dp[nn+1];
    memset(dp, -1, sizeof(dp));
    vector<ll> adjlist[nn+1];
    for (ll q = 1; q <= nn; q++) {
        cin >> capacity[q];
    }
    for (ll q = 0; q < nn-1; q++) {
        cin >> t1 >> t2;
        adjlist[t1].push_back(t2);
        adjlist[t2].push_back(t1);
    }
    for (ll q = 1; q <= nn; q++) {
        memset(visited, 0, sizeof(visited));
        queue<pair<ll,ll>> bfs;
        bfs.push(MP(q, capacity[q]));
        ll cnt = 0;
        while (!bfs.empty()) {
            ll cn = bfs.front().first;
            ll en = bfs.front().second;
            bfs.pop();
            if (dp[cn] != -1) {
                cnt += dp[cn];
                while(!bfs.empty()) {
                    bfs.pop();
                }
            }
            else if (visited[cn]==0 && (cn == q||capacity[cn] < en)) {
                visited[cn] = 1;
                cnt += 1;
                for (auto it: adjlist[cn]) {
                    bfs.push(MP(it, capacity[cn]));
                }
                //cout << cn << " ";
            }
        }
        gm = max(gm, cnt);
        dp[q] = cnt;
        cout << cnt << "\n";
    }
    cout << "Case #" << tcn << ": " << gm << "\n";
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve(q+1);}
}