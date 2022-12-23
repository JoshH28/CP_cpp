//Super idol 的笑容都没你的甜
//八月正午的阳光都没你耀眼
//热爱105度的你
//滴滴清纯的蒸馏水
//你不知道你有多可爱
//跌倒后会傻笑着再站起来
//你从来都不轻言失败
//对梦想的执着一直不曾更改
//很安心
//当你对我说
//不怕有我在
//放着让我来
//勇敢追自己的梦想
//那坚定的模样
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define pq priority_queue
#define gcd(x,y) __gcd( x, y)
#define ALL(x) x.begin(),x.end()
#define pll pair<long long,long long>
#define debug(x) cerr<<#x<<':'<<x<<endl
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INTMAX 2147483647
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int main()
{
    ll total, limit;
    cin >> total >> limit;
    ll cost[total];
    ll gain[total];
    for (ll q = 0; q < total; q++)
    {
        cin >> cost[q];
    }
    for (ll w = 0; w < total; w++)
    {
        cin >> gain[w];
    }
    vector<pair<ll, ll>> arr(total);
    for (ll q = 0; q < total; q++)
    {
        arr[q] = (make_pair(cost[q], gain[q]));
    }
    sort(arr.begin(), arr.end());
    priority_queue<ll> pq;
    ll count = 0;
    ll sum = 0;
    ll index = 0;
    while (count < limit)
    {
        cout << "yes";
        while (index < total && arr[index].first <= sum)
        {
            pq.push(arr[index].second);
            index += 1;
        }
        if (pq.size() == 0)
        {
            break;
        }
        sum += pq.top();
        pq.pop();
        cout << sum << endl;
        count += 1;
    }
    cout << sum;
}