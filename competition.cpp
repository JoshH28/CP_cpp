#include <bits/stdc++.h>
using namespace std;

int main()
{
    int totalNum;
    int bNum;
    int pNum;
    cin >> totalNum;
    cin >> bNum;
    cin >> pNum;
    vector<pair<int, int>> arr(totalNum);

    for (int q = 0; q < totalNum; q++)
    {
        cin >> arr[q].first;
    }
    for (int q = 0; q < totalNum; q++)
    {
        cin >> arr[q].second;
    }
    unordered_map<long long int, queue<pair<int, int>>> mp;
    vector<long long int> combiA;
    for (int q = 0; q < totalNum; q++)
    {
        long long int bioScore = arr[q].first;
        long long int physicScore = arr[q].second;
        long long int combined = bioScore - physicScore;
        mp[combined].push(make_pair(bioScore, physicScore));
        combiA.push_back(combined);
    }
    sort(combiA.begin(), combiA.end());
    long long int sum = 0;
    for (long long int q = 0; q < pNum; q++)
    {
        sum += mp[combiA[q]].front().second;
        mp[combiA[q]].pop();
    }
    reverse(combiA.begin(), combiA.end());
    for (long long int q = 0; q < bNum; q++)
    {
        sum += mp[combiA[q]].front().first;
        mp[combiA[q]].pop();
    }
    cout << sum;
}