/*
 *  01 bag problem
 *  EE
 *  YWL
 */
#include<iostream>
using namespace std;

int n,W;
int w[10],v[10];
int dp[11][11];

int solve();

int solve()
{

    for(int i=0;i<=n;i++)
        for(int j=0;j<=W;j++)
        {
            if(j<w[i])
                dp[i+1][j]=dp[i][j];
            else
                dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
        }

    cout<<dp[n][W]<<endl;

    return 0;
}

int main()
{
    cout<<"n:";
    cin>>n;
    cout<<endl<<"W:";
    cin>>W;
    cout<<max(n,W)<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }

    solve();
    return 0;
}








