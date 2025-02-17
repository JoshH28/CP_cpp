#pragma GCC optimize("Ofast,unroll-loops")
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

ll segn, n, qn;
pair<pll, ll> query[500001];
ll mp[1000001];
bool cmp(pair<pll, ll> p1, pair<pll, ll> p2) {
    if (p1.first.first / segn < p2.first.first / segn) return true;
    else if (p1.first.first / segn > p2.first.first / segn) return false;
    return p1.first.second <= p2.first.second;
}

void solve() {
    cin >> n >> qn;
    memset(mp, 0, sizeof(mp));
    //unordered_map<ll, ll> mp;
    set<ll> s; ll bruh=1;
    unordered_map<ll, vector<ll> > gay;
    ll arr[n], ans[qn]; segn = sqrt(n);
    for (ll q = 0; q < n; q++) {cin >> arr[q];
    //s.insert(arr[q]); gay[arr[q]].pub(arr[q]);
    }
    // for (auto it: s) {
    //     for (auto it2: gay[it]) {
    //         arr[it2] = bruh;
    //     }
    //     bruh++;
    // }
    //sort(arr, arr+n);
    for (ll q = 0; q < qn; q++) {
        cin >> query[q].first.first >> query[q].first.second;
        query[q].first.second--; query[q].first.first--; 
        query[q].second = q;
    }
    sort(query, query+qn, cmp);
    ll cnt = 0, lptr = 0, rptr = -1;
    //mp[arr[0]]++;
    for (ll q = 0; q < qn; q++) {
        ll start = query[q].first.first, end = query[q].first.second;
        while(lptr > start) {
            lptr--;
            mp[arr[lptr]]++;
            if (mp[arr[lptr]] == 2) cnt++;
            else if (mp[arr[lptr]] == 3) cnt--;
            //cout << cnt << " " << lptr << "\n";
        }
        while(rptr < end) {
            rptr++;
            mp[arr[rptr]]++;
            //cout << mp[arr[rptr]] << " " << arr[rptr] << " ";
            if (mp[arr[rptr]] == 2) cnt++;
            else if (mp[arr[rptr]] == 3) cnt--;
            //cout << cnt << " " << rptr << "\n";
        }
        while (lptr < start) {
            mp[arr[lptr]]--;
            if (mp[arr[lptr]] == 1) cnt--;
            else if (mp[arr[lptr]] == 2) cnt++;
            //cout << cnt << " " << lptr << "\n";
            lptr++;
        }
        while (rptr > end) {
            mp[arr[rptr]]--;
            if (mp[arr[rptr]] == 1) cnt--;
            else if (mp[arr[rptr]] == 2) cnt++;
            //cout << cnt << " " << rptr << "\n";
            rptr--;
        }
        //cout << cnt << " " << lptr << " " << rptr << " " << query[q].second << "\n";
        ans[query[q].second] = cnt;
    }
    for (ll q = 0; q < qn; q++) cout << ans[q] << "\n";
    
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}