#include <bits/stdc++.h>
using namespace std;
#define int long long
int findXorSum(int arr[], int n)
{
    int sum = 0;
    int mul = 1;
    for (int i = 0; i < 30; i++) {
        int c_odd = 0;
        bool odd = 0;
        for (int j = 0; j < n; j++) {
            if ((arr[j] & (1 << i)) > 0)
                odd = (!odd);
            if (odd)
                c_odd++;
        }
        for (int j = 0; j < n; j++) {
            sum += (mul * c_odd);
 
            if ((arr[j] & (1 << i)) > 0)
                c_odd = (n - j - c_odd);
        }
        mul *= 2;
    }
    return sum;
}
signed main()
{
    int n; cin >> n; int arr[n];
    for (int q = 0; q < n; q++) cin >> arr[q];
    cout << findXorSum(arr, n);
    return 0;
}
