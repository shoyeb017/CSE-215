// A Naive recursive implementation of LCS problem

#include <bits/stdc++.h>
using namespace std;

// Returns length of LCS for X[0..m-1], Y[0..n-1]
int lcs(string X, string Y, int i, int j)
{
	if (i == 0 || j==0)  //string ends
		return 0;

	if (X[i-1] == Y[j-1])
		return 1 + lcs(X, Y, i - 1, j - 1);

	else
		return  max(lcs(X, Y, i, j - 1), lcs(X, Y, i - 1, j));
}


/*
int lcs(string X, string Y, int i, int j)
{
	if (i == '\0' || j=='\0')  //string
		return 0;

	if (X[i] == Y[i])
		return 1 + lcs(X, Y, i + 1, j + 1);

	else
		return  max(lcs(X, Y, i, j + 1), lcs(X, Y, i + 1, j));
}
*/


int main()
{
    string s1,s2;

    cin>>s1>>s2;

	int m = s1.size();
	int n = s2.size();

	cout << "Length of LCS is " << lcs(s1, s2, m, n);

}



