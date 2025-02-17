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
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

string str;
ll n;
ll dp[10000010][3][3];

ll memo(ll index, ll prev, ll prev2) {// 0 means D, 1 means K, 2 means ???
    if (index == n) return 0;
    if (dp[index][prev][prev2] != -1) return dp[index][prev][prev2];
    ll ans = INT_MAX;
    // if (index >= 2 && prev == 1 && prev2 == 0 && str[index] == 'K') {
    //     ans = min({ans, 1 + memo(index+1, 0, prev)});
    // } else if (index >= 2 && prev == 0 && prev2 == 1 && str[index] == 'D') {
    //     ans = min({ans, 1 + memo(index+1, 1, prev)});
    // } else {
    //     ll bruh = -1;
    //     if (str[index] == 'D') bruh = 0;
    //     else bruh = 1;
    //     ans = min(ans, memo(index+1, bruh, prev));
    // }
    for (ll q = 0; q < 2; q++) {
        if ( prev == q && prev2 != q && index >= 2) continue;
        else {
            ll bruh = 0;
            if (str[index] == 'K' && q == 0 || str[index] == 'D' && q == 1) bruh=1;
            ans = min(ans, bruh + memo(index+1, q, prev));
        }
    }

    return dp[index][prev][prev2] = ans;
}

void solve() {
    cin >> str; n = str.length();
    for (ll q = 0; q <= n; q++) {
        memset(dp[q], -1, sizeof(dp[q]));
    }
    cout << memo(0, 0, 0) << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}