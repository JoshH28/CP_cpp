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

ll dp[201][201][101];

ll memo(ll index, ll n1, ll n5, ll n10) {
    if (index == 0) {return 0;}
    if (dp[index][n5][n10] != -1) {return dp[index][n5][n10];}
    ll ans = INT_MAX;
    if (n5 >= 2) {
        ans = min(ans, memo(index-1, n1+2, n5-2, n10)+2);
    } if (n10 >= 1) {
        ans = min(ans, memo(index-1, n1+2, n5, n10-1)+1);
    } if (n5 >= 1 && n1 >= 3) {
        ans = min(ans, memo(index-1, n1-3, n5-1, n10)+4);
    } if (n1 >= 8) {
        ans = min(ans, memo(index-1, n1-8, n5, n10)+8);
    } if (n5>=2 && n1 >= 3) {
      ans = min(ans, memo(index-1, n1-3, n5-1, n10)+5);
    } if (n10 >= 1 && n1 >= 3) {
      ans = min(ans, memo(index-1, n1-3, n5+1, n10-1)+4);
    }
    dp[index][n5][n10] = ans;
    return ans;
}

ll solve() {
    ll cn, oc,fc, tn; cin >> cn >> oc >> fc >> tn;
    //memset(dp, -1, sizeof(dp));
    ll ans = memo(cn, oc, fc, tn);
    return ans;
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  memset(dp, -1, sizeof(dp));
  cin >> tc;
  for (ll q = 0; q < tc; q++) {cout << solve() << "\n";}
}