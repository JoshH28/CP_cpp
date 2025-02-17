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
#define INT_MAX LONG_LONG_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

void solve() {
    ll nn, en, t1, t2, t3; cin >> nn >> en;
    vector<pll> adjlist[nn+1];
    queue<pll> edges; 
    ll distfs[nn+1]; memset(distfs, inf, sizeof(distfs));
    ll distfe[nn+1]; memset(distfe, inf, sizeof(distfe));
    for (ll q = 0; q < en; q++) {
        cin >> t1 >> t2 >> t3;
        adjlist[t1].push_back(MP(t2, t3));
        adjlist[t2].push_back(MP(t1, t3));
        edges.push(MP(t1, t2));
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(MP(0,1));
    while (!pq.empty()) {
        ll dist = pq.top().first; ll node = pq.top().second;
        pq.pop();
        if (distfs[node] < dist) {continue;}
        for (auto it: adjlist[node]) {
            ll cn = it.first; ll d = it.second+dist;
            if (distfs[cn] <= d) {continue;}
            distfs[cn] = d;
            pq.push(MP(d, cn));
        }
    }
    pq.push(MP(0, nn));
    while (!pq.empty()) {
        ll dist = pq.top().first; ll node = pq.top().second;
        pq.pop();
        if (distfe[node] < dist) {continue;}
        for (auto it: adjlist[node]) {
            ll cn = it.first; ll d = it.second+dist;
            if (distfe[cn] <= d) {continue;}
            distfe[cn] = d;
            pq.push(MP(d, cn));
        }
    }
    ll ans = -INT_MAX;
    while(!edges.empty()) {
        ll x = edges.front().first; 
        ll y = edges.front().second;
        ll dx1 = distfs[x]; ll dx2 = distfe[x];
        ll dy1 = distfs[y]; ll dy2 = distfe[y];
    }
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}