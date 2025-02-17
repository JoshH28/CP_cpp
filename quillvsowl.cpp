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

inline void read(int& x) {
    x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9' ) {
        x = (x << 3) + (x << 1) + (ch & 15);
        ch = getchar_unlocked();
    }
}

void solve() {
    // hn = hedgehog num, on = owl num, range is K, bhq = num of hedgehogs with quills, bhq = num of owls needed to eat hedgehog wityh quils
    ll hn, on, range, bhn, bhq, cnt=0, ans=0, t1; 
    read(hn); read(on); read(range); read(bhn); read(bhq);
    // ht<ll,ll> owls;
    // ht<ll,ll> hedgehogs;
    ll arr[hn], owls[on]; ll why[hn]; memset(why, 0, sizeof(why));
    for (ll q = 0; q < hn; q++) {
        read(arr[q]);
    }
    for (ll q = 0; q < on; q++) {
        read(t1);
        owls[q] = t1;
    }
    for (ll q = 0; q < bhn; q++) {
        read(t1);
        why[t1-1] = 1;
    }
    ll lptr = 0; ll rptr = 0;
    for (ll q = 0; q < hn; q++) {
      while (rptr < on && owls[rptr] <= arr[q]+range) {
        //cout << owls[rptr] << " " << arr[q]+range;
        rptr++;
      }
      while(lptr < rptr && owls[lptr] < arr[q]-range) {
        lptr++;
      }
      ll owlno = rptr-lptr;
      ll yes = 1;
      if (why[q] == 1) {yes = bhq+1;}
      ll hmm = yes-owlno;
      if (hmm <= 0) {ans++;}
      //cout << owlno << " " << lptr << " " << rptr << "\n";
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}
