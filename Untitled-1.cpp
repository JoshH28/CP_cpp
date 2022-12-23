#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void solve()
{
    ll ans = 0;
    cin >> ans;
    ll temp = log10(ans);
    ans -= floor(pow(10, temp));
    cout << ans << endl;
}

int main()
{
    ll tc;
    cin >> tc;
    while (tc > 0)
    {
        solve();
        tc--;
    }
}