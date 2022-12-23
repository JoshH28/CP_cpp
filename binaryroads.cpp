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
typedef pair<long long int, long long int> pi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
void solve() {
    ll nn, en, t1, t2, value; cin >> nn >> en;
    vector<pair<ll,ll>> adjlist[nn];
    for (ll q = 0; q < en; q++) {
        cin >> t1 >> t2 >> value;
        adjlist[t1].push_back(MP(t2, value));
        adjlist[t2].push_back(MP(t1,value));
    }
    ll dist[nn][2];
    priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>> > pq;
    memset(dist, -1, sizeof(dist));
    dist[0][0] = 0;
    pq.push(make_pair(0, MP(0, 0)));
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll cn = pq.top().second.first;
        ll state = pq.top().second.second;
        pq.pop();
        if (d > dist[cn][state]) continue;
        for (vector<pi>::iterator it = adjlist[cn].begin(); it != adjlist[cn].end(); ++it) {
            ll tn = it->first;
            ll tstate = it->second;
            ll sstate;
            if (tstate == 0) {
                sstate = 1;
            } else {
                sstate = 0;
            }
            ll nd = d+1;
            if ((dist[tn][sstate] != -1 && dist[tn][sstate] <= nd)|| (tstate!=state)) continue;
            dist[tn][sstate] = nd;
            pq.push(MP(nd, MP(tn, sstate)));
        }
    }
    ll maxdist;
    if (dist[nn-1][0] == -1 || dist[nn-1][1] == -1) {
        maxdist = max(dist[nn-1][0], dist[nn-1][1]);
    } else {
        maxdist = min(dist[nn-1][0], dist[nn-1][1]);
    }
    memset(dist, -1, sizeof(dist));
    dist[0][1] = 0;
    pq.push(make_pair(0, MP(0, 1)));
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll cn = pq.top().second.first;
        ll state = pq.top().second.second;
        pq.pop();
        if (d > dist[cn][state]) continue;
        for (vector<pi>::iterator it = adjlist[cn].begin(); it != adjlist[cn].end(); ++it) {
            ll tn = it->first;
            ll tstate = it->second;
            ll sstate;
            if (tstate == 0) {
                sstate = 1;
            } else {
                sstate = 0;
            }
            ll nd = d+1;
            if ((dist[tn][sstate] != -1 && dist[tn][sstate] <= nd)|| (tstate!=state)) continue;
            dist[tn][sstate] = nd;
            pq.push(MP(nd, MP(tn, sstate)));
        }
    }
    ll tmdist;
    if (dist[nn-1][0] == -1 || dist[nn-1][1] == -1) {
        tmdist = max(dist[nn-1][0], dist[nn-1][1]);
    } else {
        tmdist = min(dist[nn-1][0], dist[nn-1][1]);
    }
    if (tmdist==-1||maxdist==-1) {
        maxdist = max(tmdist, maxdist);
    } else {
        maxdist = min(tmdist, maxdist);
    }
    cout << maxdist;
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}