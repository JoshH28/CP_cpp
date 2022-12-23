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
  ll nn, en, a, b, c; cin >> nn >> en >> a >> b >> c;
  vector<pair<ll,pair<ll,ll>>> adjlist[nn+1];
  for (ll q = 0; q < en; q++) {
    ll t1, t2, t3, t4;
    cin >> t1 >> t2 >> t3 >> t4;
    adjlist[t1].push_back(MP(t2, MP(t3, t4)));
    adjlist[t2].push_back(MP(t1, MP(t3, t4)));
  }
  ll distfa[nn+1];
  priority_queue<pi, vector<pi>, greater<pi> > pq;
  memset(distfa, -1, sizeof(distfa));
  distfa[a] = 0;
  pq.push(make_pair(0, a));
  while (!pq.empty()) {
    pi cur = pq.top();
    pq.pop();
    ll x = cur.second, d = cur.first;
    if (d > distfa[x]) continue;
    for (auto it: adjlist[x]) {
        ll nx = it.first, nd = d+it.second.first;
        if (distfa[nx] != -1 && distfa[nx] <= nd) continue;
        distfa[nx] = nd;
        pq.push(make_pair(nd, nx));
    }
  }
  ll distfc[nn+1];
  memset(distfc, -1, sizeof(distfc));
  distfc[c] = 0;
  pq.push(make_pair(0, c));
  while (!pq.empty()) {
    pi cur = pq.top();
    pq.pop();
    ll x = cur.second, d = cur.first;
    if (d > distfc[x]) continue;
    for (auto it: adjlist[x]) {
        ll nx = it.first, nd = d+it.second.first;
        if (distfc[nx] != -1 && distfc[nx] <= nd) continue;
        distfc[nx] = nd;
        pq.push(make_pair(nd, nx));
    }
  }
  ll distfb[nn+1];
  memset(distfb, -1, sizeof(distfb));
  distfb[b] = 0;
  pq.push(make_pair(0, b));
  while (!pq.empty()) {
    pi cur = pq.top();
    pq.pop();
    ll x = cur.second, d = cur.first;
    if (d > distfb[x]) continue;
    for (auto it: adjlist[x]) {
        ll nx = it.first, nd = d+it.second.first+it.second.second;
        if (distfb[nx] != -1 && distfb[nx] <= nd) continue;
        distfb[nx] = nd;
        pq.push(make_pair(nd, nx));
    }
  }
  ll mn = LONG_LONG_MAX;
  for (ll q = 1; q <= nn; q++) {
    ll cnt = distfa[q]+distfb[q]+distfc[q];
    //cout << cnt << " ";
    mn = min(cnt, mn);
  }
  cout << mn;
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}