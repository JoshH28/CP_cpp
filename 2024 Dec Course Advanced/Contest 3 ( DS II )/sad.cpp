#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll s, e, m, fsum, ssum, troll_sum;
    pair<ll, ll> lazy; // lazy.first -> for fsum, lazy.second -> for ssum
    Node *l = nullptr, *r = nullptr;

    Node(ll _s, ll _e) : s(_s), e(_e), fsum(0), ssum(0), troll_sum(0), lazy({0, 0}) {
        m = (s + e) / 2;
    }

    void create() {
        if (!l && s != e) {
            l = new Node(s, m);
            r = new Node(m + 1, e);
        }
    }

    void apply_lazy() {
        // Update the current node with lazy values
        troll_sum += lazy.first * ssum + lazy.second * fsum;

        if (s != e) { // If not a leaf, propagate lazy values to children
            create();
            l->lazy.first += lazy.first;
            l->lazy.second += lazy.second;
            r->lazy.first += lazy.first;
            r->lazy.second += lazy.second;
        }

        lazy = {0, 0}; // Reset lazy for the current node
    }

    void update(ll x, ll y, ll val, ll type) {
        apply_lazy(); // Apply any pending lazy updates

        if (x > e || y < s) return; // Out of range
        if (x <= s && e <= y) { // Fully in range
            if (type == 0) lazy.first += val;
            else lazy.second += val;
            apply_lazy();
            return;
        }

        // Partially in range
        create();
        l->update(x, y, val, type);
        r->update(x, y, val, type);

        // Recalculate troll_sum
        troll_sum = l->troll_sum + r->troll_sum;
    }

    ll query(ll x, ll y) {
        apply_lazy(); // Ensure all updates are applied before querying

        if (x > e || y < s) return 0; // Out of range
        if (x <= s && e <= y) return troll_sum; // Fully in range

        // Partially in range
        create();
        return l->query(x, y) + r->query(x, y);
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> F(n + 1), S(n + 1);
    Node* root = new Node(1, n);

    // Input for F
    for (ll i = 1; i <= n; i++) cin >> F[i];
    // Input for S
    for (ll i = 1; i <= n; i++) cin >> S[i];

    // Initialize segment tree with F and S
    for (ll i = 1; i <= n; i++) {
        root->update(i, i, F[i], 0); // Update fsum
        root->update(i, i, S[i], 1); // Update ssum
    }

    // Process queries
    while (q--) {
        ll type, l, r, k;
        cin >> type;
        if (type == 1) {
            cin >> l >> r >> k;
            root->update(l, r, k, 0); // Update fsum in range
        } else if (type == 2) {
            cin >> l >> r >> k;
            root->update(l, r, k, 1); // Update ssum in range
        } else if (type == 3) {
            cin >> l >> r;
            cout << root->query(l, r) << "\n"; // Query troll_sum
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
