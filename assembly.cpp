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
    ll num; cin >> num;
    ll a1[num], a2[num], l1[num+1], l2[num+1];
    cin >> l1[0] >> l2[0];
    for (ll q = 0; q < num; q++) {cin >> a1[q];}
    for (ll q = 0; q < num; q++) {cin >> a2[q];}
    for (ll q = 1; q < num; q++) {cin >> l1[q];}
    for (ll q = 1; q < num; q++){cin >> l2[q];}
    cin >> l1[num] >> l2[num];
    ll dp1[num]; ll dp2[num];
    dp1[0] = l1[0]+a1[0];
    dp2[0] = l2[0]+a2[0];
    for (int q = 1; q < num; q++) {
        dp1[q] = min(dp1[q-1]+a1[q], dp2[q-1]+a1[q]+l2[q]);
        dp2[q] = min(dp2[q-1]+a2[q], dp1[q-1]+a2[q]+l1[q]);
    }
    cout << min(dp1[num-1]+l1[num], dp2[num-1]+l2[num]);
}

int main() {ll tc=1; /*cin >> tc;*/ for (ll q = 0; q < tc; q++) {solve();}}