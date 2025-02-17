// Whoa-oh-oh
// Whoa-oh-oh
// Whoa-oh-oh
// Whoa-oh-oh
// I remember us alone
// Tasting you like alcohol, I know
// (For me, it was always you)
// Madison and 34
// Watched you close that yellow door and go
// I should have said turn around, turn around
// Let's get back to it
// I should have said I was wrong all along
// I put you through it
// I can't undo it
// But I could call your phone just to hear your voice
// I could drive to you, yeah, but what's the point?
// I still think of you 'cause I've got no choice
// I still think of you 'cause I've got no choice
// I could run away but I won't get far
// Meet somebody new, let her break my heart
// I still think of you 'cause I've got no choice
// I still think of you, I still think of you
// I'm missin' you in figure eight
// Tears me down, it's way too late, I know
// That you already moved on
// You were gone before I knew it
// Just to come back like a song
// On and on in my head, I can't lose it
// I can't undo it
// But I could call your phone just to hear your voice
// I could drive to you, yeah, but what's the point?
// I still think of you 'cause I've got no choice
// I still think of you 'cause I've got no choice
// I could run away but I won't get far
// Meet somebody new, let her break my heart
// I still think of you 'cause I've got no choice
// I still think of you, I still think of you
// Whoa-oh-oh
// Whoa-oh-oh
// Whoa-oh-oh
// Whoa-oh-oh
// No matter what I try to do, I never get away from you, ah-aah
// And even if I wanted to, the only other choice is you, mm-ah
// I could call your phone just to hear your voice
// I could drive to you, yeah, but what's the point?
// I still think of you 'cause I've got no choice
// I still think of you 'cause I've got no choice
// I could run away but I won't get far
// Meet somebody new, let her break my heart
// I still think of you 'cause I've got no choice
// I still think of you, I still think of you
// Whoa-oh-oh
// Whoa-oh-oh
// Whoa-oh-oh
// Whoa-oh-oh
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

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; //to do 4dir skip every odd index
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //to do 4dir skip every odd index

void solve() {
    ll ans=0, n, t1, t2, state = 0, x = 0, y = 0;
    vector<pair<ll, pll>> pos, neg; cin >> n;
    for (ll q = 0; q < n; q++) {
        cin >> t1 >> t2;
        pos.pub({t1+t2, {t1, t2}});
    }
    sort(pos.begin(), pos.end());
    reverse(pos.begin(), pos.end());
    deque<pair<ll, pll>> dq;
    for (auto it: pos) dq.push_back(it);
    for (ll q = 0; q < pos.size(); q++) {
        if (state == 0) {
            x += dq.front().se.fi; dq.pop_front(); state += 1;
        } else {
            y += dq.front().se.se; dq.pop_front(); state -= 1;
        }
    }
    cout << x-y;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}