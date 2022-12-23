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

inline long long int read() {
  long long int x = 0;
  char ch = getchar_unlocked();
  while (ch < '0' || ch > '9' ) ch = getchar_unlocked();
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar_unlocked();
  }
  return x;
}

void solve() {
    ll hnum, onum, range, qnum, eatn, max, t1, cnt=0; 
    hnum = read(); onum = read(); range = read(); qnum = read(); eatn = read();
    ll harr[hnum]; ll oarr[onum];
    for (ll q = 0; q < hnum; q++) {
        harr[q] = read();
    } 
    max = harr[hnum-1]; pair<ll,ll> arr[max+1]; ll owls[max+1];
    for (ll q = 0; q < onum; q++) {
        oarr[q] = read();
        owls[oarr[q]] = 1;
    }
    for (ll q = 0; q < hnum; q++) {
        ll curr = harr[q];
        arr[curr] = MP(1, 0);
    }
    for (ll q = 0; q < qnum; q++) {
        t1 = read(); 
        if (arr[t1].first == 1) {
            arr[t1] = MP(1, 0-eatn);
        } 
    }
    ll lptr = 0; ll rptr = range;
    unordered_set<ll> uset;
    for (ll q = 0; q <= range; q++) {
        if (owls[q] == 1) {
            uset.emplace(q);
        }
    }
    if (arr[0].first == 1 && arr[0].second+uset.size() >= 1) {
        cnt += 1;
    }
    arr[0] = MP(arr[0].first, arr[0].second+uset.size());
    while (rptr <= 2*range) {
        rptr += 1;
        if (owls[rptr] == 1) {
            uset.emplace(rptr);
        }
        ll cmid = rptr-range;
        if (arr[cmid].first == 1 && arr[cmid].second+uset.size() >= 1) {
            cnt += 1;
        }
    }
    while (rptr <= max) {
        rptr += 1;
        if (owls[rptr] == 1) {
            uset.emplace(rptr);
        }
        if (uset.find(lptr) != uset.end()) {
            uset.erase(lptr);
        }
        lptr += 1; ll cmid = (rptr-lptr)/2;
        if (arr[cmid].first == 1 && arr[cmid].second+uset.size() >= 1) {
            cnt += 1;
        }
    }
    while (lptr <= max-range) {
        lptr += 1;
        if (uset.find(lptr) != uset.end()) {
            uset.erase(lptr);
        }
        ll cmid = lptr+range;
        if (arr[cmid].first == 1 && arr[cmid].second+uset.size() >= 1) {
            cnt += 1;
        }
    }
    cout << cnt;
    
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}