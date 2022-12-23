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
#define pi pair<int,int>
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
typedef long long unsigned ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
void solve() {
    ll qnum, leftn=0, rightn=0, t1, t2; cin >> qnum;
    deque<ll> dq;
    unordered_map<ll,ll> left;
    unordered_map<ll,ll> right;
    for (ll q = 0; q < qnum; q++) {
        cin >> t1;
        if (t1 == 1) {
            cin >> t2;
            leftn+=1;
            left[t2] = leftn;
            dq.push_front(t2);
        } else if (t1 == 2) {
            cin >> t2;
            rightn+=1;
            right[t2] = rightn;
            dq.push_back(t2);
        } else if (t1 == 3) {
            left.erase(dq.front());
            leftn-=1;
            dq.pop_front();
        } else if (t1 == 4) {
            right.erase(dq.back());
            rightn-=1;
            dq.pop_back();
        } else if (t1 == 5) {
            cin >> t2;
            ll ans = 0;
            if (right[t2] != 0) {
                cout << leftn+right[t2] << "\n";
            } else {
                cout << leftn-left[t2]+1 << "\n";
            }
        } else if (t1 == 6) {
            cin >> t2;
            ll ans = 0;
            if (left[t2] != 0) {
                cout << rightn+left[t2] << "\n";
            } else {
                cout << rightn-right[t2]+1 << "\n";
            }
        } 
        
    }
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}