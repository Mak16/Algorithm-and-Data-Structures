#include <iostream>

using namespace std;

struct MinMax
{
    int min;
    int max;
};
MinMax findMinMax(int arr[] , int l ,int r)
{
    MinMax mm;
    if(l==r)
    {
        mm.max=arr[l];
        mm.min=arr[l];
        return mm;
    }
    else if( r-l==1 )
    {
        if(arr[l]>arr[r])
        {
            mm.max=arr[l];
            mm.min=arr[r];
        }
        else
        {
            mm.max=arr[r];
            mm.min=arr[l];
        }
        return mm;
    }
    else
    {
        int mid = (l+r)/2;
        MinMax mm1 = findMinMax(arr,l,mid);
        MinMax mm2 = findMinMax(arr,mid+1,r);
        if(mm1.max > mm2.max)
            mm.max = mm1.max;
        else
            mm.max = mm2.max;

        if(mm1.min < mm2.min)
            mm.min = mm1.min;
        else
            mm.min = mm2.min;

        return mm;
    }
}
int main()
{
    int arr[]={23,4,56,7,12,3,66,1};
    int n = sizeof(arr)/sizeof(int);
    MinMax mm = findMinMax(arr,0,n-1);
    cout<<"Min : "<<mm.min<<" | Max : "<<mm.max<<endl;
    return 0;
}
