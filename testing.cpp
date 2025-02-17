#include <bits//stdc++.h>
using namespace std;
#define ll long long
#define iloop(m, h) for (auto i = m; i != h; i+=(m<h?1:-1))
#define jloop(m, h) for (auto j = m; j != h; j+=(m<h?1:-1))
#define kloop(m, h) for (auto k = m; k != h; k+=(m<h?1:-1))
#define lloop(m, h) for (auto l = m; l != h; l+=(m<h?1:-1))
#define iloop_(m, h, g) for (auto i = m; i != h; i+=g)
#define jloop_(m, h, g) for (auto j = m; j != h; j+=g)
#define kloop_(m, h, g) for (auto k = m; k != h; k+=g)
#define lloop_(m, h, g) for (auto l = m; l != h; l+=g)
#define getchar_unlocked _getchar_nolock // comment before submission
#define pll pair<ll,ll>
#define plll pair<ll, pll>
#define pllll pair<pll, pll>
#define vll vector<ll>
#define qll queue<ll>
#define dll deque<ll>
#define pqll priority_queue<ll>
#define gll greater<ll>
#define INF 1000000000000000
#define MOD1 1000000007
#define MOD2 998244353
#define MOD3 1000000009
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
struct node {
	ll s, e, m, v = 0;
	node *l, *r;
	node (ll S, ll E) {
		s = S, e = E, m = (S+E)>>1;
		if (s != e) {
			l = new node(s, m);
			r = new node(m+1, e);
		}
	}
	void upd(ll X, ll V) {
		if (s == e) v += V;
		else {
			if (X <= m) l->upd(X, V);
			else  r->upd(X, V);
			v = l->v + r->v;
		}
	}
	ll query(ll S, ll E) {
		if (E < S) return 0;
		if (s == S && e == E) return v;
		if (E <= m) return l->query(S, E);
		if (S > m) return r->query(S, E);
		return l->query(S, m) + r->query(m+1, E);
	}
} *root = new node(0, 100005);
ll block_size = 100;
bool cmp(pllll a, pllll b) {
	if (a.first.first != b.first.first) return a.first.first < b.first.first;
	return a.first.second < b.first.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    ll a[n];
    pllll queries[q];
    set<ll> st;
    map<ll, ll> mp;
    iloop(0, n) {cin >> a[i]; st.insert(a[i]);}
    ll cnt = 0;
    for (auto it : st) {
		mp[it] = cnt;
		cnt++;
	}
	iloop(0, n) a[i] = mp[a[i]];
    iloop(0, q) {
		cin >> queries[i].second.first >> queries[i].first.second;
		queries[i].second.first--, queries[i].first.second--;
		queries[i].first.first = queries[i].second.first/block_size;
		queries[i].second.second = i;
	}
	sort(queries, queries+q, cmp);
	cnt = 0;
	ll lptr = 0, rptr = 0, cans = 0;
	root->upd(a[0], 1);
	ll ans[q];
	iloop(0, block_size) {
		while (cnt < q && queries[cnt].first.first == i) {
			while (queries[cnt].first.second < rptr) {
				cans -= root->query(a[rptr]+1, 100005);
				root->upd(a[rptr], -1);
				rptr--;
			}
			while (queries[cnt].first.second > rptr) {
				rptr++;
				cans += root->query(a[rptr]+1, 100005);
				root->upd(a[rptr], 1);
			}
			while (queries[cnt].second.first < lptr) {
				lptr--;
				cans += root->query(0, a[lptr]-1);
				root->upd(a[lptr], 1);
			}
			while (queries[cnt].second.first > lptr) {
				cans -= root->query(0, a[lptr]-1);
				root->upd(a[lptr], -1);
				lptr++;
			}
			ans[queries[cnt].second.second] = cans;
			cnt++;
		}
	}
	iloop(0, q) cout << ans[i] << "\n";
}
