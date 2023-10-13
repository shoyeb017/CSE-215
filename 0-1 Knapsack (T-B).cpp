 //DP top-down approach
#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int c,n;
int p[2005],w[2005];
int knapsack(int i,int j)
{
    if(i<0 || j<=0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int v1=knapsack(i-1,j),v2=-1;

    if(j>=w[i]) v2=p[i]+knapsack(i-1,j-w[i]);
    dp[i][j]=max(v1,v2);
    return dp[i][j];

}
int main()
{
    cin>>c>>n;
    for(int i=0; i<n; i++) cin>>w[i]>>p[i];
    for(int i=0; i<2005; i++)
    {
        for(int j=0; j<2005; j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(n-1,c)<<endl;
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<c+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
