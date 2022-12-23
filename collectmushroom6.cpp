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



void solve() {
    ll r, c, range, harvestn, num=0, cnt=0; char a; cin >> r >> c >> range >> harvestn;
    queue<pair<ll,ll>> mushrooms; 
    ll arr[r+1][c+1]; ll sum[r+1][c+1]; 
    for (ll q = 1; q <= r; q++) {
        for (ll w = 1; w <= c; w++) {
            cin >> a;
            if (a == 'M') {
                mushrooms.push(MP(q,w));
                arr[q][w] = 0;
            } else if (a == 'S') {
                arr[q][w] = 1;
            } else {
                arr[q][w] = 0;
            }
        }
    }
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + arr[i][j];
        }
    }
    while(!mushrooms.empty()) {
        ll y = mushrooms.front().first;
        ll x = mushrooms.front().second;
        mushrooms.pop();
        ll y1 = max(y-range-1, 1ll);
        ll y2 = min(y+range+1, r);
        ll x1 = max(x-range-1, 1ll);
        ll x2 = min(x+range+1, c);
        cnt = sum[y2][x2] - sum[y2][x1] - sum[y1][x2] + sum[y1][x1];
        if (cnt >= harvestn) {
            num += 1;
        }
    }

    cout << num;
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}