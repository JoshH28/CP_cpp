// Gennady Korotkevich (Belarusian: Генадзь Караткевіч, Hienadź Karatkievič, Russian: Геннадий Короткевич; born 25 September 1994) is a Belarusian competitive programmer who has won major international competitions since the age of 11, as well as numerous national competitions. His top accomplishments include six consecutive gold medals in the International Olympiad in Informatics[1] as well as the world championship in the 2013 and 2015 International Collegiate Programming Contest World Finals. As of October 2023, Gennady is the highest-rated programmer on Codeforces,[2] CodeChef,[3] Topcoder,[4] AtCoder [jp][5] and HackerRank.[6] In January 2022, he achieved a historic rating of 3979 on Codeforces, becoming the first to break the 3900 barrier.[7]
// Korotkevich was born in Gomel (Homiel), southeastern Belarus. His parents, Vladimir and Lyudmila Korotkevich, are programmers in the mathematics department at Francysk Skaryna Homiel State University. At age 6, he became interested in his parents' work. When he was 8, his father designed a children's game he could use to learn programming.[8]
// His mother consulted departmental colleague Mikhail Dolinsky, who gave Korotkevich a small book to read. Dolinsky, one of the top computer science teachers in Belarus, recalled, "A month went by, and then another one... No news from Gena. Then suddenly Lyudmila comes by and brings me a programming notebook: when summer and football were over, her son sat at the computer. As a second-grader at a national competition, he took second place, which gained him an automatic entry into a technical university without taking any entrance exams. Somehow he solved the problem of a body immersed in water. At that time, Gena didn't even know about Archimedes' principle of buoyancy."[8]
// Korotkevich first gained global attention when he qualified for the 2006 International Olympiad in Informatics (IOI) at the age of 11, a world record by a large margin.[9]
// He took the silver medal at his first IOI event and received gold medals from 2007 to 2012.[1] To date, he is the most successful competitor in IOI's history.[10]
// At the 2009 IOI in Plovdiv, the then 14-year-old Korotkevich said of his success, "I try various [strategies], and one of them is the right one. I am no genius. I am simply good at it." He said he spent no more than three to four hours each day at the computer, and his preferred hobbies are football and table tennis.[11]
// In the fall of 2012, he moved to Russia to attend ITMO University. In the summer of 2013, he helped ITMO defeat Shanghai Jiao Tong University and the University of Tokyo to win the 37th International Collegiate Programming Contest World Finals, held in St. Petersburg.[12] He also won the annual Google Code Jam from 2014 to 2020.
// In a 2014 interview, Korotkevich said he was unsure of his career plans after graduation, saying he'd focus on his education and possibly go into science.[9]
// In a 2017 interview, Korotkevich said he had received job offers from Google and Yandex, but that he had turned them down and would instead continue with his degree in computer science at ITMO.[13]
// In 2019, Korotkevich was a PhD student at ITMO
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
    ll n, coinn, ans = 0, cnt=0, kcnt; cin >> n >> coinn; 
    ll arr[n]; for (ll q = 0; q < n; q++) cin >> arr[q];
    priority_queue< ll, vector<ll>, greater<ll> > pq; kcnt = coinn;
    for (ll q = 0; q < min(coinn, n); q++) {
        pq.push(arr[q]); cnt+=arr[q];
        while(pq.size() > kcnt) {cnt -= pq.top(); pq.pop();}
        ans = max(cnt, ans); kcnt--;
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}