#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pll pair<long long int,long long int>
#define int long long
typedef long long ll;
const int MAX_DIGITS = 19;

int dp[MAX_DIGITS][10][2][2];

int count_snake(string &num, int pos, int prev_d, bool limit, bool lead) {
    if (pos == num.size()) return 1;
    if (dp[pos][prev_d][limit][lead] != -1) return dp[pos][prev_d][limit][lead];

    int res = 0;
    int end = limit ? num[pos] - '0' : 9;

    for (int d = 0; d <= end; d++) {
        if (lead || d < prev_d) {
            res += count_snake(num, pos + 1, lead && d == 0 ? 9 : d, limit && d == end, lead && d == 0);
        }
    }
    return dp[pos][prev_d][limit][lead] = res;
}

int solve(int x) {
    string num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return count_snake(num, 0, 9, true, true) - 1;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << endl;
    return 0;
}
