#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

ll max(ll a, ll b, ll c)
{
    ll temp = max(a, b);
    return max(temp, c);
}

ll max_gold(vector<vector<ll>> mine, ll n, ll m, ll i, ll j, vector<vector<ll>> &dp)
{

    if (i < 0 || i > n - 1 || j < 0 || j > m - 1)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    ll temp1 = mine[i][j] + max_gold(mine, n, m, i - 1, j + 1, dp);
    ll temp2 = mine[i][j] + max_gold(mine, n, m, i, j + 1, dp);
    ll temp3 = mine[i][j] + max_gold(mine, n, m, i + 1, j + 1, dp);

    return dp[i][j] = max(temp1, temp2, temp3);
}

int main()
{
    ll n, m;
    srand(time(0));
    n = (rand() %(10 - 1 + 1)) +1;
    m = (rand() %(10 - 1 + 1)) +1;
    
    vector<vector<ll>> mine(n, vector<ll>(m, 0));
    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    ll pos_x;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            mine[i][j] = (rand() %(100 - 1 + 1)) +1;
        }
    }

    cout<<"The gold mine is: "<<endl;
    cout<<"----------------------------"<<endl;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout<<mine[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------"<<endl;

    ll ans = 0, maximum = INT_MIN;
    // cin>>pos_x;   // present at row number pos_x

    for (ll i = 0; i < n; i++)
    {
        pos_x = i;
        ans = max_gold(mine, n, m, pos_x, 0, dp);
        maximum = max(ans, maximum);
    }

    cout <<"The maximum amount of gold that can be mined in this gold mine is : "<< maximum << endl;
}