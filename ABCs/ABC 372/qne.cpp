// I've been on this phone, sitting all alone, missing ya
// You be on Patron, losing self control, living up

// They say you live, you learn
// But it's hard to learn when you fall out
// You left me and it hurts
// Bandaids, they don't work and I'm all out

// Ooh, you never pick up and I've been tryna call ya
// Lately I've been roaming the streets of California
// Looking for your red lips, got some roses for ya
// I've been running circles, I'm lost in California

// Got me turning sticks and stones
// Got me breaking every bone
// Got me out here looking for ya
// Babe, you never pick up and I've been tryna call ya
// Lately I've been roaming the streets of California

// I've been counting stars on top of my car, wishing ya
// Would call me back and talk, mend this broken heart, giving up

// They say you live, you learn
// But it's hard to learn when you fall out
// You left me and it hurts
// Pills, they don't work and I'm all out

// Ooh, you never pick up and I've been tryna call ya
// Lately I've been roaming the streets of California
// Looking for your red lips, got some roses for ya
// I've been running circles, I'm lost in California

// Got me turning sticks and stones
// Got me breaking every bone
// Got me out here looking for ya
// Babe, you never pick up and I've been tryna call ya
// Lately I've been roaming the streets of California

// And ah, I've been running 'round in California
// And ah, I've been running 'round in California

// If someone don't love you, let 'em go
// Don't try to make fire in the snow
// The longer you wait, the fire grows
// If someone don't love you, let 'em go
// Don't try to make fire in the snow
// The longer you wait, the fire grows, grows

// Ooh, you never pick up and I've been tryna call ya
// Lately I've been roaming the streets of California
// Looking for your red lips, got some roses for ya
// I've been running circles, I'm lost in California

// Got me turning sticks and stones
// Got me breaking every bone
// Got me out here looking for ya
// Babe, you never pick up and I've been tryna call ya
// Lately I've been roaming the streets of California

// I've been running California
// And ah, I've been running 'round in California
// I've been running 'round

// And ah, I've been running 'round in California 
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

const ll MAXN = 200010;

struct DSU {
    ll parent[MAXN];
    ll size[MAXN];
    ll sizeOfMax = 1;
    priority_queue<ll> largestComponents[MAXN];
    DSU(ll n) {
        for (ll q = 1; q <= n; q++) {
            parent[q] = q;
            size[q] = 1;
            largestComponents[q].push(q);
        }
    }
    ll par(ll x) {
        if (parent[x] == x) {
            return x;
        } else {
            ll pathCompression = par(parent[x]);
            parent[x] = pathCompression; // path compression;
            return pathCompression;
        }
    }
    void merge(ll x, ll y) {
        if (par(x) == par(y)) return;
        ll cnt = 10;
        if (size[par(x)] < size[par(y)]) {
            while (largestComponents[par(x)].size() && cnt > 0) {
                largestComponents[par(y)].push(largestComponents[par(x)].top());
                largestComponents[par(x)].pop(); cnt--;
            }
            size[par(y)] += size[par(x)];
            parent[par(x)] = par(y);
            sizeOfMax = max(sizeOfMax, size[par(y)]);
        } else {
            ll cnt = 10;
            while (largestComponents[par(y)].size() && cnt > 0) {
                largestComponents[par(x)].push(largestComponents[par(y)].top());
                largestComponents[par(y)].pop(); cnt--;
            }
            size[par(x)] += size[par(y)];
            parent[par(y)] = par(x);
            sizeOfMax = max(sizeOfMax, size[par(x)]);
        }
    }
    bool isSameSet(ll x, ll y) {
        return par(x) == par(y);
    }
    ll query(ll x, ll k) {
        stack<ll> temp;
        if (largestComponents[par(x)].size() < k) return -1;
        for (ll q = 0; q < k-1; q++) {
            temp.push(largestComponents[par(x)].top());
            largestComponents[par(x)].pop();
        }
        ll ans = largestComponents[par(x)].top();
        while (temp.size()) {
            largestComponents[par(x)].push(temp.top());
            temp.pop();
        }
        return ans;
    }
}*gay;

void solve() {
    ll n, qn, t1, t2, t3; cin >> n >> qn;
    gay = new DSU(n+10);
    for (ll q = 0; q < qn; q++) {
        cin >> t1 >> t2 >> t3;
        if (t1 == 1) {
            gay->merge(t2, t3);
        } else {
            cout << gay->query(t2, t3) << "\n";
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}