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
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

struct edge {
    int a, b, w;
    edge (int _a=0, int _b=0, int _w=0): a(_a), b(_b), w(_w) {}
};
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w < y.w; } //Swap the comparator for maximum

/* UFDS */
int pa[100];
int par(int x) { return (x==pa[x])?x:pa[x]=par(pa[x]); }

/* Pre-computation using DFS */
const int MAXN = 100050;
const int LOGN = 17;
ll en; 
vector<pair<ll, pll>> arr;
int p[LOGN+1][MAXN], h[MAXN];   //h: number of edges from root
long long d[MAXN];     //dist: sum of edge weight from root
vector<pair<int, int> > adjlist[MAXN];   //node, weight
bitset<MAXN> visited;
void dfs(int x) {
    if (visited[x]) return;
    visited[x] = 1;
    for (int k = 0; k < LOGN; ++k) {
        if (p[k][x] == -1) break;
        p[k+1][x] = p[k][p[k][x]];
    }
    for (auto it:adjlist[x]) {
        if (visited[it.first]) continue;
        p[0][it.first] = x;
        d[it.first] = d[x] + it.second;
        h[it.first] = h[x] + 1;
        dfs(it.first);
    }
}

/* Query */
int lca(int a, int b) { //h[a] < h[b]
    if (h[a] > h[b]) swap(a, b);
    /* advance b by h[b] - h[a] parents */
    for (int k = 0, d = h[b] - h[a]; k < LOGN; ++k) {
        if (d & (1<<k))  b = p[k][b];
    }
    if (a == b) return a;
    //assert(h[a] == h[b]); //same height
    /* to be continued */
    for (int k = LOGN-1; k >= 0; --k) {
        if (p[k][a] != p[k][b]) 
            a = p[k][a], b = p[k][b];
    }
    //assert(p[0][a] == p[0][b]);        //same immediate parent
    return p[0][a];
}


void solve() {
    cin >> en; ll t1, t2, t3, a,b,c,d,e, qn; en-=1;
    for (ll q = 0; q < en; q++) {
        cin >> t1 >> t2 >> t3;
        adjlist[t1].push_back(MP(t2, t3));
        adjlist[t2].push_back(MP(t1, t3));
        arr.push_back(MP(t3, MP(t1, t2)));
    }
    dfs(0);
    cin >> qn;
    sort(arr.begin(), arr.end());
    for (ll q = 0; q < qn; q++) {
        unordered_set<ll> uset;
        ll nodes[5]; for (ll q = 0; q < 5; q++) {cin >> nodes[q];}
        for (ll q = 0; q < 100; q++) {
            pa[q] = q;
        }
        while(!edgeList.empty()) {edgeList.pop_back();}
        for (int bruh = 0; bruh < 5; bruh++) {
            for (ll g = 0; g < 5; g++) {
                if (bruh==q) {continue;}
                ll hmm = lca(nodes[g], nodes[bruh]);
                ll dist=d[nodes[g]]+d[nodes[bruh]]-d[hmm]-d[hmm];
                uset.insert(hmm); uset.insert(nodes[g]); uset.insert(nodes[bruh]);
                edge e = (bruh, g, dist);
                edgeList.push_back(e);
            }
        }
        sort(edgeList.begin(), edgeList.end(), cmp);
        int ans = 0;
        for (vector<edge>::iterator it = edgeList.begin(); it != edgeList.end(); ++it) {
            if (par(it->a) == par(it->b)) continue;
            pa[par(it->a)] = par(it->b);
            ans += it->w;
        }     
        cout << ans <<"\n";
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}