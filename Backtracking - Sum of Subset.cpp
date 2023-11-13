// Sum of Subset

#include<bits/stdc++.h>
using namespace std;

int a[3];
int n,ts;
vector <int> b;

void back_track(int i,int s,vector<int> b)
{
    if(s==0)
    {
        for(int j=0; j<b.size(); j++)
        cout<<b[j]<<" ";
    }

    if(i==n ) return ;

    back_track(i+1 , s , b );
    b.push_back(a[i]);
    back_track(i+1 , s-a[i] , b );

}


int main()
{
    cin>>n>>ts;  // ts - target sum

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    back_track(0,ts,b);
}
