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

ll l, r, k, n; string str; 

//vector<ll> dp[n+10][k+10];
ll dp[210][210];
ll par[210][210];
vector<ll> zero;

// vector<ll> memo(ll idx, ll wn, vector<ll> curr) {
//     if (idx == n) return zero;
//     if (dp[idx][wn] != "") return dp[idx][wn];
//     vector<ll> temp, ans;
//     for (ll q = l; q <= r; q++) {
//         if (idx+q > n) break;
//         for (auto it: curr) temp.pub(it);
//         temp.pub(q); vector<ll> theirans = memo(idx+q, wn+1, temp(q))
//     }
// } 

ll memo(ll idx, ll wn) {
    if (idx == n) {
        dp[idx][wn] = wn==k;
        if (wn == k) return 1;
        else return 0;
    }
    if (dp[idx][wn] != -1) return dp[idx][wn];
    ll ans = -INT_MAX;
    for (ll q = l; q <= r; q++) {
        if (idx+q > n) break;
        if (ans < memo(q+idx, wn+1)) {
            ans = max(ans, memo(q+idx, wn+1));
            par[idx+q][wn+1] = idx; 
        }
    }
    return dp[idx][wn] = ans;
}

void solve() {
    cin >> k >> l >> r >> str; n = str.length();
    if (n > k*r || n < k*l) {cout << "No solution"; return;}
    ll currcnt = 0, idx = 0;
    for (ll q = k; q > 0; q--) {
        ll cnt = (n-idx)/q;
        for (ll w = idx; w < idx + cnt; w++) {
            cout << str[w];
        }
        cout << "\n"; idx += cnt;
    } 
    // memset(dp, -1, sizeof(dp)); memset(par, -1, sizeof(dp)); 
    // ll ans = memo(0,0),  currlength = par[n][k], curridx = n, blockn = k;
    // vector<ll> lengs; 
    // while (currlength != -1) {
    //     blockn--; lengs.pub(curridx-currlength); curridx = currlength, currlength = par[currlength][blockn];
    // }
    // for (auto it: lengs) {
    //     cout << it << " ";
    // }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}