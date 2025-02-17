#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    ordered_set online; 
    unordered_map<long long, long long> freq; 
    long long n;
    scanf("%lld", &n); 
    for (long long i = 0; i < n; i++) {
        long long type, x;
        scanf("%lld %lld", &type, &x);
        if (type == 1) {
            if (freq[x] == 0) online.insert(x); 
            freq[x]++;
        } else if (type == 2) {
            freq[x]--;
            if (freq[x] == 0) online.erase(x);
        } else if (type == 3) {
            auto it = online.lower_bound(x);
            if (it == online.end()) {
                printf("-1\n");
            } else {
                printf("%lld\n", *it);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
