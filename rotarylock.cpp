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
ull mod = pow(2, 60);
const ll N = 1000001;
ll fw[N], fw2[N];
void update(ll x, ll y, ll v, ll mod) { //inclusive
    for (ll tx=x; tx < N; tx += tx&(-tx)) {
		if(tx==x) x%=mod;
        fw[tx] += v, fw2[tx] -= (v*(x-1))%mod;
        fw[tx]%=mod;
        fw2[tx]%=mod;
    }
    for (ll ty=y+1; ty < N; ty += ty&(-ty)){
		if(ty==y+1) y%=mod;
        fw[ty] -= v, fw2[ty] += (v*(y))%mod; 
        fw[ty]%=mod; 
        fw2[ty]%=mod;
    } 
}

ll sum (ll x) {
    ll res = 0;
    for (ll tx=x; tx; tx -= tx&(-tx)) res += (((fw[tx]))*x) + (fw2[tx]);
    //res %= mod;
    return res;
}
ll range_sum(ll x, ll y) { //inclusive
    return sum(y)-sum(x-1);
}

void solve() {
    ll dialn, qn, k, t1, t2, t3; cin >> dialn >> qn >> k; 
    mod = pow(2, k);
    //cout << mod << "\n";
    for (ll q = 0; q < qn; q++) {
        cin >> t1;
        if (t1 == 0) {
            cin >> t2 >> t3;
            update(t2, dialn, t3, mod);
        } else {
            cin >> t2;
			ll yes = range_sum(t2, t2)%mod;
            if(yes>=0) 
                cout << (long long int)yes << '\n';
            else
                cout << (long long int)mod+yes << '\n';
       	}
    }
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}