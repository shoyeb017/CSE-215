
#include<bits/stdc++.h>
using namespace std;

void print(int a[],int n)
{
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}


//*************first pivot*************//
int partition_first_pivot(int a[],int l,int h)
{
    int p = a[l];
    int i=l;
    int j=h;

    while(i<j)
    {
        while(a[i] <= p) i++;
        while(a[j] > p) j--;

        if(i<j)
        {
            swap (a[i],a[j]);
            i++;j--;
        }
    }

    swap(a[j],a[l]);
    return j;
}
void quicksort_first_pivot(int a[],int l,int h)
{
    if(l<h)
    {
        int p = partition_first_pivot(a,l,h);
        quicksort_first_pivot(a,l,p-1);
        quicksort_first_pivot(a,p+1,h);
    }
}

//**************first**************//



//*************last pivot*************//

int partition_last_pivot(int a[],int l,int h)
{
    int p = a[h];
    int i=l;
    int j=h;

    while(i<j)
    {
        while(a[i] < p) i++;
        while(a[j] >= p) j--;

        if(i<j)
        {
            swap (a[i],a[j]);
            i++;j--;
        }
    }

    swap(a[i],a[h]);
    return i;
}
void quicksort_last_pivot(int a[],int l,int h)
{
    if(l<h)
    {
        int p = partition_last_pivot(a,l,h);
        quicksort_last_pivot(a,l,p-1);
        quicksort_last_pivot(a,p+1,h);
    }
}

//***************last*************//




//*************mid pivot*************//
void quicksort_mid_pivot(int a[],int l,int h)
{
    int p=a[(l+h)/2];
    int i=l;
    int j=h;

    //****partition****//
    while(i<=j)
    {
        while(a[i] < p) i++;
        while(a[j] > p) j--;

        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }

    //****recursion****//
    if(l<j) quicksort_mid_pivot(a,l,j);
    if(i<h) quicksort_mid_pivot(a,i,h);
}



int main()
{
    int a[]={5,9,1,0,2,4,5,6,3,1};
    int n=10;

    print(a,n);

    //quicksort_first_pivot(a,0,n-1);
    //quicksort_last_pivot(a,0,n-1);
    quicksort_mid_pivot(a,0,n-1);

    print(a,n);

}
