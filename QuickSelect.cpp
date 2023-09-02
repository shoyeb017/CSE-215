
#include<bits/stdc++.h>
using namespace std;

void print(int a[],int n)
{
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int partition_last_pivot(int a[],int l,int h)
{
    int p = a[h];
    int i=l;
    int j=h;

    while(i<j)
    {
        while(a[i] > p) i++;
        while(a[j] <= p) j--;

        if(i<j)
        {
            swap (a[i],a[j]);
            i++;j--;
        }
    }

    swap(a[i],a[h]);
    return i;
}

int quick_select(int a[],int l,int h,int k)
{

        int p = partition_last_pivot(a,l,h);
        if(p==k) return a[p];
        else if(p<k) return quick_select(a,p+1,h,k);
        else if(p>k) return quick_select(a,l,p-1,k);

}


int main()
{
    int a[]={3,2,1,5,6,4};
    int n=sizeof(a)/sizeof(a[0]);
    int k=2;
    print(a,n);
    cout<<quick_select(a,0,n-1,k-1)<<endl;

    int b[]={3,2,3,1,2,4,5,5,6};
    n=sizeof(b)/sizeof(b[0]);
    k=4;
    print(b,n);
    cout<<quick_select(b,0,n-1,k-1)<<endl;;

}
