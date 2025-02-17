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

struct DSU {
    const ll MAXN = 100001;
    ll parent[100001];
    ll size[100001];
    ll sizeOfMax = 1;
    DSU(ll n) {
        for (ll q = 1; q <= n; q++) {
            parent[q] = q;
            size[q] = 1;
        }
    }
    ll par(ll x) {
        if (parent[x] == x) {
            return x;
        } else {
            ll pathCompression = par(parent[x]);
            parent[x] = pathCompression; // path compression;
            return pathCompression;
        }
    }
    void merge(ll x, ll y) {
        if (par(x) == par(y)) return;
        if (size[par(x)] < size[par(y)]) {
            size[par(y)] += size[par(x)];
            parent[par(x)] = par(y);
            sizeOfMax = max(sizeOfMax, size[par(y)]);
        } else {
            size[par(x)] += size[par(y)];
            parent[par(y)] = par(x);
            sizeOfMax = max(sizeOfMax, size[par(x)]);
        }
    }
    bool isSameSet(ll x, ll y) {
        return par(x) == par(y);
    }
};

ll n, en, t1, t2, t3, ans = INT_MAX, k;
vector<pair<pll, ll>> edges;
//vector<vector<pair<pll, ll>>> subsets;
void bf(ll index, ll currTotal, DSU lolston) {
    if (index == en) return;
    bf(index, currTotal, lol);
    ll n1 = edges[index].first.first, n2 = edges[index].first.second, weight = edges[index].second;
    if (lol.isSameSet(n1, n2) == true) return;
    lol.merge(n1, n2);
    ll lmao = lol.parent[1], flag=1;
    for (ll q = 2; q <= n; q++) {
        if (lol.parent[q] != lmao) flag = 0;
    }
    if (flag) ans = min((currTotal+weight)%k, ans);
    else {
        bf(index+1, (currTotal+weight)%k, lol);
    }
}

void solve() {
    cin >> n >> en >> k;
    for (ll q = 0; q < en; q++) {
        cin >> t1 >> t2 >> t3;
        edges.pub({{t1, t2}, t3});
    }
    DSU sad(n);
    bf(0, 0, sad);
    cout << ans;
    // for (auto it: subsets) {
    //     DSU ufds(n); ll cnt = 0, flag=1;
    //     for (auto it2: it) {
    //         ll n1 = it2.first.first, n2 = it2.first.second, weight = it2.second;
    //         ufds.merge(n1, n2);
    //         cnt+=weight;
    //     }
    //     cnt%=k;
    //     ll lmao = ufds.parent[1];
    //     for (ll q = 2; q <= n; q++) {
    //         if (ufds.parent[q] != lmao) flag = 0;
    //     }
    //     if (flag) ans = min(cnt, ans);
    // }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}