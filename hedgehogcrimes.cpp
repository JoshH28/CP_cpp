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

const ll mod = 998244353;
ll n; ll k;

ll memo[3001][3001];
ll recur(ll cu, ll index) {
    ll ans = 0;
    if (index == 0) {memo[cu][0] = 1; return 1;}
    if (cu+1 < k) {
        if (memo[cu+1][index-1] == -1) {
            ans = recur(cu+1, index-1)%mod;
            memo[cu+1][index-1] = ans;
        } else {
            ans = memo[cu+1][index-1]%mod;
        }
    }
    if (memo[0][index-1]==-1) {
        ll hold = recur(0, index-1)%mod;
        memo[0][index-1] = hold;
        ans += hold;
    } else {
        ans += memo[0][index-1]%mod;
    }
    return ans%mod;
}

void solve() {
    cin >> n >> k;
    for (ll q = 0; q <= k; q++) {
        for (ll w = 0; w <= n; w++) {
            memo[q][w] = -1;
        }
    }
    ll fi =  recur(0, n);
    cout << fi;
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}