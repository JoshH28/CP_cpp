// Sigma, sigma boy, sigma boy, sigma boy
// Каждая девчонка хочет танцевать с тобой
// Sigma, sigma boy, sigma boy, sigma boy
// Я такая вся, что добиваться будешь год
// Sigma, sigma boy, sigma boy, sigma boy
// Каждая девчонка хочет танцевать с тобой
// Sigma, sigma boy, sigma boy, sigma boy
// Я такая вся, что добиваться будешь год
// Sigma, sigma boy, sigma boy, sigma boy
// Каждая девчонка хочет танцевать с тобой
// Sigma, sigma boy, sigma boy, sigma boy
// Я такая вся, что добиваться будешь год
// Так что милый мальчик будет прыгать и сгорать (ага)
// Ой, пакуйся в мою Bentley, полезай в мой beauty box (давай)
// Ты мой sigma boy, но я желаю твоих слёз (понял?)
// Sigma, sigma boy, бэк на стол, достаю bank roll
// Я куплю все Skittles, Snickers — точно будешь мой, boy
// Sigma, sigma boy, я — икона твоих икон
// Обо мне мечтают так, как будто я биткоин (понял?)
// Sigma, sigma бой, но не мой, молча, как немой
// Смотрит в никуда, ой какой, этот взгляд — огонь
// Годы будут ждать, когда ты соберёшься
// И меня когда-нибудь добьёшься
// Sigma, sigma boy, sigma boy, sigma boy
// Каждая девчонка хочет танцевать с тобой
// Sigma, sigma boy, sigma boy, sigma boy
// Я такая вся, что добиваться будешь год
// Sigma, sigma boy, sigma boy, sigma boy
// Каждая девчонка хочет танцевать с тобой
// Sigma, sigma boy, sigma boy, sigma boy
// Я такая вся, что добиваться будешь год
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

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; //to do 4dir skip every odd index
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //to do 4dir skip every odd index

void solve() {
    ll n, k, qn; cin >> n >> k >> qn;
    ll arr[k][n];
    for (ll q = 0; q < n; q++) {
        for (ll w = 0; w < k; w++) {
            cin >> arr[w][q];
            if (q != 0) arr[w][q] |= arr[w][q-1];
        }
    }
    for (ll sigmasigmaboy = 0; sigmasigmaboy < qn; sigmasigmaboy++) {
        ll m, pos, num; char wow; cin >> m;
        ll hi=n-1, lo=0;
        for (ll f = 0; f < m; f++) {
            cin >> pos >> wow >> num; pos--;
            if (wow == '<') {
                ll gay = upper_bound(arr[pos], arr[pos]+n, num-1)-arr[pos];
                hi = min(hi, gay-1);
            } else {
                ll gay = lower_bound(arr[pos], arr[pos]+n, num+1)-arr[pos];
                lo = max(lo, gay);
            }
        }
        if (lo <= hi) {
            cout << lo+1 << "\n";
        } else {
            cout << "-1\n";
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}