#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long unsigned int num = 0;
    cin >> num;
    long long int hold1 = 0;
    long long int hold2 = 0;
    long long int sum1 = 0;
    long long int sum2 = 0;
    int xA[num];
    int yA[num];
    for (int q = 0; q < num; q++)
    {
        cin >> hold1;
        cin >> hold2;
        xA[q] = hold1;
        yA[q] = hold2;
    }
    sort(xA, xA + num);
    sort(yA, yA + num);
    int temp1;
    int temp2;
    if (num % 2 == 1)
    {
        cout << xA[num / 2] << " " << yA[num / 2];
    }
    else
    {
        temp1 = (xA[(num / 2) - 1] + xA[(num / 2)]) / 2;
        temp2 = (yA[(num / 2) - 1] + yA[(num / 2)]) / 2;
        cout << temp1 << " " << temp2;
    }
}