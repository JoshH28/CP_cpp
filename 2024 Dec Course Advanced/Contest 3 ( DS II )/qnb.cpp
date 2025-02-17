/*
I'm in the thick of it, everybody knows
They know me where it snows, I skied in and they froze
I don't know no nothin' 'bout no ice, I'm just cold
Forty somethin' milli' subs or so, I've been told
I'm in my prime and this ain't even final form
They knocked me down, but still, my feet, they find the floor
I went from living rooms straight out to sold-out tours
Life's a fight, but trust, I'm ready for the war
Woah-oh-oh
This is how the story goes
Woah-oh-oh
I guess this is how the story goes
I'm in the thick of it, everybody knows
They know me where it snows, I skied in and they froze
I don't know no nothin' 'bout no ice, I'm just cold
Forty somethin' milli' subs or so, I've been told
From the screen to the ring, to the pen, to the king
Where's my crown? That's my bling
Always drama when I ring
See, I believe that if I see it in my heart
Smash through the ceiling 'cause I'm reachin' for the stars
Woah-oh-oh
This is how the story goes
Woah-oh-oh
I guess this is how the story goes
I'm in the thick of it, everybody knows
They know me where it snows, I skied in and they froze (woo)
I don't know no nothin' 'bout no ice, I'm just cold
Forty somethin' milli' subs or so, I've been told
Highway to heaven, I'm just cruisin' by my lone'
They cast me out, left me for dead, them people cold
My faith in God, mind in the sun, I'm 'bout to sow (yeah)
My life is hard, I took the wheel, I cracked the code (yeah-yeah, woah-oh-oh)
Ain't nobody gon' save you, man, this life will break you (yeah, woah-oh-oh)
In the thick of it, this is how the story goes
I'm in the thick of it, everybody knows
They know me where it snows, I skied in and they froze
I don't know no nothin' 'bout no ice, I'm just cold
Forty somethin' milli' subs or so, I've been told
I'm in the thick of it, everybody knows (everybody knows)
They know me where it snows, I skied in and they froze (yeah)
I don't know no nothin' 'bout no ice, I'm just cold
Forty somethin' milli' subs or so, I've been told (ooh-ooh)
Woah-oh-oh (nah-nah-nah-nah, ayy, ayy)
This is how the story goes (nah, nah)
Woah-oh-oh
I guess this is how the story goes
*/
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

struct node{
    ll s,e,m, fsum, ssum, v; pll lazy;
    node *l = nullptr,*r = nullptr; //please remember to set to nullptr (if not it might RTE)
    node(ll _s,ll _e){
        s = _s;
        e = _e;
        m = (s + e) / 2;
        fsum = 0, ssum=0;
        v = 0;
        lazy = {0, 0};
    }
    void create(){
        if(l == nullptr && s != e){
            l = new node(s,m);
            r = new node(m + 1,e);
        }
    }
    void propo(){
        create();
        if(lazy.fi == 0 && lazy.se == 0)return;
        v = v + (lazy.fi) * (e - s + 1) * ssum;
        v = v + lazy.se * fsum * (e - s + 1);
        if(s != e){
            l->lazy = {l->lazy.fi + lazy.fi, l->lazy.se + lazy.se};
            r->lazy = {r->lazy.fi + lazy.fi, r->lazy.se + lazy.se};
        }
        lazy = {0, 0};
    }
    void update(ll x,ll y,ll nval, ll state){ // state = 0 --> f, stae = 1 --> s
        if(s == x && e == y) {
            if (state == 0) lazy.fi += nval;
            else lazy.se += nval;
        }
        else{
            create();
            if(x > m) r -> update(x,y,nval, state);
            else if(y <= m) l -> update(x,y,nval, state);
            else l -> update(x,m,nval, state), r -> update(m + 1,y,nval, state);
            l->propo(), r->propo();
            v = l->v + r->v;
        }
    }
    long long query(ll x,ll y){
        create();
        propo();
        if(s == x && e == y){
            return v;
        }else{
            if(x > m) return r->query(x,y);
            else if(y <= m) return l->query(x,y);
            else return l->query(x,m) + r-> query(m + 1,y);
        }
    }
} *root;

void solve() {
    ll n, qn, t1; cin >> n >> qn;
    root = new node(0, n+10);
    for (ll q = 1; q <= n; q++) {
        cin >> t1;
        root->update(q, q, t1, 0);
    }
    for (ll q = 1; q <= n; q++) {
        cin >> t1;
        root->update(q, q, t1, 1);
    }
    ll t2, t3, t4;
    for (ll sus = 0; sus < qn; sus++) {
        cin >> t1;
        if (t1 == 1) {
            cin >> t2 >> t3 >> t4;
            root->update(t2, t3, t4, 0);
        } else if (t1 == 2) {
            cin >> t2 >> t3 >> t4;
            root->update(t2, t3, t4, 1);
        } else {
            cin >> t2 >> t3;
            cout << root->query(t2, t3) << "\n";
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}