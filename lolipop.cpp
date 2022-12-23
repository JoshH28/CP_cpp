#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void solve()
{
    string word;
    cin >> word;
    unordered_set<char> mp;
    for (ll q = 0; q < word.length(); q++)
    {
        if (mp.find(word[q]) == mp.end())
        {
            mp.emplace(word[q]);
        }
    }
    ll ans = mp.size() / 3;
    if (mp.size() % 3 != 0)
    {
        ans += 1;
    }
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