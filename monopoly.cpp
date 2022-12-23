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


int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  ll dp[400001];
  ll rolls[6] = {1,2,3,4,5,6};
  ll mod = 1000000007;
  memset(dp, -1, sizeof(dp));
  dp[0] = 1;
  for (ll q = 0; q < 400000; q++) {
    for (ll w = 1; w <= 6 ; w++) {
        if (dp[q] != -1 && q+w <= 400000) {
          if (dp[q+w] == -1) {
            dp[q+w] = dp[q]%mod;
          } else {
            dp[q+w] = (dp[q+w]%mod)+(dp[q]%mod);
            dp[q+w]%mod;
          }
        }
      }
    }
  for (ll q = 0; q < tc; q++) {
    ll sn, index; char y; cin >> sn >> y >> index;
        ll yes;
        if (y == 'A') {
            yes = index;
        } else if (y == 'B') {
            yes = sn-1+index;
        } else if (y == 'C') {
            yes = (sn-1) + (sn-1) +index;
        } else {
            yes = (3*(sn-1))+index;
        }
    if (yes == (4*sn-4)) {cout << 1 << "\n";}
    else {
        cout << dp[yes]%mod << "\n";
  }
}
  }