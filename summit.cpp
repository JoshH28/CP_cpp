#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll height = 14;
ll days = 2;
ll constant;

ll setup()
{
    ll hold = 1;
    for (ll q = days; q <= height - 2; q++)
    {
        hold *= q;
    }
    return hold;
}

int main()
{
    cin >> height;
    cin >> days;
    constant = setup();
    ll lo = 1, hi = height;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        ll count = 1;
        while(1) {
            tmp = mid/
        }
        if (mid < constant && mid + 1 > constant)
            cout << mid;
        return 0;
        if (mid >= constant)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << lo;
}