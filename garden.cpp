// Союз нерушимый республик свободных
// Сплотила навеки Великая Русь.
// Да здравствует созданный волей народов
// Единый, могучий Советский Союз!
// Славься, Отечество наше свободное,
// Дружбы народов надёжный оплот!
// Знамя советское, знамя народное
// Пусть от победы к победе ведёт!
// Сквозь грозы сияло нам солнце свободы,
// И Ленин великий нам путь озарил:
// вырастил Сталин — на верность народу,
// труд и на подвиги нас вдохновил!
// Славься, Отечество наше свободное,
// Счастья народов надёжный оплот!
// Знамя советское, знамя народное
// Пусть от победы к победе ведёт!
// Мы армию нашу растили в сраженьях.
// Захватчиков подлых с дороги сметём!
// Мы в битвах решаем судьбу поколений,
// Мы к славе Отчизну свою поведём!
// Славься, Отечество наше свободное,
// Славы народов надёжный оплот!
//Знамя советское, знамя народное
//Пусть от победы к победе ведёт!
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
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
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

void solve() {
    ll nn, en, entrancenum, mintime, t1, t2, t3; 
    cin >> nn >> en >> entrancenum >> mintime;
    unordered_set<ll> entrances;
    for (ll q = 0; q < entrancenum; q++) {
        cin >> t1;
        entrances.emplace(t1);
    }
    vector<pair<ll, ll>> adjlist[nn];
    for (ll q = 0; q < en; q++) {
        cin >> t1 >> t2 >> t3;
        adjlist[t2].push_back(MP(t1, t3));
    }
    ll dist[nn];
    priority_queue<pair<ll, ll> , vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
    memset(dist, -1, sizeof(dist));
    dist[nn-1] = 0;
    pq.push(MP(0, nn-1));
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll cn = pq.top().second;
        pq.pop();
        if (d > dist[cn]) continue;
        for (vector<pi>::iterator it = adjlist[cn].begin(); it != adjlist[cn].end(); ++it) {
            ll nx = it->first, nd = d+1;
            if (dist[nx] != -1 && dist[nx] <= nd) continue;
			dist[nx] = nd;
            pq.push(MP(nd, nx));
        }
    }
    ll cost[nn];
    memset(cost, -1, sizeof(cost));
    cost[nn-1] = 0;
    pq.push(MP(0,nn-1));
    while (!pq.empty()) {
        ll cc = pq.top().first;
        ll cn = pq.top().second;
        pq.pop();
        if (cc > cost[cn]) continue;
        for (vector<pi>::iterator it = adjlist[cn].begin(); it != adjlist[cn].end(); ++it) {
            ll nx = it->first, nc = it->second+cc;
            if (cost[nx] != -1 && cost[nx] <= nc) continue;
			cost[nx] = nc;
            pq.push(MP(nc, nx));
        }
    }
    vector<ll> ans;
    ll mincost=LONG_LONG_MAX;
    for (ll q = 0; q < nn; q++) {
        //cout << dist[it] << " " << cost[it] << "\n";
        if (entrances.find(q) == entrances.end()) {
            cost[q] = LONG_LONG_MAX;
        } else if (dist[q] < mintime) {
            cost[q] = LONG_LONG_MAX;
        } else if (cost[q] < mincost) {
            mincost = cost[q];
        }
    }
    ll cnt=0;
    for (ll q = 0; q < nn; q++) {
        if (cost[q] == mincost && mincost != LONG_LONG_MAX) {
            cout << q << " ";
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << -1;
    }
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}