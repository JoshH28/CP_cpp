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
    ll r, c; cin >> r >> c;
    ll sr, sc, er, ec;
    char grid[r][c]; ll dist[r][c];
    for (ll q = 0; q < r; q++) {
        for (ll w = 0; w < c; w++) {
            cin >> grid[q][w];
            dist[q][w] = -1;
            if (grid[q][w] == 'S') {
                sr = q; sc = w;
            } else if (grid[q][w] == 'E') {
                er = q; ec = w;
            }
        }
    }
    queue< pair<ll, pair<ll,ll>> > bfs; bfs.push(MP(0, MP(sr, sc)));
    while (!bfs.empty()) {
        ll cd = bfs.front().first;
        ll cr = bfs.front().second.first;
        ll cc = bfs.front().second.second;
        bfs.pop();
        if (dist[cr][cc] != -1 && dist[cr][cc] <= cd) continue;
        dist[cr][cc] = cd;
        if (cr-1 >= 0) {
            if (grid[cr-1][cc] == '.' || grid[cr-1][cc] == 'E') {
                bfs.push(MP(cd+1, MP(cr-1, cc)));
            } else if (grid[cr-1][cc] == '#') {
                if (cr-2 >= 0) {
                    if (grid[cr-2][cc] == '.' || grid[cr-2][cc] == 'E') {
                        bfs.push(MP(cd+1, MP(cr-2, cc)));
                    }
                }
            }
        } 
        if (cr+1 < r) {
            if (grid[cr+1][cc] == '.' || grid[cr+1][cc] == 'E') {
                bfs.push(MP(cd+1, MP(cr+1, cc)));
            } else if (grid[cr+1][cc] == '#') {
                if (cr+2 < r) {
                    if (grid[cr+2][cc] == '.' || grid[cr+2][cc] == 'E') {
                        bfs.push(MP(cd+1, MP(cr+2, cc)));
                    }
                }
            }
        }
        if (cc-1 >= 0) {
            if (grid[cr][cc-1] == '.' || grid[cr][cc-1] == 'E') {
                bfs.push(MP(cd+1, MP(cr, cc-1)));
            } else if (grid[cr][cc-1] == '#') {
                if (cc-2 >= 0) {
                    if (grid[cr][cc-2] == '.' || grid[cr][cc-2] == 'E') {
                        bfs.push(MP(cd+1, MP(cr, cc-2)));
                    }
                }
            }
        }
        if (cc+1 < c) {
            if (grid[cr][cc+1] == '.' || grid[cr][cc+1] == 'E') {
                bfs.push(MP(cd+1, MP(cr, cc+1)));
            } else if (grid[cr][cc+1] == '#') {
                if (cc+2 < c) {
                    if (grid[cr][cc+2] == '.' || grid[cr][cc+2] == 'E') {
                        bfs.push(MP(cd+1, MP(cr, cc+2)));
                    }
                }
            }
        }
    }
    cout << dist[er][ec];
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}