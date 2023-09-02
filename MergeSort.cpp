#include<bits/stdc++.h>
using namespace std;

void merg(int a[],int l, int m,int h)
{
    int b[h+1];

    int i=l;
    int j=m+1;
    int k=l;

    while(i<=m && j<=h)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }

    if(i>m)
    {
        while(j<=h)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }

    else
    {
         while(i<=m)
         {


            b[k]=a[i];
            k++;
            i++;
         }

    }

    for(int q=l;q<=h;q++)
    {
        a[q]=b[q];
    }
}

void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
        int m = (l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merg(a,l,m,h);
    }
}

int main()
{
    int a[]={7,0,1,5,-1,5,1,9,3,6,3};
    int l = sizeof(a)/sizeof(int);

    mergesort(a,0,l-1);

    for(int i=0;i< l;i++)
    {
        cout<<a[i]<<" ";
    }
}
