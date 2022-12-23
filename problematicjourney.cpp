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
    ll nn, en, maxtime; cin >> nn >> en >> maxtime;
    vector<pair<ll,ll>> adjlist[nn+1];
    for (ll q = 0; q < en; q++) {
        ll t1, t2, qn; cin >> t1 >> t2 >> qn;
        adjlist[t1].push_back(MP(t2, qn));
        adjlist[t2].push_back(MP(t1, qn));
    }
    ll lo = 0; ll hi = 10e9+1;
    while (lo < hi) {
        ll mid = (lo+hi)/2;
        queue<pair<ll,ll>> bfs;
        bfs.push(MP(1, 0));
        ll dist[nn+1];
		memset(dist, -1, sizeof(dist));
        dist[1] = 0;
        bool check = false;
        while (!bfs.empty()) {
            ll cn = bfs.front().first;
            ll d = bfs.front().second;
            bfs.pop();
            if (d > maxtime) continue;
            if (d > dist[cn] && dist[cn] != -1) continue;
            dist[cn] = d;
			if (cn == nn) {
                check = true;
                while (!bfs.empty()) {
                    bfs.pop();
                }
                break;
            }
            for (vector<pair<ll,ll>>::iterator it = adjlist[cn].begin(); it != adjlist[cn].end(); ++it) {
                ll tn = it->first; ll cq = it->second;
                if (cq > mid) continue;
                if (dist[tn] != -1 && dist[tn] < d+1) {continue;}
                bfs.push(MP(tn, d+1)); 
            }
        }
        if (check == true) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if (lo == 10e9+1) {
        cout << -1;
    } else {
        cout << lo;
    }
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}