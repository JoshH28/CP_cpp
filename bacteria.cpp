// [Chorus: Conor Maynard]
// Remember when I told you
// "No matter where I go
// I'll never leave your side
// You will never be alone"
// Even when we go through changes
// Even when we're old
// Remember that I told you
// I'll find my way back home

// [Verse 1: Conor Maynard]
// I could never let you go
// Couldn't run away if I tried
// 'Cause even when I'm all alone
// You still got a hold on my mind
// And I'll always let you know
// That I'm always gonna hold on

// [Pre-Chorus: Conor Maynard]
// And I told you right from the start
// You just say the word and I'll go
// No, it doesn't matter how far
// 'Cause your love is all that I know
// Baby you just stay where you are
// And you know I won't be too long
// Hold on
// Hold on

// [Chorus: Conor Maynard]
// Remember when I told you
// "No matter where I go
// I'll never leave your side
// You will never be alone"
// Even when we go through changes
// Even when we're old
// Remember that I told you
// I'll find my way back home

// [Verse 2: SHAUN]
// 조용히 잠든 방을 열어 기억을 꺼내 들어
// 부서진 시간 위에서 선명히 너는 떠올라
// 길 잃은 마음속에 널 가둔 채 살아
// 그만 그만

// [Chorus: SHAUN]
// 멈춘 시간 속 잠든 너를 찾아가
// 아무리 막아도 결국 너의 곁인 걸
// 길고 긴 여행을 끝내 이젠 돌아가
// 너라는 집으로 지금 다시 way back home

// [Bridge: SHAUN, Conor Maynard]
// 세상을 뒤집어 찾으려 해
// 오직 너로 완결된 이야기를
// No, I won't ever lose
// As long as you're there
// [Chorus: SHAUN, Conor Maynard]
// 빛이 다 꺼진 여기 나를 안아줘
// 눈을 감으면 소리 없이 밀려와
// 이 마음 그 위로 넌 또 한 겹 쌓여가
// Even when we go through changes
// Even when we're old
// Remember that I told you
// I'll find my way back home
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

ll n, d, qn, t1, t2 , t3, t4;

struct node {// segment tree with beats
    ll start, end, mid, value;
    node *l, *r;
    node(ll S, ll E) {
        start = S; end = E; mid = (start + end)/2;
        if (start != end) {
            l = new node(start, mid);
            r = new node(mid+1, end);
        }
    }

    void pointUpdate(ll pos, ll uv) {
        //if (value == 0) return;
        if (start == end) {
            value = uv;
        } else {
            if (pos <= mid) {
                l->pointUpdate(pos, uv);
            } else {
                r->pointUpdate(pos, uv);
            }
            value = r->value + l->value;
        }
    }

    void rangeUpdate(ll left, ll right, ll d) {
        if (value == 0 || d == 1) return; // the part that makes stree into stree beats
        if (start == end) {
            value /= d;
            return;
        } else {
            if (left > mid) {
                r->rangeUpdate(left, right, d);
            } else if (right <= mid) {
                l->rangeUpdate(left, right, d);
            } else {
                l->rangeUpdate(left, mid, d); r->rangeUpdate(mid+1, right, d);
            }
            value = r->value + l->value;
        }
    }

    ll rangeQuery(ll left, ll right) {
        if (start == left && end == right) {
            return value;
        } else {
            if (left > mid) {
                return r->rangeQuery(left, right);
            } else if (right <= mid) {
                return l->rangeQuery(left, right);
            } else {
                return l->rangeQuery(left, mid) + r->rangeQuery(mid+1, right);
            }
        }
    }

}*root;


void solve() {
    cin >> n >> qn; // work in progress
    root = new node(0, n-1);
    for (ll q = 0; q < n; q++) {
        cin >> t1; root->pointUpdate(q, t1);
    }
    for (ll q = 0; q < qn; q++) {
        cin >> t1;
        if (t1 == 1) {
            cin >> t2 >> t3;
            root->pointUpdate(t2, t3);
        } else if (t1 == 0) {
            cin >> t2 >> t3 >> t4;
            root->rangeUpdate(t2, t3, t4);
        } else {
            cin >> t2 >> t3;
            cout << root->rangeQuery(t2, t3) << "\n";
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}