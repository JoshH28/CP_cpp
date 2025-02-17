// Lately, I've been, I've been losing sleep
// Dreaming about the things that we could be
// But baby, I've been, I've been praying hard
// Said, "No more counting dollars, we'll be counting stars"
// Yeah, we'll be counting stars
// I see this life, like a swinging vine
// Swing my heart across the line
// And in my face is flashing signs
// Seek it out and ye shall find
// Old, but I'm not that old
// Young, but I'm not that bold
// And I don't think the world is sold
// On just doing what we're told
// I feel something so right
// Doing the wrong thing
// And I feel something so wrong
// Doing the right thing
// I couldn't lie, couldn't lie, couldn't lie
// Everything that kills me makes me feel alive
// Lately, I've been, I've been losing sleep
// Dreaming about the things that we could be
// But baby, I've been, I've been praying hard
// Said, "No more counting dollars, we'll be counting stars"
// Lately, I've been, I've been losing sleep
// Dreaming about the things we could be
// But baby, I've been, I've been praying hard
// Said, "No more counting dollars, we'll be, we'll be counting stars"
// Yeah, yeah
// I feel your love, and I feel it burn
// Down this river, every turn
// Hope is our four-letter word
// Make that money, watch it burn
// Old, but I'm not that old
// Young, but I'm not that bold
// And I don't think the world is sold
// On just doing what we're told
// And I feel something so wrong
// Doing the right thing
// I couldn't lie, couldn't lie, couldn't lie
// Everything that drowns me makes me wanna fly
// Lately, I've been, I've been losing sleep
// Dreaming about the things that we could be
// But baby, I've been, I've been praying hard
// Said, "No more counting dollars, we'll be counting stars"
// Lately, I've been, I've been losing sleep
// Dreaming about the things that we could be
// But baby, I've been, I've been praying hard
// Said, "No more counting dollars, we'll be, we'll be counting stars"
// Oh, take that money, watch it burn
// Sink in the river the lessons I've learned
// Take that money, watch it burn
// Sink in the river the lessons I've learned
// Take that money, watch it burn
// Sink in the river the lessons I've learned
// Take that money, watch it burn
// Sink in the river the lessons I've learned
// Everything that kills me makes me feel alive
// Lately, I've been, I've been losing sleep
// Dreaming about the things that we could be
// But baby, I've been, I've been praying hard
// Said, "No more counting dollars, we'll be counting stars"
// Lately, I've been, I've been losing sleep
// Dreaming about the things that we could be
// But baby, I've been, I've been praying hard
// Said, "No more counting dollars, we'll be, we'll be counting stars"
// Take that money, watch it burn
// Sink in the river the lessons I've learned
// Take that money, watch it burn
// Sink in the river the lessons I've learned
// Take that money, watch it burn
// Sink in the river the lessons I've learned
// Take that money, watch it burn
// Sink in the river the lessons I've learned
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
#define pq priority_queue
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

struct node {
    int s, e, m, v;
    node *l, *r;
    node(int _s, int _e){
        s = _s; e = _e; m = (s+e)/2; v = INT_MAX;
        if(s != e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }
    void update(int x, int y){
        if(s == e){ v = y; return; }
        if(x <= m) l->update(x, y);
        if(x > m) r->update(x, y);
        v = min(l->v, r->v);
    }
    int query(int x, int y){
        if(s == x && e == y) return v;
        if(y <= m) return l->query(x, y);
        if(x > m) return r->query(x, y);
        return min(l->query(x, m), r->query(m+1, y));
    }
} *root;


void solve() {
    ll n, cn, qn, t1, t2; cin >> n >> cn >> qn;
    ll prevGuy[cn]; 
    memset(prevGuy, -1, sizeof(prevGuy));
    priority_queue<  pll , vector< pll >, greater< pll>  > pq;
    for (ll q = 0; q < n; q++) {
        cin >> t1;
        if (prevGuy[t1] != -1) {
            pq.push(MP(q, prevGuy[t1]));
        }
        prevGuy[t1] = q;
    }
    root =  new node(0, n);
    pair<pll, ll> query[qn];
    ll ans[qn];
    for (ll q = 0; q < qn; q++) {
        cin >> t1 >> t2;
        query[q] =  MP(MP(t2, t1), q);
        //cout << query[q].first.first << "\n";
    }
    //cout << "\n";
    sort(query, query+qn);
    //cout << "yay";
    for (ll q = 0; q < qn; q++) {
        ll left = query[q].first.second, right = query[q].first.first;
        //cout << left << " " << right << "\n";
        ll qi = query[q].second;
        while(!pq.empty() && pq.top().first <= right) {
            ll firstGuy = pq.top().second;
            ll dist = pq.top().first - pq.top().second;
            //cout << firstGuy << " " << pq.top().first << "\n";
            pq.pop();
            root->update(firstGuy, dist);
            //cout << root->query(firstGuy, firstGuy) << "\n";
        }
        ll ANS = root->query(left, right);
        if (ANS == INT_MAX) {
            ans[qi] = -1; continue;
        }
        ans[qi] = ANS;
    }
    //cout << "Time for answers: \n";
    for (ll q = 0; q < qn; q++) {
        cout << ans[q] << "\n";
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}