#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define ll long long int
#define endl "\n"

#define MAX_SIZE 1000005
ll dp[MAX_SIZE];
void SieveOfEratosthenes(vector<ll> &primes)
{
    bool IsPrime[MAX_SIZE];
    memset(IsPrime, true, sizeof(IsPrime));
    dp[0] = 0;
    dp[1] = 0;
    for (int p = 2; p * p < MAX_SIZE; p++)
    {
        if (IsPrime[p] == true)
        {
            dp[p] = dp[p - 1] + 1;
            for (int i = p * p; i < MAX_SIZE; i += p)
                IsPrime[i] = false;
        }
        else
        {
            dp[p] = dp[p - 1];
        }
    }
    for (int p = 2; p < MAX_SIZE; p++)
        if (IsPrime[p])
            primes.push_back(p);
}

int main()
{
    ll tc, num;
    cin >> tc;
    vector<ll> primes;
    SieveOfEratosthenes(primes);
    for (ll q = 0; q < tc; q++)
    {
        cin >> num;
        cout << primes[num - 1] << endl;
    }
}