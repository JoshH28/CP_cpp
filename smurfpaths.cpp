// [Verse 1]
// You have my heart
// We'll never be worlds apart
// May be in magazines
// But you'll still be my star
// Baby, 'cause in the dark
// You can't see shiny cars
// And that's when you need me there
// With you I'll always share
// Because

// [Chorus]
// When the sun shine, we'll shine together
// Told you I'll be here forever
// Said I'll always be your friend
// Took an oath and I'm stick it out till the end
// Now that it's raining more than ever
// Know that we still have each other
// You can stand under my umbrella
// You can stand under my umbrella

// [Post-Chorus]
// (Ella, ella, eh, eh, eh)
// Under my umbrella
// (Ella, ella, eh, eh, eh)
// Under my umbrella
// (Ella, ella, eh, eh, eh)
// Under my umbrella
// (Ella, ella, eh, eh, eh, eh)

// [Verse 2]
// These fancy things
// Will never come in between
// You're part of my entity
// Here for infinity
// When the war has took its part
// When the world has dealt its cards
// If the hand is hard
// Together we'll mend your heart
// Because

// [Chorus]
// When the sun shine, we'll shine together
// Told you I'll be here forever
// Said I'll always be your friend
// Took an oath and I'm stick it out till the end
// Now that it's raining more than ever
// Know that we still have each other
// You can stand under my umbrella
// You can stand under my umbrella

// [Post-Chorus]
// (Ella, ella, eh)
// Under my umbrella
// (Ella, ella, eh)
// Under my umbrella
// (Ella, ella, eh)
// Under my umbrella
// (Ella, ella, eh, eh, eh, eh, eh)
// [Outro]
// It's raining
// Ooh, baby it's raining
// You can always come into me, come into me
// It's raining
// Ooh, baby it's raining
// You can always come into me, come into me
// It's raining
// Ooh, baby it's raining
// You can always come into me, come into me
// It's raining
// Ooh, baby it's raining
// You can always come into me, come into me
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

const ll N = 1e6+1;
int fw[N], fw2[N], pre[N], post[N], arr[N];
vector<ll> adjlist[N];
ll n, counter = 1, limit, t1, t2, t3, qn;

void update(int x, int y, int v) { //inclusive
   for (int tx=x; tx < N; tx += tx&(-tx)) fw[tx] += v, fw2[tx] -= v*(x-1);
    for (int ty=y+1; ty < N; ty += ty&(-ty)) fw[ty] -= v, fw2[ty] += v*y;
}
int sum (int x) {
   int res = 0;
   for (int tx=x; tx; tx -= tx&(-tx)) res += fw[tx]*x + fw2[tx];
   return res;
}
int range_sum(int x, int y) { //inclusive
   return sum(y)-sum(x-1);
}

typedef long long ll;
struct node {
    ll start, end, mid, lazy=0;
    pll value;
    node *l, *r;
    node (ll s, ll e) {
        start = s; end = e; mid = (start+end)/2;
        lazy = 0; value = MP(0, start);
        if (start != end) {
            l = new node(start, mid);
            r = new node(mid+1, end);
        }
    }

    pll prop() {
        if (lazy == 0) return value;
        value.first += lazy;
        if (start != end) {
            l->lazy += lazy;
            r->lazy += lazy;
        }
        lazy = 0;
        return value;
    }

    void upd(ll left, ll right, ll val) {
        prop();
        if (start == left && right == end) {
            lazy += val;
        } else {
            if (left > mid) {
                r->upd(left, right, val);
            } else if (right <= mid) {
                l->upd(left, right, val);
            } else {
                l->upd(left, mid, val);
                r->upd(mid+1, right, val);
            }
            r->prop(), l->prop();
            value = max(l->prop(), r->prop());
        }
    }

    pll qry(ll left, ll right) {
        prop();
        if (left == start && right == end) {
            return prop();
        } else {
            if (left > mid) {
                return r->qry(left, right);
            } else if (right <= mid) {
                return l->qry(left, right);
            } else {
                return max(l->qry(left, mid), r->qry(mid+1, right));
            }
        }
    }
} *root;

void dfs(ll node, ll par) {
    pre[node] = counter; counter++;
    for (auto it: adjlist[node]) {
        if (it != par) dfs(it, node);
    }
    post[node] = counter-1;
}


void solve() {
    cin >> n >> limit;
    root = new node(1, n);
    for (ll q = 1; q <= n; q++) {
        cin >> arr[q];
    }
    for (ll q = 0; q < n-1; q++) {
        cin >> t1 >> t2;
        adjlist[t1].push_back(t2);
        adjlist[t2].push_back(t1);
    }
    dfs(1, -1);
    //cout << "\n";
    for (ll q = 1; q <= n ;q++) {
        root->upd(pre[q], pre[q], arr[q]); // need to *3 when querying idk why
        //cout << root->qry(pre[q], pre[q]).first << " ";
    }
    cin >> qn;
    for (ll q = 0; q < qn; q++) {
        cin >> t1;
        pll lol = root->qry(1, n);
        while(lol.first >= limit) {
            root->upd(lol.second, lol.second, LLONG_MIN);
            update(lol.second, lol.second, 1);
            lol = root->qry(1, n);
        }
        if (t1 == 1) {
            cin >> t2 >> t3;
            root->upd(pre[t2], post[t2], t3);
            pll lol = root->qry(pre[t2], post[t2]);
            while(lol.first >= limit) {
                root->upd(lol.second, lol.second, LLONG_MIN);
                update(lol.second, lol.second, 1);
                lol = root->qry(pre[t2], post[t2]);
            }
        } else {
            cin >> t2;
            ll ans = range_sum(pre[t2], post[t2]);
            ll sus = range_sum(1, n);
            ans  = ans*(sus-ans);
            cout << ans << "\n";
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}