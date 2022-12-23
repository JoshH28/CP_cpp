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

ll n, k;
ll dp[5001][5001][2];
ll hurt[5002];
ll dmg[5002];
ll pain[5002];

ll memo(ll index, ll taken, ll streak) {
    if (index <= 0) {return 0;}
    if (taken <= 0 && streak==1) {return -(INT_MAX/2);}
    if (dp[index][taken][streak]!=-1) {return dp[index][taken][streak];}
    ll ans = 0;
    if (streak == 0) {
        ans = max(memo(index-1, taken, 0), memo(index-1, taken, 1));
    } else {
        ans = memo(index-1, taken-1, 0)+dmg[index]-pain[index]-pain[index+1];
        ans = max(ans, memo(index-1, taken-1, 1)+dmg[index]+(pain[index])-pain[index+1]);
    }
    dp[index][taken][streak] = ans;
    return ans;
}

void solve() {
    cin >> n >> k;
    memset(dp,-1, sizeof(dp));
    pain[0] = 0; pain[n+1] = 0; dmg[n+1] = 0; dmg[0] = 0;
    for (ll q = 1; q <= n; q++) {
        cin >> hurt[q];
    }
    for (ll q = 1; q <= n+1; q++) {
        pain[q] = hurt[q-1]*hurt[q];
    }
    for (ll q = 1; q <= n; q++) {
        cin >> dmg[q];
    }
    ll ans = max(memo(n, k, 0), memo(n, k, 1));
    cout << ans;
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}