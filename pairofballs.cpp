// [Verse 1]
// Waking up back home in New York City
// And I know I miss you, and I hope you miss me too, yeah
// The days away leave me feeling so empty
// But I can't wait 'til I can take you with me, ooh yeah

// [Pre-Chorus]
// Say, you're gonna stay with me
// Don't you let me go, no
// You're the kinda love for me
// You already know
// Come back home late
// And fall right into your bed (Oh, oh, oh)
// Every time I feel it over again

// [Chorus]
// You're throwing fuel into my fire
// Racing, making me bleed
// Do you still feel it in your chest
// The way you did at sixteen?
// Didn't know I was alive
// Until you made my heart beat
// Thought my youth was going quickly
// But you give me sixteen

// [Verse 2]
// I'm tryna find my way through LAX
// And I'm so lost, don't know what to expect to ya
// Growing up means growing tired, I guess, yeah
// But nothing gets me when I'm right here next to you, yeah

// [Pre-Chorus]
// Say, you're gonna stay with me
// Don't you let me go, no
// You're the kinda love for me
// You already know
// Come back home late
// And fall right into your bed (Oh, oh, oh)
// Every time I feel it over again

// You're throwing fuel into my fire
// Racing, making me bleed
// Do you still feel it in your chest
// The way you did at sixteen?
// Didn't know I was alive
// Until you made my heart beat
// Thought my youth was going quickly
// But you give me sixteen

// [Bridge]
// Do you still feel it?
// Do you still feel it?
// Do you still feel it?
// Do you still feel it?
// Do you still feel it?
// Do you still feel it?
// I thought my youth was going quickly (Do you still feel it?)
// But you give me sixteen
// [Chorus]
// You're throwing fuel into my fire
// Racing, making me bleed
// Do you still feel it in your chest
// The way you did at sixteen?
// Didn't know I was alive
// Until you made my heart beat
// I thought my youth was going quickly
// But you give me sixteen
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
    ll balln, cn, t1, t2; cin >> balln >> cn;
    unordered_map<ll,ll> mp;
    queue<ll> arr[cn+1];
    for (ll q = 1; q <= cn; q++) {
        cin >> t1;
        for (ll w =0; w < t1; w++) {
            cin >> t2; 
            arr[q].push(t2); 
            //cout << t2;
            //cout << arr[q].front();
        }
        //cout << "\n";
    }
    queue<ll> operations;
    for (ll q = 1; q <= cn; q++) {
        if (mp[arr[q].front()] == 0) {
            mp[arr[q].front()] = q;
            //cout << arr[q].front() << "\n";
        } else {
            operations.push(q);
            operations.push(mp[arr[q].front()]);
            //cout << q << " " << mp[arr[q].front()] << "\n";
        }
    }
    while(!operations.empty()) {
        ll currc = operations.front();
        operations.pop();
        arr[currc].pop();
        if (arr[currc].empty()) continue;
        if (mp[arr[currc].front()] == 0) {
            mp[arr[currc].front()] = currc;
        } else {
            operations.push(currc);
            operations.push( mp[arr[currc].front()]);
        }
        //cout << currc << " ";
    }
    for (ll q = 1; q <= cn; q++) {
        if (arr[q].size()) {
            cout << "No"; return;
        }
    }
    cout << "Yes"; return;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}