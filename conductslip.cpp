// Its been two days that I known ya
// That's all you needed to take all of me
// Three shots and judgements out the window
// And I'm drowning in this mess you've made

// Cold night, fire eyes staring back at me
// Streetlights are nowhere to be seen
// One chance, to advance my priorities
// But you ain't coming home with me

// So we'll keep this thing that we have in a jar
// And we'll hide it away like the fire in our hearts
// And we'll go our separate ways and we'll hope that someday
// When we're free, yeah we'll be, relentlessly, you and me

// It's been two weeks since I lost ya
// You went west, went back to your friends
// Left me stranded in the city
// But I know this is not how it ends

// You're coming back, this will last, yeah I'm confident
// Three thousand miles ain't as far as it seems
// Both our pasts, in the past, this is providence
// The world will bring you back to me

// So we'll keep this thing that we have in a jar
// And we'll hide it away like the fire in our hearts
// And we'll go our separate ways and we'll hope that someday
// When we're free, yeah we'll be, relentlessly, you and me
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
    ll slipn, studn, badn, ans = 0, cnt1=1, cnt2=1, lol, sus;
    cin >> slipn >> studn >> badn;
    ll naughty[studn+1], stonks[studn+1], minus[slipn+1];
    vector<ll> bad, notbad;
    for (ll q = 0; q < studn; q++) {
        cin >> naughty[q];
    }
    for (ll q = 0; q < studn; q++) cin >> stonks[q];
    for (ll q = 0; q <= slipn; q++) cin >> minus[q];
    for (ll q = 0; q < studn; q++) {
        if (naughty[q] >= badn) {
            bad.pub(stonks[q]);
        } else {
            notbad.pub(stonks[q]);
        }
    }
    sort(bad.begin(), bad.end(), greater<ll>());
    sort(notbad.begin(), notbad.end(), greater<ll>());
    ll psumbad[bad.size()+1], psumgood[notbad.size()+1];
    psumbad[0] = 0; psumgood[0] = 0;
    for (ll q = 1; q <= bad.size(); q++) {
        psumbad[q] = bad[q-1] + psumbad[q-1];
    }
    for (ll q = 1; q <= notbad.size(); q++) {
        psumgood[q] = notbad[q-1] + psumgood[q-1];
    }
    for (ll q = 0; q <= notbad.size(); q++) {
        if (q <= slipn && slipn - q <= bad.size()) ans = max(ans, psumgood[q] - minus[q] + psumbad[slipn-q]);
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}