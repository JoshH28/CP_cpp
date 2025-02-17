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
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

vector<pll> adjList[100001];
/* Pre-computation using DFS */
const int MAXN = 100050;
const int LOGN = 17;
pll p[LOGN+1][MAXN]; ll h[MAXN];   //h: number of edges from root
long long d[MAXN];     //dist: sum of edge weight from root
bitset<MAXN> visited;
ll dist[MAXN];

void dfs(int x, int depth) {
    if (visited[x]) return;
    visited[x] = 1;
    h[x] = depth;
    ll mx = p[0][x].se;
    for (int k = 0; k < LOGN; ++k) {
        if (p[k][x].fi == -1) break;
        mx += p[k][p[k][x].fi].se;
        p[k+1][x] = MP(p[k][p[k][x].fi].fi, mx);
    }
    for (auto it:adjList[x]) {
        if (visited[it.first]) continue;
        p[0][it.first] = MP(x, it.se);
        dfs(it.first, depth+1);
    }
}

int lca(int a, int b) { //h[a] < h[b]
    if (h[a] > h[b]) swap(a, b);
    /* advance b by h[b] - h[a] parents */
    ll ans = 0;
    for (int k = 0, d = h[b] - h[a]; k < LOGN; ++k) {
        if (d & (1<<k))  {ans += p[k][b].se; b = p[k][b].fi; };
    }
    if (a == b) return ans;
    for (int k = LOGN; k >= 0; --k) {
        if (p[k][a].fi != p[k][b].fi) {
            ans += p[k][a].se; ans += p[k][b].se;
            a = p[k][a].fi, b = p[k][b].fi;
        }
    }
    ans += p[0][a].se; ans += p[0][b].se;
    return ans;
}

void solve() {
    ll nn, en, yes, qn, t1, t2, t3; cin >> nn >> qn;
    memset(h, 0, sizeof(h)); memset(p, -1, sizeof(p));
    for (ll q = 0; q < nn-1; q++) {
        cin >> t1 >> t2 >> t3;
        adjList[t1].push_back(MP(t2, t3));
        adjList[t2].push_back(MP(t1, t3));
    }
    dfs(1, 0);
    for (ll q = 0; q < qn; q++) {
        cin >> t1 >> t2;
        //if (t1 == t2) {cout << 0 << "\n"; continue;}
        ll ans = lca(t1, t2);
        cout << ans << "\n";
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}