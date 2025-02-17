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
    ll n, dn, t1, t2; cin >> n >> dn;
    ll bugn[n+1], species[n+1], home[n+1];
    vector<ll> adjlist[n+5];
    for (ll q = 1; q <= n; q++) cin >> bugn[q];
    for (ll q = 1; q <= n; q++) cin >> species[q];
    for (ll q = 1; q <= dn; q++) cin >> home[q];
    for (ll q = 0; q < n-1; q++) {
        cin >> t1 >> t2;
        adjlist[t1].pub(t2);
        adjlist[t2].pub(t1);
    }
    //cout << "\n";
    if (n <= 1000 && dn <= 1000) {
        for (ll q = 1; q <= dn; q++) {
            vector<ll> us; ll vis[n+1];
            stack<pair<ll, vector<ll>>> stk; 
            us.pub(1);
            memset(vis, 0, sizeof(vis)); stk.push({1, us});
            vis[1] = 1;
            while(!stk.empty()) {
                ll currpond = stk.top().first; 
                vector<ll> visitedislands = stk.top().second;
                stk.pop();
                if (currpond == home[q]) {
                    unordered_set<ll> bruh;
                    for (auto it: visitedislands) {
                        if (bugn[it] > 0) {bruh.insert(species[it]);
                        bugn[it]-= 1;}
                    }
                    cout << bruh.size() << " "; //<< " " << q << " " << home[q] << "\n";
                    while(stk.size()) stk.pop();
                    break;
                }
                for (auto it: adjlist[currpond]) {
                    if (vis[it]) continue;
                    vector<ll> newset; vis[it] = 1;
                    for (auto it2: visitedislands) newset.pub(it2);
                    newset.pub(it);
                    stk.push({it, newset});
                } 
            }

        }
    } else {
        unordered_set<ll> us; ll vis[n+1];
        stack< pair<pll, unordered_set<ll>>> stk; 
        us.insert(species[1]); memset(vis, 0, sizeof(vis)); 
        stk.push({{1,1}, us}); vis[1] = 1;
        while(!stk.empty()) {
            ll currpond = stk.top().first.second, uniquecnt = stk.top().first.first; 
            unordered_set<ll> visitedislands = stk.top().second; stk.pop();
            for (auto it: adjlist[currpond]) {
                if (vis[it]) continue;
                unordered_set<ll> newset; 
                for (auto it2: visitedislands) newset.insert(it2);
                newset.insert(species[it]);
                vis[it] = newset.size();
                //cout << newset.size() << " " << it << "\n";
                stk.push({{newset.size(), it}, newset});
            } 
        }
        // for (ll q = 1; q <= n; q++) cout << vis[q] << " ";
        // cout << "\n";
        for (ll q = 1; q <= dn; q++) {
            cout << vis[home[q]] << " ";
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}