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

void solve() {
    ll n, qn, t1, t2, t3, t4; cin >> n >> qn;
    vector<pll> adjlist[n+10];
    for (ll q = 0; q < n-1; q++) {
        cin >> t1 >> t2 >> t3;
        adjlist[t1].pub({t2, t3});
        adjlist[t2].pub({t1, t3});
    }
    ll state[n+10]; memset(state, 0, sizeof(state));
    for (ll q = 0; q < qn; q++) {
        cin >> t1;
        if (t1 == 1) {
            cin >> t2;
            ll min_distance = INT_MAX;
            ll vis[n+10]; memset(vis, 0, sizeof(vis));
            stack<pll> stk; stk.push({t2, 0});
            vis[t2] = 1;
            while(!stk.empty()) {
                ll currnode = stk.top().first, currdist = stk.top().second; stk.pop();
                if (state[currnode] == 1) {
                    min_distance = min(min_distance, currdist);
                    continue;
                }
                for (auto it: adjlist[currnode]) {
                    if (vis[it.first]) continue;
                    vis[it.first] = 1;
                    stk.push({it.first, currdist+it.second});
                }
            }
            if (min_distance == INT_MAX) cout << -1 << "\n";
            else cout << min_distance << "\n";
        } else if (t1 == 2) {
            cin >> t2;
            if (state[t2]) state[t2] = 0;
            else state[t2] = 1;
        } else {
            cin >> t2 >> t3 >> t4;
            for (ll q = 0; q < adjlist[t2].size(); q++) {
                if (adjlist[t2][q].first == t3) {
                    adjlist[t2][q] = {t3, t4};
                }
            }
            for (ll q = 0; q < adjlist[t3].size(); q++) {
                if (adjlist[t3][q].first == t2) {
                    adjlist[t3][q] = {t2, t4};
                }
            }
        }

    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}