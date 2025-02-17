#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, a, b, limit;
    cin >> n >> limit;
    ll cat[n + 1];
    ll shortest[n + 1];
    vector<ll> adjlist[n + 1];
    for (ll q = 1; q <= n; q++)
    {
        cin >> cat[q];
    }
    for (ll q = 0; q < n - 1; q++)
    {
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    // ll visited[n + 1];
    // memset(visited, 0, sizeof(visited));
    for (ll q = 0; q <= n; q++)
    {
        shortest[q] = LONG_LONG_MAX;
    }
    vector<ll> leaf;
    queue<pair<ll, pair<ll, ll>>> bfs;
    bfs.push(make_pair(1, make_pair(cat[1], 0)));
    while (!bfs.empty())
    {
        ll curr = bfs.front().first;
        ll catno = bfs.front().second.first;
        ll cnt = bfs.front().second.second;
        bfs.pop();
        // cout << curr << "\n";
        if (cnt < shortest[curr])
        {
            shortest[curr] = cnt;
        }
        // else if (cnt == shortest[curr])
        //{
        //     pain[curr] = min(catno, pain[curr]);
        // }
        else
        {
            continue;
        }
        for (auto it : adjlist[curr])
        {
            ll targetno = it;
            if (shortest[targetno] > cnt + 1)
            {
                if (cat[targetno] == 0)
                {
                    bfs.push(make_pair(targetno, make_pair(0, cnt + 1)));
                }
                else
                {
                    if (cat[targetno] + catno <= limit)
                    {
                        bfs.push(make_pair(targetno, make_pair(catno + cat[targetno], cnt + 1)));
                    }
                }
            }
        }
        if (adjlist[curr].size() == 1)
        {
            leaf.push_back(curr);
        }
    }
    ll ans = 0;
    // cout << limit << "\n";
    for (auto it : leaf)
    {
        // cout << it << " ";
        if (shortest[it] < LONG_LONG_MAX)
        {
            ans++;
        }
    }
    cout << ans;
}