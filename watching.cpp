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

ll n, smol, big, m, best=INT_MAX, range; 
ll event[2001];
ll dp[2001][2001]; //p and q is bounded by n because can only use n cameras at most

ll memo(ll currevent, ll smolu) {
    if (currevent >= n) {return 0;}
    if (dp[currevent][smolu] != -1) {return dp[currevent][smolu];}
    ll bigr = INT_MAX, smolr = INT_MAX;
    ll ans=INT_MAX;
    bigr = event[currevent] + range + range - 1;
	ll ptr1=currevent;
    while(ptr1 < n && event[ptr1] <= bigr){
		ptr1++;
    }
	ll ptr2 = currevent;
    ans = memo(ptr1, smolu)+1;
	if (smolu > 0) {
		smolr = event[currevent] + range - 1;
        while(ptr2 < n && event[ptr2] <= smolr){
            ptr2++;
        }
        ans = min(ans, memo(ptr2, smolu-1));
    }
    dp[currevent][smolu] = ans;
    return ans;
}

void solve() {
    cin >> n >> smol >> big;
	smol = min(n, smol); big= min(n, big);
    for (ll q = 0; q < n; q++) {cin >> event[q]; m = max(m, event[q]);}
    sort(event, event+n);
    ll hi=1e9+1, lo=1;
    while (lo <= hi) {
        memset(dp, -1, sizeof(dp));
        ll mid = (lo+hi)/2;
        range = mid;
        ll ans = memo(0, smol);
        //cout << ans << " " << range << "\n";
        if (ans <= big) {//very sexy, works
            best = min(best, mid);
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    cout << best;
}


signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}