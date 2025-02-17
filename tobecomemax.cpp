// 5th of November
// When I walked you home
// That's when I nearly said it
// But then said "Forget it" and froze
// Do you remember?
// You probably don't
// 'Cause the sparks in the sky
// Took a hold of your eyes while we spoke
// Yesterday, drank way too much
// And stayed up too late
// Started to write what I wanna say
// Deleted the message, but I still remember it said
// I wish I was who you drunk texted at midnight
// Wish I was the reason you stay up 'til 3
// And you can't fall asleep
// Waiting for me to reply
// I wish I was more than just someone you walk by
// Wish I wasn't scared to be honest and open
// Instead of just hoping
// You'd feel what I'm feeling inside
// April the 7th
// And nothing has changed
// It's hard to get by
// When you're still on my mind everyday
// Sometimes I question
// If you feel the same?
// Do we make stupid jokes?
// Trying to hide that we're both too afraid to say
// I wish I was who you drunk texted at midnight
// Wish I was the reason you stay up 'til 3
// And you can't fall asleep
// Waiting for me to reply
// I wish I was more than just someone you walk by
// Wish I wasn't scared to be honest and open
// Instead of just hoping
// You'd feel what I'm feeling inside
// Oh, and here we go again
// Destroy myself to keep a friend
// Hiding away 'cause I was afraid you'd say no
// I wonder if I cross your mind
// Half as much as you do mine
// If I tell you the truth
// What will I lose?
// I don't know
// I wish I sent you that drunk text at midnight
// I was just scared it would ruin our friendship
// But I really meant it
// I wonder how you would reply
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

ll n, k;
vector<ll> arr(1001); 

ll recur(ll idx, ll currnum) {
    if (idx == n-1) {
        if (currnum > arr[idx]) return INT_MAX/6;
        else return 0;
    } 
    if (arr[idx] >= currnum) return 0;
    else {
        ll sigma = currnum - arr[idx];
        return sigma + recur(idx+1, currnum-1);
    }
}

void solve() {
    cin >> n >> k;
    ll maxn=0, ans = 0;
    for (ll q = 0; q < n; q++) { 
        cin >> arr[q];
        maxn = max(maxn, arr[q]);
    }
    ll lo = maxn, hi = maxn + n + 5;
    while (lo <= hi) {
        ll mid = (lo+hi)/2, check=0;
        for (ll q = 0; q < n; q++) {
            if (recur(q, mid) <= k) {
                check=1; break;
            }
        }
        if (check) {
            ans = max(ans, mid);
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    cout << ans << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}