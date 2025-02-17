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

ll arr[1000+1][1000+1], dist[1000+1][2];
ll n, a, b, c, ans=INT_MAX;

// ll memo(ll index, ll state, unordered_set<ll> lol) {
//     if (n == index) return 0;
//     if (dp[index][state] != -1) return dp[index][state];
//     ll ans = INT_MAX;
//     for (ll q = 1; q <= n; q++) {
//         if (lol.find(q) != lol.end()) continue;
//         unordered_set<ll> sus; sus = lol;
//         sus.insert(q);
//         ans = min(ans, memo(q, 0, sus) + c + b*arr[index][q]);
//     } 
//     if (state == 1) {
//         for (ll q = 1; q <= n; q++) {
//         if (lol.find(q) != lol.end()) continue;
//             unordered_set<ll> sus; sus = lol;
//             sus.insert(q);
//             ans = min(ans, memo(q, 1, sus) + a*arr[index][q]);
//         } 
//     }
//     cout << index << " " << state << " " << ans << "\n";
//     return dp[index][state] = ans;
// }


void solve() {
    cin >> n >> a >> b >> c;
    vector<pair<ll, pll>> adjlist[n+1][2];
    for (ll q = 1; q <= n; q++) {
        for (ll w = 1; w <= n; w++) {
            cin >> arr[q][w];
            adjlist[q][0].push_back({w, {c + b*arr[q][w], 0}});
            adjlist[q][1].push_back({w, {a*arr[q][w], 0}});
            adjlist[q][1].push_back({w, {a*arr[q][w], -1}});
        }
    }
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>>pq;
    memset(dist, -1, sizeof(dist));
    pq.push({0, {1, 1}}); // for multisource just push more nodes with dist 0
    dist[1][1] = 0;
    while (!pq.empty()) {
       ll cn = pq.top().second.first, cd = pq.top().first;
       ll state = pq.top().second.second; pq.pop();
       if (cd!=dist[cn][state]) continue;
       for (auto it: adjlist[cn][state]) {
           ll nx = it.first, nd = cd+it.second.first, ns = state+it.second.second; // change nd to max/min(d, it->second)​ for max and min flow. 
           if (dist[nx][ns] != -1 && dist[nx][ns] <= nd) continue; // change to dist[nx]>=nd for max dist
           dist[nx][ns] = nd;
           pq.push({nd, {nx, ns}});
       }
    }
    cout << min(dist[n][0], dist[n][1]);
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}