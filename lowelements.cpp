// No chemical can recreate our chemistry
// Got what I need, need, need
// I'm technical but I love sensibility
// When you're next to me
// I feel the boom, feel the bang inside my soul, love
// When you lay me down
// When you do it that way, I lose control love
// Of my senses now
// You got me flying and falling till four in the morning
// Can you hear my body is calling your name?
// Like oh my god (ooh), I think I might love you
// 'Cause I only liked a lot of things before I knew
// The way I love it when you touch me now
// Oh my god (ooh), I think I might love you-oo-ooh
// 'Cause I only liked a lot of things before I knew
// The way I love it when you touch me now (ooh)
// Oh my god (ooh)
// The way I love it when you touch me now
// Oh my god (ooh), I think I might love you-oo-ooh
// 'Cause I only liked a lot of things before I knew
// The way I love it when you touch me now
// I go from zero to a million when you dim the lights
// You get me high, high, high
// When you whisper in my ear I hear a lullaby
// So sing to me all night
// I feel the boom, feel the bang from head to toe, love
// When you caress me down
// When you do it that way, I lose control love
// You know you got me now
// You got me flying and falling till four in the morning
// Can you hear my body is calling your name?
// Like oh my god (ooh), I think I might love you
// 'Cause I only liked a lot things before I knew
// The way I love it when you touch me now
// Oh my god (ooh), I think I might love you-oo-ooh
// 'Cause I only liked a lot things before I knew
// The way I love it when you touch me now (ooh)
// Oh my god (ooh)
// The way I love it when you touch me now
// Oh my god (ooh), I think I might love you-oo-ooh
// 'Cause I only liked a lot of things before I knew
// The way I love it when you touch me now
// You got me flying and falling till four in the morning
// Can you hear my body is calling your name?
// And when you're gone you should know that you're all that I'm wanting
// And I'll always be feeling the same
// Like oh my god (ooh), I think I might love you
// 'Cause I only liked a lot of things before I knew
// The way I love it when you touch me now
// Oh my god (ooh), I think I might love you (ahh)
// 'Cause I only liked a lot of things before I knew
// The way I love it when you touch me now
// Oh my god (I think I might love you)
// Oh my god (ooh)
// The way I love it when you touch me now
// Oh my god (ooh)
// I think I might love you-oo-ooh (I think I might love you)
// 'Cause I only liked a lot of things before I knew
// The way I love it when you touch me now
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

const ll N = 2e5 + 1;
int fw[N];
void update(int x, int v) {
    for (; x<N; x+=x&(-x)) fw[x] += v; 
}
int sum(int x) {
    int res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

void solve() {
    ll n, prevMin, lol, ans = 0, sus; cin >> n; prevMin = n;
    for (ll q = 1; q <= n; q++) {
        cin >> lol;
        ans += ll(lol <= prevMin);
        prevMin = min(lol, prevMin);
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}