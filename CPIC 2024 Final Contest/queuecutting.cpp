// I used to shut my door while my mother screamed in the kitchen
// I'd turn the music up, get high and try not to listen
// To every little fight, 'cause neither one was right
// I swore I'd never be like them
// But I was just a kid back then
// The older I get the more that I see
// My parents aren't heroes, they're just like me
// And loving is hard, it don't always work
// You just try your best not to get hurt
// I used to be mad but now I know
// Sometimes it's better to let someone go
// It just hadn't hit me yet
// The older I get
// I used to wonder why, why they could never be happy
// I used to close my eyes and pray for a whole 'nother family
// Where everything was fine, one that felt like mine
// I swore I'd never be like them
// But I was just a kid back then
// The older I get the more that I see
// My parents aren't heroes, they're just like me
// And loving is hard, it don't always work
// You just try your best not to get hurt
// I used to be mad but now I know
// Sometimes it's better to let someone go
// It just hadn't hit me yet
// The older I get
// The older I get the more that I see
// My parents aren't heroes, they're just like me
// And loving is hard, it don't always work
// You just try your best not to get hurt
// I used to be mad but now I know
// Sometimes it's better to let someone go
// It just hadn't hit me yet
// The older I get
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
    deque<ll> dq; ll qn; cin >> qn;
    map<ll, ll> fren; ll type, s1, s2;
    for (ll q = 0; q < qn; q++) {
        cin >> type;
        if (type == 1) {
            cin >> s1; dq.pub(s1);
        } else if (type == 2) {
            cin >> s1 >> s2;
            fren[s2] = s1;
        } else {
            ll sus = dq.front();
            cout << sus << "\n";
            dq.pop_front();
            if (fren[sus] != 0) {
                dq.puf(fren[sus]);
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