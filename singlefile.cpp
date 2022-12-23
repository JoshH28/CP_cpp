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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")
const long long int N = 2*10e6 + 1;
int fw[N], fw2[N];
void update1(ll x, ll y, ll v) { //inclusive
    for (ll tx=x; tx < N; tx += tx&(-tx)) fw[tx] += v, fw2[tx] -= v*(x-1);
    for (ll ty=y+1; ty < N; ty += ty&(-ty)) fw[ty] -= v, fw2[ty] += v*y; 
}
ll sum1 (ll x) {
    ll res = 0;
    for (ll tx=x; tx; tx -= tx&(-tx)) res += fw[tx]*x + fw2[tx];
    return res;
}
ll range_sum1(ll x, ll y) { //inclusive
    return sum1(y)-sum1(x-1);
}

ll fw3[N], fw4[N];
void update2(ll x, ll y, ll v) { //inclusive
    for (ll tx=x; tx < N; tx += tx&(-tx)) fw3[tx] += v, fw4[tx] -= v*(x-1);
    for (ll ty=y+1; ty < N; ty += ty&(-ty)) fw3[ty] -= v, fw4[ty] += v*y; 
}
ll sum2 (ll x) {
    ll res = 0;
    for (ll tx=x; tx; tx -= tx&(-tx)) res += fw3[tx]*x + fw4[tx];
    return res;
}
ll range_sum2(ll x, ll y) { //inclusive
    return sum2(y)-sum2(x-1);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll num, t1, ans=0; cin >> num; ll arr[num];
    ll temp[num];
    for (ll q = 0; q < num; q++) {
        cin >> arr[q];
        temp[q] = arr[q];
    }
    unordered_map<ll,ll> mp;
    sort(temp, temp+num);
    for (ll q = 0; q < num; q++) {
      mp[temp[q]] = q+1;
    }
    for (ll q = 0; q < num; q++) {
      arr[q] = mp[arr[q]];
    }
    for (ll q = 0; q < num; q++) {
        ll one = arr[q];
        ll lessn = range_sum1(0, one);
        ll moren = range_sum2(one, num);
        moren = num-one-moren;
        ll temp = lessn*moren;
        ans += temp;
        update1(one, one, 1);
        update2(one, one, 1);
    }
    cout << ans;
    return 0;
}