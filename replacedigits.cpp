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

ll power10[200001], power1[200001];
ll n, qn, t1, t2, t3;
const ll mod = 998244353;

void powerPrecomp() {
    power10[0] = 1, power1[0] = 1;
    for (ll q = 1; q < 200001; q++) {
        power10[q] = power10[q-1] * 10;
        power10[q]%=mod;
        power1[q] = power1[q-1]*10 + 1;
        power1[q]%=mod;
    }
}

struct node {
    ll start, end, mid, value=1, lazy=0;
    node *l, *r;
    node(ll s, ll e) {
        start = s; end = e; mid = (start+end)/2; value = 1;
        if (start != end) {
            l = new node(start, mid);
            r = new node(mid+1, end);
        }
    }

    ll lazyProp() {
        if (!lazy) {return 0;}
        if (start ==end) {//currently dealing with leaf node
            value = lazy*power1[end-start];
            value%=mod;
            lazy = 0;
            return value%mod;
        } else {// dealing with non leaf node aka the gay part
            value = lazy*power1[end-start];
            l->lazy = lazy;
            r->lazy = lazy;
            lazy = 0;
            value%=mod;
            return value; 
        }
    }

    void rangeUpdate(ll left, ll right, ll uv) {
		lazyProp();
        if (start == left && end == right) {
            lazy  = uv;
            return;
        } else {
            if (left > mid) {
                r->rangeUpdate(left, right, uv);
            } else if (right <=mid) {
                l->rangeUpdate(left, right, uv);
            } else {
                l->rangeUpdate(left, mid, uv);
                r->rangeUpdate(mid+1, right, uv);
            }
        }
        l->lazyProp(), r->lazyProp();
        value = (l->value*power10[r->end - r->start + 1])%mod + r->value;
        value%= mod;
    }

    // ll rangeQuery(ll left, ll right) {
    //     lazyProp();
    //     if (left ==start && right == end) {
    //         return lazyProp();
    //     } else {
    //         if (left > mid) {
    //             return r->rangeQuery(left, right);
    //         } else if (right <= mid) {
    //             return l->rangeQuery(left, right);
    //         } else {
    //             ll ans = (l->rangeQuery(left, mid)*power10[right - mid + 1])%mod + r->lazyProp();
    //             return ans%mod;
    //         }
    //     }
    // }
}*root;


void solve() {
    powerPrecomp();
    cin >> n >> qn;
    root = new node(0, n-1);
    for (ll q = 0; q < n; q++) {
        root->rangeUpdate(q, q, 1);
    }
    //cout << root->value << "\n";
    for (ll q = 0; q < qn; q++) {
        cin >> t1 >> t2 >> t3;
        root->rangeUpdate(t1-1, t2-1, t3);
        cout << root->value << "\n";
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}