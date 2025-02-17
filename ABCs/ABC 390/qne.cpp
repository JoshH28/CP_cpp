#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int N, X;
    cin >> N >> X;
    vector<tuple<int, int, int>> foods(N);
    for (int i = 0; i < N; ++i) {
        int V, A, C;
        cin >> V >> A >> C;
        foods[i] = make_tuple(V, A, C);
    }
    vector<vector<int>> dp1(X + 1, vector<int>(N + 1, -1e9));
    vector<vector<int>> dp2(X + 1, vector<int>(N + 1, -1e9));
    vector<vector<int>> dp3(X + 1, vector<int>(N + 1, -1e9));
    dp1[0][0] = dp2[0][0] = dp3[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        int V = get<0>(foods[i - 1]);
        int A = get<1>(foods[i - 1]);
        int C = get<2>(foods[i - 1]);
        for (int j = 0; j <= X; ++j) {
            dp1[j][i] = dp1[j][i - 1];
            dp2[j][i] = dp2[j][i - 1];
            dp3[j][i] = dp3[j][i - 1];
            if (j >= C) {
                if (V == 1) dp1[j][i] = max(dp1[j][i], dp1[j - C][i - 1] + A);
                else dp1[j][i] = max(dp1[j][i], dp1[j - C][i - 1]);
                
                if (V == 2) dp2[j][i] = max(dp2[j][i], dp2[j - C][i - 1] + A);
                else dp2[j][i] = max(dp2[j][i], dp2[j - C][i - 1]);
                
                if (V == 3) dp3[j][i] = max(dp3[j][i], dp3[j - C][i - 1] + A);
                else dp3[j][i] = max(dp3[j][i], dp3[j - C][i - 1]);
            }
        }
    }

    auto is_valid = [&](int target) {
        for (int j = 0; j <= X; ++j) {
            if (min({dp1[j][N], dp2[j][N], dp3[j][N]}) >= target)
                return true;
        }
        return false;
    };
    int low = 0, high = 1e9, answer = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (is_valid(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
