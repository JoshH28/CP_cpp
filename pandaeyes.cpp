// if this code passes then idk whats up on printingmachine
// [Verse 1]
// They say time
// It's all it takes to heal the pain
// But I'm running out on patience
// I wish I could find a way to feel something
// But I'm too busy asking why
// Why'd I never let you in?
// And why'd I never let you go?
// Why'd I always let you down?
// And why didn't I let you know?

// [Verse 2]
// I never meant to lose my way
// But now I'm running out on streght to fight
// 'Cause I've been taking more that I can take
// Now I can finally see the reason why

// [Pre-Chorus]
// You shot me right in the heart
// You let me here in the dark
// Slipping away like all the love that I gave you
// You tried to make me undеrstand that this was over
// But you just wanted to me to undеrstand you

// [Chorus]
// I wish that I never let you in
// 'Cause I can't get you out
// I wish that I could do it all again, I could do it all again without you

// [Post-Chorus]
// (I could do it all again without you)
// I could do it all again without you
// (I could do it all again without you)

// [Verse 3]
// You said you're packing up your bags in the morning
// Slipping away like all the hope that I was holding
// I tried to make you understand that I was lonely
// Joking on every single you ever told me

// [Pre-Chorus]
// You shot me right in the heart
// You let me here in the dark
// Slipping away like all the time that I gave you
// I tried to make you understand that I was sorry
// But you just wanted to me to understand you

// [Chorus]
// I wish that I never let you in
// 'Cause I can't get you out
// I wish that I could do it all again, I could do it all again without you (Without you)

// [Post-Chorus]
// (I could do it all again without you)
// I could do it all again without you
// (I could do it all again without you)
// I could do it all again, I could do it all again without you
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
#define pll pair<unsigned long long, unsigned long long>
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

bool cmp(pll p1, pll p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

void solve() {
    ll n, currt=0, ans=0; cin >> n; pll arr[n];
    unordered_set<ll> lol;
    for (ll q = 0; q < n; q++) {
        cin >> arr[q].first >> arr[q].second;
    }
    sort(arr, arr+n, cmp);
    // cout << "\n";
    // for (ll q = 0; q < n; q++) {
    //     cout << arr[q].first << " " << arr[q].second << "\n";
    // }
    // cout << "\n";
    for (ll q = 0; q < n; q++) {
        if (currt > arr[q].first) continue;
        currt = arr[q].second; ans++;
        //cout << currt-1 << " " << arr[q].second << "\n";
    }
    cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}