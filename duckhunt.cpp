// Yeah... yeah

// Somebody loved you
// Somebody set the truth on fire
// And it was me
// A tragedy, yeah, I believe
// I wanna find out
// So burst my bubble, I'm falling to the ground now
// Down on my knees
// And I'm just caught up in

// Lying in my bed, all the things I said
// Think I'm gonna call you but I never
// Fall asleep instead, maybe I'm just dead
// Wishing I could change what we've become now
// But I can't, you'll never forgive me
// Misunderstood, smoking like a chimney
// What you said, now it all makes sense
// Maybe it's a dead-end, now or never

// Somebody told ya
// That words don't hurt, but you're crying on his shoulder
// A part of me, yeah yeah yeah
// Is kinda dead now, I believe
// Some days I fall out
// From your head, guess I'm staying in the dog house
// Insanity, oh-oh
// No clarity at all

// Lying in my bed, all the things I said
// Think I'm gonna call you but I never
// Fall asleep instead, maybe I'm just dead
// Wishing I could change what we've become now
// But I can't, you'll never forgive me
// Misunderstood, smoking like a chimney
// What you said, now it all makes sense
// Maybe it's a dead-end, now or never

// Yeah, yeah, yeah 
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
    ll h, w, n, ans = 1;
    cin >> h >> w >> n;
    pll arr[n];
    for (ll q = 0; q < n; q++) 
        cin >> arr[q].fi >> arr[q].se;
    sort(arr, arr+n);
    vector<int> track(n, -1);
    vector<int> lis;
    for(int i = 0; i < n; i++){
        auto pr = arr[i];
        int it = upper_bound(lis.begin(), lis.end(), pr.second) - lis.begin();
        if(it < lis.size()){
            lis[it] = pr.second;
            track[i] = it + 1;
        }
        else{
            lis.push_back(pr.second);
            track[i] = lis.size();
        }
    }
    cout << lis.size();

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
} 