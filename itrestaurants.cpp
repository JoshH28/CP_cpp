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

ll n, t1, t2, currmax = 0;
vector<ll> adjlist[5010];
map<ll, ll> bruh;
set<ll> s;

int cnt=0, counter = 0;
ll local[20001], check[20001];
ll dfs(int node, int par){
    ll subtreesize = 1;
    vector<ll>sizes; 
    for (auto it: adjlist[node]) {
        if (it == par) continue;
        ll currsize = dfs(it, node);
        sizes.pub(currsize);
        subtreesize += currsize;
    }
    if (sizes.size()) {
        if (par != -1) {
            sizes.pub(n - subtreesize);
        }
        memset(local, 0, sizeof(local));
        local[0] = 1;
        for (auto it: sizes) {
            for (ll q = n - it; q >= 0; q--) {
                if (local[q]) {
                    local[q+it] = 1;
                    check[q+it] = 1;
                }
            }
        }
    }
    return subtreesize;
}

void solve() {
    cin >> n;
    for (ll q = 0; q < n-1; q++) {
        cin >> t1 >> t2; 
        adjlist[t2].pub(t1); 
        adjlist[t1].pub(t2);
    }
    dfs(1, -1);
    set<ll> bruh;
    for (ll q = 1; q < n-1; q++) {
        if (check[q]) {
            bruh.insert(q);
        }
    }
    cout << bruh.size() << "\n";
    for (auto it: bruh) {
        cout << it << " " << n - it - 1 << "\n";
    }

    // for (ll q = 1; q <= n; q++) {
    //     //cout << q << "\n";
    //     for (auto it: adjlist[q]) {//we are currently handling all the subtrees
    //         ll subtreesize = abs(post[it]-pre[it]);
    //         if (subtreesize >= 1 && n-subtreesize-1 >= 1){
    //             bruh[subtreesize] = n-subtreesize-1;
    //             s.insert(subtreesize);
    //             bruh[n-subtreesize-1] = subtreesize;
    //             s.insert(n-subtreesize-1);
    //         }
    //         //cout << subtreesize << " "<< n-subtreesize-1 << "\n";
    //     }
    //     //cout << "\n";
    // }
    // counter = 0;
    // dfs(2, -1);
    // for (ll q = 1; q <= n; q++) {
    //     //cout << q << "\n";
    //     for (auto it: adjlist[q]) {//we are currently handling all the subtrees
    //         ll subtreesize = abs(post[it]-pre[it]);
    //         if (subtreesize >= 1 && n-subtreesize-1 >= 1){
    //             bruh[subtreesize] = n-subtreesize-1;
    //             s.insert(subtreesize);
    //             bruh[n-subtreesize-1] = subtreesize;
    //             s.insert(n-subtreesize-1);
    //         }
    //     }
    // }
    // cout << s.size() << "\n";
    // for (auto it: s){
    //     cout << it << " " << bruh[it] << "\n";
    // }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}