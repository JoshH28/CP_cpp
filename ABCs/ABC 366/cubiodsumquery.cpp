#include <bits/stdc++.h>
using namespace std;
#define ll long long

int arr[105+1][105+1][105+1]; //Original Array
int sum[105+1][105+1][105+1]; //Array used by RSQ
int rsq(int x1, int y1, int z1, int x2, int y2, int z2) { 
    return sum[x2][y2][z2] 
    - sum[x2][y2][z1-1] - sum[x2][y1-1][z2] - sum[x1-1][y2][z2] 
    + sum[x2][y1-1][z1-1] + sum[x1-1][y2][z1-1] + sum[x1-1][y1-1][z2] 
    - sum[x1-1][y1-1][z1-1];
}

signed main() {
    ll n, qn; cin >> n;
    for (ll q = 1; q<= n; q++) {
        for (ll w = 1; w <= n; w++) {
            for (ll r = 1; r <= n; r++) {
                cin >> arr[q][w][r];
            }
        }
    }
    memset(sum, 0, sizeof(sum)); //Not required if no multiple testcases
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                sum[i][j][k] = sum[i][j][k-1] + sum[i][j-1][k] + sum[i-1][j][k] - sum[i-1][j-1][k] - sum[i-1][j][k-1] - sum[i][j-1][k-1] + sum[i-1][j-1][k-1] + arr[i][j][k];
            }
        }
    }
    cin >> qn;
    ll x1, x2, y1, y2, z1, z2;
    for (ll q = 0; q < qn; q++) {
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        cout << rsq(x1, y1, z1, x2, y2, z2) << "\n";

    }


}