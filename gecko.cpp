#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rowNum = 0;
    int colNum = 0;
    cin >> rowNum;
    cin >> colNum;
    int arr[rowNum][colNum];
    int holdA[rowNum][colNum];
    for (int q = 0; q < rowNum; q++)
    {
        for (int w = 0; w < colNum; w++)
        {
            cin >> arr[q][w];
            holdA[q][w] = arr[q][w];
        }
    }
    for (int r = 0; r < rowNum - 1; r++)
    {
        if (arr[r + 1][0] + holdA[r][0] > holdA[r + 1][0])
        {
            holdA[r + 1][0] = holdA[r + 1][0] + arr[r][0];
        }
        if (arr[r + 1][1] + holdA[r][0] > holdA[r + 1][1])
        {
            holdA[r + 1][1] = holdA[r + 1][1] + arr[r][0];
        }
        for (int t = 1; t < colNum - 1; t++)
        {
            if (arr[r + 1][t - 1] + holdA[r][t] > holdA[r + 1][t - 1])
            {
                holdA[r + 1][t - 1] = arr[r + 1][t - 1] + holdA[r][t];
            }
            if (arr[r + 1][t] + holdA[r][t] > holdA[r + 1][t])
            {
                holdA[r + 1][t] = arr[r + 1][t] + holdA[r][t];
            }
            if (arr[r + 1][t + 1] + holdA[r][t] > holdA[r + 1][t + 1])
            {
                holdA[r + 1][t + 1] = arr[r + 1][t + 1] + holdA[r][t];
            }
        }
        if (arr[r + 1][colNum - 2] + holdA[r][colNum - 1] > holdA[r + 1][colNum - 2])
        {
            holdA[r + 1][colNum - 2] = arr[r + 1][colNum - 2] + holdA[r][colNum - 1];
        }
        if (arr[r + 1][colNum - 1] + holdA[r][colNum - 1] > holdA[r + 1][colNum - 1])
        {
            holdA[r + 1][colNum - 1] = arr[r + 1][colNum - 1] + holdA[r][colNum - 1];
        }
    }
    int greatest = 0;
    for (int s = 0; s < colNum; s++)
    {
        if (greatest < holdA[rowNum - 1][s])
        {
            greatest = holdA[rowNum - 1][s];
        }
    }
    cout << greatest;
}