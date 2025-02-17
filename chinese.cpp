// hat's the trick? I wish I knew
// I'm so done with thinking through all the things I could've been
// And I know you want me too
// All it takes is that one look at you and I run right back to you
// You cross the line and it's time to say F you
// What's the point in saying that when you know how I'll react?
// You think you can just take it back, but shit just don't work like that
// You're the drug that I'm addicted to, and I want you so bad
// Guess I'm stuck with you, and that's that
// 'Cause when it all falls down, then whatever
// When it don't work out for the better
// If it just ain't right, and it's time to say goodbye
// When it all falls down, when it all falls down
// I'll be fine
// I'll be fine
// You're the drug that I'm addicted to
// And I want you so bad, but I'll be fine
// Why we fight? I don't know
// We say what hurts the most
// Oh, I tried staying cold, but you take it personal
// All these firing shots and making ground
// It's way too hard to cope, but I still can't let you go
// 'Cause when it all falls down, then whatever
// When it don't work out for the better
// If it just ain't right, and it's time to say goodbye
// When it all falls down, when it all falls down
// I'll be fine
// I'll be fine
// You're the drug that I'm addicted to and I want you so bad
// But I'll be fine
// I'll be fine, fine, fine
// Fine, fine, fine, fine, fine
// I'll be fine, fine, fine
// Fine, fine, fine, fine, fine
// I'll be fine, fine, fine
// Fine, fine, fine, fine, fine
// I'll be fine, fine, fine
// Fine, fine, fine, fine, fine
// 'Cause when it all falls down, then whatever (then whatever, babe)
// When it don't work out for the better (for the better)
// If it just ain't right, and it's time to say goodbye
// When it all falls down (when it all, when it all)
// When it all falls down (when it all falls down)
// I'll be fine
// (Fine, fine, fine) I'll be fine (I'll be fine)
// You're the drug that I'm addicted to and I want you so bad
// But I'll be fine (I'll be fine), and that's that
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
    ll n, lim, ans=0; cin >> n;
    ll day[n], night[n]; 
    for (ll q = 0; q < n; q++) cin >> day[q];
    for (ll q = 0; q < n; q++) cin >> night[q];
    cin >> lim; sort(day, day+n); 
    sort(night, night+n); reverse(night, night+n);
    for (ll q = 0; q < n; q++) {
        ll minsTdy = day[q]+night[q];
        if (minsTdy > lim) {
            ans = ans + (minsTdy-lim)*100;
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