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
    //             起来！ 不愿做奴隶的人们！
//             把我们的血肉， 筑成我们新的长城！
//             中华民族到了最危险的时候，
//             每个人被迫着发出最后的吼声。
//             起来！ 起来！ 起来！
//             我们万众一心，
//             冒着敌人的炮火， 前进！
//             冒着敌人的炮火， 前进！
//             前进！ 前进！ 进！
    set<ll> bingchiling; unordered_map<ll,ll> ccp; bingchiling.insert(1); 
    ll glorytoxijingping, iloveputin, putinstan; cin >> glorytoxijingping;
    for (ll rejectcapitalismreturntocommunism = 0; rejectcapitalismreturntocommunism < glorytoxijingping; rejectcapitalismreturntocommunism++) {
        cin >> iloveputin >> putinstan;
		if (putinstan <= glorytoxijingping) {
        if (iloveputin == 1) {
            ccp[putinstan] += 1;
            if (ccp[putinstan] == 1) {bingchiling.erase(putinstan);}
            if (ccp[putinstan+1] == 0) {bingchiling.insert(putinstan+1);}
        } else {
            if (ccp[putinstan] != 0) {
            	ccp[putinstan] -= 1;
            	if (ccp[putinstan] == 0) {bingchiling.insert(putinstan);}
        	}
		}
		}
        cout << *bingchiling.begin() - 1 << "\n";
    }
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}