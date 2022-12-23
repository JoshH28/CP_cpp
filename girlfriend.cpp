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
}

ll visited[100000];
bool dfs2(int index){
	visited[index]=1; vis2[index]=1;
	for(auto it: adj[index]) {
		if(!visited[it.first] && dfs2(it.first)) return 1;
		else if(vis2[it.first]) return 1;
	} 
	vis2[index]=0;
	return 0;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll nn, en, start, end, t1, t2, t3, ans=-INT_MAX; cin >> nn >> en >> start >> end;
    vector<pair<ll,ll>> adjlist[nn+1];
    for (ll q = 0; q < en; q++) {
        cin >> t1 >> t2 >> t3;
        adjlist[t1].push_back(MP(t2, t3));
    }
    memset(vis2, 0, sizeof(vis2)); memset(visited, 0, sizeof(visited));
    bool ans = dfs2(start);
    if (ans == true) {
        memset(visited, 0, sizeof(visited));
        queue<ll> bfs;
        visited[start] = 1;
        bfs.push(start);
        while(!bfs.empty()) {
            ll cn = bfs.front();
            bfs.pop();
            for (auto it: adjlist[cn]) {
                ll tn = it.first;
                if (visited[tn] == 1) continue;
                bfs.push(tn);
                visited[tn] = 1;
            }
        }
        if (visited[end] == -1) {cout << -1; return 0;}
        else {cout << -2; return 0;}
    }
    queue<pll> pq;
    pq.push(MP(0, start));
    dist[start] = 0; 
    while(!pq.empty()) {
        ll cd = pq.front().first;
        ll cn = pq.front().second;
        if (dist[cn] > cd) continue;
        pq.pop();
        for (auto it: adjlist[cn]) {
            ll tn = it.first; ll td = it.second+cd;
            if (dist[tn] >= td) {continue;}
            if (dist[tn] < td) {
                dist[tn] = td;
                pq.push(MP(td, tn));
            }
        }
    }
    cout << dist[end];
}