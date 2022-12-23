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
    ll nn, sn; cin >> nn >> sn;
    unordered_set<ll> adjlist[nn+1];
    unordered_set<ll> illegal[nn+1];
    bool visited[nn+1];
    for (ll q = 0; q < sn; q++) {
        ll num; cin >> num;
        ll arr[num];
        for (ll q = 0; q < num; q++) {
            ll t1; cin >> arr[q];
        }
        for (ll q = 1; q < num; q++) {
            if (adjlist[arr[q-1]].find(arr[q]) == adjlist[arr[q-1]].end()) {
                if (illegal[arr[q-1]].find(arr[q]) == illegal[arr[q-1]].end())
                    if (illegal[arr[q]].find(arr[q-1]) == illegal[arr[q]].end())
                        adjlist[arr[q]].emplace(arr[q-1]);
            } else {
                adjlist[arr[q-1]].erase(arr[q]);
                illegal[arr[q-1]].insert(arr[q]);
                illegal[arr[q]].insert(arr[q-1]);
            }
        }
        if (adjlist[arr[num-1]].find(arr[0]) == adjlist[arr[num-1]].end()) { 
            if (illegal[arr[num-1]].find(arr[0]) == illegal[arr[num-1]].end())
                if (adjlist[arr[0]].find(arr[num-1]) == illegal[arr[0]].end())
                    adjlist[arr[0]].emplace(arr[num-1]);
        } else {
            adjlist[arr[num-1]].erase(arr[0]);
            illegal[arr[num-1]].insert(arr[0]);
            illegal[arr[0]].insert(arr[num-1]);
        }
    }
    // for (ll q = 1; q <= nn; q++) {
    //     for (auto it: adjlist[q]) {
    //         cout << it << " ";
    //     }
    //     cout << "\n";
    // }
    for (ll q = 1; q <= nn; q++) {
        visited[q] = 0;
    }
    queue<ll> qu;
    qu.push(nn);
    while(!qu.empty()) {
        ll cn = qu.front();
        qu.pop();
        if (visited[cn] == 1) {continue;}
        visited[cn] = 1;
        for (auto it: adjlist[cn]) {
            qu.push(it);
        }
    }
    for (ll w = 1; w <= nn; w++) {
        cout << visited[w] << " ";
    }
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}