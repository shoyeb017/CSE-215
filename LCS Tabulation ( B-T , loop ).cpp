#include <bits/stdc++.h>
using namespace std;


void lcs(string x, string y, int m, int n)
{

	int dp[m + 1][n + 1];

	for (int i = 0; i <= m; i++)
    {
		for (int j = 0; j <= n; j++)
		{

			if (i == 0 || j == 0)
				dp[i][j] = 0;

			else if (x[i - 1] == y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;

			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	//return dp[m][n]

	//printing sequence

    int p = dp[m][n];     // p = result char array r index

    char r[p + 1];        // r = result array
    r[p] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
          r[p - 1] = x[i - 1];
          i--;
          j--;
          p--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])  i--;
        else  j--;
    }

    cout<<"lcs length: "<<dp[m][n]<<endl;
    cout<<"lcs: "<<r<<endl;
}




int main()
{
    string s1,s2;

    cin>>s1>>s2;

	int m = s1.size();
	int n = s2.size();

    lcs(s1, s2, m, n);
}
