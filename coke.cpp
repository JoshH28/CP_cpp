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

ll dp[3001][3001];
ll n, k;
ll c[3001], sugar[3001];
pair<ll,ll> arr[3001];

bool cmp(pair<ll,ll> one, pair<ll,ll> two) {
    if (one.first*two.second < one.second*two.first) {
        return true;
    } else {
        return false;
    }
}

ll memo(ll index, ll cleft) {
    if (index == n) {return 0;}
    if (cleft < 0) {return 0;}
    if (dp[index][cleft] != -1) {return dp[index][cleft];}
    ll ans = memo(index+1, cleft); //notake
    if (arr[index].second <= cleft) {
        ans = max(ans, memo(index+1, cleft-arr[index].second)+(k-cleft)*arr[index].first);
    } //take if sane enouf
    //cout << ans << " " << index << "\n";
    dp[index][cleft] = ans;
    return ans;
}

void solve() {
    cin >> n >> k;
    for (ll q = 0; q < n; q++) {
        cin >> c[q];
    }
    for (ll q = 0; q < n; q++) {
        cin >> sugar[q];
    }
    for (ll q = 0; q < n; q++) {
        arr[q] = MP(sugar[q],c[q]);
    }
    sort(arr, arr+n, cmp);
    memset(dp, -1, sizeof(dp));
    ll ans = memo(0, k);
    cout << ans;
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}