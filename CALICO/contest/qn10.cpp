// You said don't look back and don't look down
// But here I am, replaying every sound and second since you found me
// All packed up, headed out, I hate to say I need you now
// Here I am, turn around, one more time, I need you now

// Ooh-ooh-ooh, said that I'd be fine without you
// It's not true, I move but can't move on without you
// I'm looking back, looking down, hate to say I need you now
// Ooh-ooh-ooh, said that I'd be fine without you
// Said that I'd be fine without you
// Said that I'd be fine without you

// [?] making sure you're safe and sound
// How your voice sang the songs that made me wanna live forever
// All packed up, headed out, I hate to say I need you now
// Here I am, turn around, one more time, I need you now

// Ooh-ooh-ooh, said that I'd be fine without you
// It's not true, I move but can't move on without you
// I'm looking back, looking down, hate to say I need you now
// Ooh-ooh-ooh, said that I'd be fine without you
// Said that I'd be fine without you
// Said that I'd be fine without you

// Ooh-ooh-ooh, said that I'd be fine without you
// It's not true, I move but can't move on without you
// I'm looking back, looking down, hate to say I need you now
// Ooh-ooh-ooh, said that I'd be fine without you
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) begin(x), end(x)
#define int long long
const int N = 1e5+5;
ll t[4*N], lz[4*N];

void app(int n, int l, int r, ll x) {
    t[n] += x;
    if(l != r) lz[2*n] += x, lz[2*n+1] += x;
    lz[n] = 0;
}

void upd(int n, int l, int r, int ql, int qr, ll x) {
    if(lz[n]) app(n, l, r, lz[n]);
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr) {
        app(n, l, r, x);
        return;
    }
    int m = (l+r)/2;
    upd(2*n, l, m, ql, qr, x);
    upd(2*n+1, m+1, r, ql, qr, x);
    t[n] = t[2*n];
}

ll qry(int n, int l, int r, int p) {
    if(lz[n]) app(n, l, r, lz[n]);
    if(l == r) return t[n];
    int m = (l+r)/2;
    return p <= m ? qry(2*n, l, m, p) : qry(2*n+1, m+1, r, p);
}

ll solve(vector<ll>& a) {
    int n = a.size();
    ll ans = 1e18;
    for(int k = 1; k < n; k++) {
        ll g1 = a[0], g2 = a[k];
        for(int i = 1; i < k; i++) g1 = __gcd(g1, a[i]);
        for(int i = k+1; i < n; i++) g2 = __gcd(g2, a[i]);
        vector<ll> d1, d2;
        for(ll i = 1; i*i <= g1; i++) {
            if(g1%i == 0) {
                d1.pb(i);
                if(i*i != g1) d1.pb(g1/i);
            }
        }
        sort(all(d1));
        for(ll i = 1; i*i <= g2; i++) {
            if(g2%i == 0) {
                d2.pb(i);
                if(i*i != g2) d2.pb(g2/i);
            }
        }
        sort(all(d2));
        
        for(ll x1 : d1) {
            if(x1 <= 0) continue;
            bool ok = 1;
            for(int i = 0; i < k && ok; i++) 
                if(a[i]%x1) ok = 0;
            if(!ok) continue;
            
            for(ll x2 : d2) {
                if(x2 <= 0) continue;
                ok = 1;
                for(int i = k; i < n && ok; i++)
                    if(a[i]%x2) ok = 0;
                if(!ok) continue;
                ll sum = 0;
                for(int i = 0; i < k; i++) sum += a[i]/x1;
                for(int i = k; i < n; i++) sum += a[i]/x2;
                ans = min(ans, sum);
            }
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        upd(1, 0, n-1, i, i, a[i]);
    }
    int q; cin >> q;
    while(q--) {
        string s; cin >> s;
        if(s[0] == 'U') {
            int l, r; ll x;
            cin >> l >> r >> x;
            upd(1, 0, n-1, --l, --r, x);
        } else {
            vector<ll> cur(n);
            for(int i = 0; i < n; i++) 
                cur[i] = qry(1, 0, n-1, i);
            cout << solve(cur) << '\n';
        }
    }
    return 0;
}