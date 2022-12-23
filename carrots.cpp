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

ll sq(ll x) {
    ll ans = x*x;
    return ans;
}

ll val(ll num, ll div) {
    ll yes = num/div; // number in every division
    ll extra = num-(yes*div); // remainder
    ll sum = extra*(sq(yes+1)) + (div-extra)*(sq(yes));
    return sum;
}

void solve() {
    ll on, cn, t1; cin >> on >> cn;
    ll arr[on];
    ll cuts[on];
    ll prev[on];
    priority_queue<pll> pq;
    ll ans = 0;
    for (ll q = 0; q < on; q++) {
        cin >> arr[q];
        ans += sq(arr[q]);
        cuts[q] = 1;
        prev[q]=sq(arr[q]);
        ll loss = sq(arr[q]/2) + sq(arr[q] - arr[q]/2);
        loss = prev[q]-loss;
        //cout << loss << " ";
        pq.push(MP(loss, q));
    }
    //cout << "\n";
    for (ll r = 0; r < cn-on; r++) {
        ll lost = pq.top().first;
        ll q = pq.top().second;
        pq.pop();
        ans -= lost;
        cuts[q] += 1;
        //ll loss = 0;
        ll div = cuts[q]+1;
        ll loss = val(arr[q], cuts[q]+1);
        prev[q] = val(arr[q], cuts[q]);
        loss = prev[q]-loss;
        pq.push(MP(loss, q));
        //cout << ans << " " << loss << "\n";
    }
    cout << ans;
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}