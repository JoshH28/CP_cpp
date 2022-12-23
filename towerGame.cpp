#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
    ll r, c;
    cin >> r >> c;
    string arr[r + 1][c + 1];
    for (ll q = 1; q <= r; q++)
    {
        for (ll w = 1; w <= c; w++)
        {
            if (w % 2 == 1)
            {
                arr[q][w] = "W";
                // cout << w << " " << q;
            }
            else
            {
                arr[q][w] = "B";
                // cout << w << " " << q;
            }
        }
    }
    for (ll q = 1; q <= r; q++)
    {
        for (ll w = 1; w <= c; w++)
        {
            cout << arr[q][w];
            // cout << q << " " << w;
        }
        cout << endl;
    }
}