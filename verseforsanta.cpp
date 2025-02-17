#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
      cin >> a[i];

    ll total = 0, max_time = 0, max_index = -1, skip_index = 0;

    for (ll i = 0; i < n; i++)
    {
      total += a[i];
      if (a[i] > max_time)
      {
        max_time = a[i];
        max_index = i;
      }

      if (total > s)
      {
        if (total - max_time <= s)
          skip_index = max_index + 1;
        else
          skip_index = 0;
        break;
      }
    }

    cout << skip_index << "\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
