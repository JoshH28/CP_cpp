// [Zayn:]
// Going out tonight
// Changes into something red
// Her mother doesn't like that kind of dress
// Everything she never had she's showing off

// [Liam:]
// Driving too fast
// Moon is breaking through her hair
// She's heading for something that she won't forget
// Having no regrets is all that she really wants

// [Harry:]
// We're only getting older, baby
// And I've been thinking about it lately
// Does it ever drive you crazy
// Just how fast the night changes?
// Everything that you've ever dreamed of
// Disappearing when you wake up
// But there's nothing to be afraid of
// Even when the night changes
// It will never change me and you

// [Louis:]
// Chasing it tonight,
// Doubts are running 'round her head
// He's waiting, hides behind a cigarette
// Heart is beating loud, and she doesn't want it to stop

// [Niall:]
// Moving too fast
// Moon is lighting up her skin
// She's falling, doesn't even know it yet
// Having no regrets is all that she really wants

// [Harry:]
// We're only getting older, baby
// And I've been thinking about it lately
// Does it ever drive you crazy
// Just how fast the night changes?
// Everything that you've ever dreamed of
// Disappearing when you wake up
// But there's nothing to be afraid of
// Even when the night changes
// It will never change me and you

// [Zayn:]
// Going out tonight
// Changes into something red
// Her mother doesn't like that kind of dress
// Reminds her of the missing piece of innocence she lost

// [Harry (along all):]
// We're only getting older, baby
// And I've been thinking about it lately
// Does it ever drive you crazy
// Just how fast the night changes?
// Everything that you've ever dreamed of
// Disappearing when you wake up
// But there's nothing to be afraid of
// Even when the night changes
// It will never change, baby
// It will never change, baby
// It will never change me and you
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

ll mod( ll num, ll gay) {
    if (num < 0) num += gay; 
    return num;
}

void solve() {
    ll n, qn;  cin >> n >> qn;
    ll realleft = 1, realright = 2;
    char hand; ll t1, ans = 0;
    for (ll q = 0; q < qn; q++) {
        cin >> hand >> t1;
        if (hand == 'R') {
            ll cnt1 = 0, cnt2 = 0;
            ll right = realright, left = realleft;
            while (right != t1) {
                if (right == left) {
                    cnt1 = -1; 
                    break;
                }
                if (right == 1) right = n;
                else right--; 
                cnt1++;
            }
            right = realright;
            while (right != t1) {
                if (right == left) {
                    cnt2 = -1;
                    break;
                }
                if (right == n) right = 1; 
                else right++; 
                cnt2++;
            }
            if (cnt1 == -1) ans += cnt2;
            else if (cnt2 == -1) ans += cnt1;
            else ans += min(cnt1, cnt2);
            realright = t1;
        } else {
            ll cnt1 = 0, cnt2 = 0;
            ll right = realright, left = realleft;
            while (left != t1) {
                if (right == left) {
                    cnt1 = -1; 
                    break;
                }
                if (left == 1) left = n;
                else left--; 
                cnt1++;
            }
            left = realleft;
            while (left != t1) {
                if (right == left) {
                    cnt2 = -1; 
                    break;
                }
                if (left == n) left = 1;
                else left++; 
                cnt2++;
            }
            if (cnt1 == -1) ans += cnt2;
            else if (cnt2 == -1) ans += cnt1;
            else ans += min(cnt1, cnt2);
            realleft = t1;
        }
    }
    cout << ans;
}


signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}