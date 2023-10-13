#include <bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int i, int j,vector<vector<int> >& dp)
{
	if (i == 0 || j==0)
		return 0;

    if(dp[i][j]!=-1) return dp[i][j];

	if (X[i-1] == Y[j-1])
		return dp[i][j] = 1 + lcs(X, Y, i - 1, j - 1,dp);

	else
		return  dp[i][j] = max(lcs(X, Y, i, j - 1,dp), lcs(X, Y, i - 1, j,dp));
}


int main()
{
    string s1,s2;

    cin>>s1>>s2;

	int m = s1.size();
	int n = s2.size();

	vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));

	cout << "Length of LCS is " << lcs(s1, s2, m, n,dp);

}




