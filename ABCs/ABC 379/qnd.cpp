// Heavy heart since I met ya 
// In my head heavy metal 
// Caught me by surprise 
// Late night Uber just too get a tattoo 
// You’re a foot I’m a pedal
// I’m a dog in your kennel
// But then I don’t mind
// It’s a ghost town but I pass through 
// wish I left you in the dust too spend your time 
// So there’s no chance to run into you down the line 
 
// But when I think about you I just get so high
// I’ve had these dreams about you, but I know they won’t come true
// Stuck in my head like melodies
// Can’t get you out no remedy
// Wish I could wipe my memory
// And I will burn like gasoline 
// Just light the match I’ll be your fiend 
// And when I’m gone remember me
// Empty room at a motel 
// 4 walls for me and I
// In an endless night
// Tears run’ dry by the fire
// I wish I left
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
    ll qn; cin >> qn;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    char qu; ll num, cday = 0;
    for (ll q = 0; q < qn; q++) {
        cin >> qu;
        if (qu == '1') {
            pq.push(cday);
        } else if (qu == '2') {
            cin >> num; cday+=num;
        } else {
            cin >> num;
            ll ans = 0;
            while (pq.size()) {
                if (cday - pq.top() >= num)  {ans++; pq.pop();}
                else break;
            }
            cout << ans << "\n";
        }
    } 
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}