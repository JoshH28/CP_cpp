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

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

void solve() {}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll leng, changen, cost; cin >> leng >> changen;
    ll adjMat[26][26];
    for (ll q = 0; q < 26; q++) {
        for (ll w = 0; w < 26; w++) {
			if (q == w) {adjMat[q][w] = 0;}
			else {
            adjMat[q][w] = LONG_LONG_MAX;
			}
        }
    }
    string str; cin >> str; 
    for (ll q = 0; q < changen; q++) {
        char c1, c2; cin >> c1 >> c2 >> cost;
        ll y1 = (long long int)c1; y1-=97;
        ll y2 = (long long int)c2; y2 -= 97;
        adjMat[y1][y2] = min(cost, adjMat[y1][y2]);
    }

    for (ll k = 0; k < 26; k++) {
        for (ll i = 0; i < 26; i++) {
            for (ll j = 0; j < 26; j++) {
                if (adjMat[i][k] == LONG_LONG_MAX|| adjMat[k][j] ==  LONG_LONG_MAX) continue;
                if (adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) 
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
            }
        }
    }
    ll tc = 0;
    for (ll q = 0; q < (leng/2); q++) {
        ll lmc = LONG_LONG_MAX;
        for (ll w = 0; w < 26; w++) {
            ll lc = adjMat[(long long int)str[q]-97][w];
            ll rc = adjMat[(long long int)str[leng-q-1]-97][w];
            lmc = min(lc+rc, lmc);
        }
        if (lmc == LONG_LONG_MAX) {
            cout << -1; return 0;
        }
        tc += lmc;
    }
    cout << tc; return 0;
}