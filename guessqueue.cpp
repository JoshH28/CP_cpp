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
    ll qnum, state = 0, t1, t2; 
    queue<long long int>qu;
    priority_queue<ll> pq;
    //priority_queue<ll, vector<ll>, greater<ll>> cancer;
    multiset<ll> cancer;
    ll qtrue = 1;
    ll pqtrue = 1;
    ll fmqtrue = 1;
    cin >> qnum;
    for (ll q = 0; q < qnum; q++) {
        cin >> t1 >> t2;
        if (t1 == 1) {
            qu.push(t2);
            pq.push(t2);
            cancer.insert(t2);
        } else if (t1 == 2) {
            ll qtop = qu.front();
            ll pqtop = pq.top();
            qu.pop();
            pq.pop();
            ll cancertop;
            if (state == 1) {
                state = 0;
                cancertop = *cancer.begin();
                cancer.erase(cancer.find(cancertop));
            } else {
                state = 1;
                cancertop = *cancer.rbegin();
                cancer.erase(cancer.find(cancertop));
            }
            if (t2 != qtop) {
                qtrue = 0;
            } 
            if (t2 != pqtop) {
                pqtrue = 0;
            }
            if (t2 != cancertop) {
                fmqtrue = 0;
            }
        }
    }
    if (fmqtrue+pqtrue+qtrue != 1) {
        cout << "unsure";
    } else if (fmqtrue == 1) {
        cout << "fickle minded priority queue";
    } else if (qtrue == 1) {
        cout << "queue";
    } else if (pqtrue == 1) {
        cout << "priority queue";
    }
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}