#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

bool is_geometric_progression(vector<long long>& a) {
    if(a.size() <= 1) return false;
    if(a.size() == 2) return true;
    if(a[0] == 0) return all_of(a.begin(), a.end(), [](long long x) { return x == 0; });
    long long num = a[1], den = a[0];
    long long gcd_val = __gcd(num, den);
    num /= gcd_val;
    den /= gcd_val;
    
    rep(i, 2, a.size()) {
        long long curr_num = a[i], curr_den = a[i-1];
        long long curr_gcd = __gcd(curr_num, curr_den);
        curr_num /= curr_gcd;
        curr_den /= curr_gcd;
        if(curr_num * den != curr_den * num) return false;
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<long long> a(n);
    rep(i, 0, n) cin >> a[i];

    cout << (is_geometric_progression(a) ? "Yes" : "No") << '\n';
    return 0;
}