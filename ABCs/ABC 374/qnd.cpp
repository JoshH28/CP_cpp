// La da la da da, la da da da
// La da la da di da da, la da da da da
// La da la da da, la da da
// La da la da di da
// I got my head out the sunroof
// I'm blasting our favorite tunes
// I only got one thing on my mind
// You got me stuck on the thought of you
// You're making me feel brand new
// You're more than the sunshine in my eyes
// You got those pretty eyes in your head, you know it
// You got me dancing in my bed so let me show it
// You are exactly what I want, kinda cool and kinda not
// Wanna give myself to you
// Yeah, we're driving down the freeway at night
// I only got one thing in the back of my mind (you got me stuck on the thought of you)
// I'm feeling like this might be my time to shine
// With you, with you, with you
// I got my head out the sunroof
// I'm blasting our favorite tunes
// I only got one thing on my mind
// You got me stuck on the thought of you
// You're making me feel brand new
// You're more than the sunshine in my eyes
// I got my head out the sunroof
// Oh-whoa, oh-whoa, ooh
// You got me stuck on the thought of you
// Oh-whoa, oh-whoa, ooh
// Yeah, we're driving down the freeway at night
// I only got one thing in the back of my mind (you got me stuck on the thought of you)
// I'm feeling like this might be my time to shine
// With you, with you, with you
// I got my head out the sunroof
// I'm blasting our favorite tunes
// I only got one thing on my mind
// You got me stuck on the thought of you
// You're making me feel brand new
// You're more than the sunshine in my eyes
// La da la da da, la da da da
// La da la da di da da, la da da da da
// La da la da da, la da da da
// La da la da di da da da
// La da la da da, la da da da
// La da la da di da da, la da da da da
// La da la da da, la da da da
// La da la da di da
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

ll n, s, t;
ld calcdist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

ld bf(ll index, ld currx, ld curry, vector<pair<pair<ld, ld>, pair<ld, ld>>> &arr, map<tuple<ll, ld, ld>, ld> &memo) {
    if (index == n) return 0;
    tuple<ll, ld, ld> state = make_tuple(index, currx, curry);
    if (memo.find(state) != memo.end()) return memo[state];
    ld x1 = arr[index].first.first, y1 = arr[index].first.second;
    ld x2 = arr[index].second.first, y2 = arr[index].second.second;
    ld time1 = calcdist(currx, curry, x1, y1) / ld(s) + calcdist(x1, y1, x2, y2) / ld(t);
    ld time2 = calcdist(currx, curry, x2, y2) / ld(s) + calcdist(x2, y2, x1, y1) / ld(t);
    memo[state] = min(time1 + bf(index + 1, x2, y2, arr, memo), time2 + bf(index + 1, x1, y1, arr, memo));
    return memo[state];
}

void solve() {
    vector<pair<pair<ld, ld>, pair<ld, ld>>> arr;
    cin >> n >> s >> t;
    for (ll i = 0; i < n; i++) {
        ld x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr.push_back({{x1, y1}, {x2, y2}});
    }
    ld best = numeric_limits<ld>::max();
    map<tuple<ll, ld, ld>, ld> memo;
    do {
        memo.clear();
        best = min(best, bf(0, 0, 0, arr, memo));
    } while (next_permutation(arr.begin(), arr.end()));
    cout << fixed << setprecision(10) << best << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}

