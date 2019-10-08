#include <iostream>

using namespace std;
// Using Recursion
int BSR(int arr[],int l,int r,int key)
{
    if(l>r)
        return -1;
    else
    {
        int mid = (l+r)/2;
        if( arr[mid]==key )
            return mid;
        else if( key < arr[mid] )
            return BSR(arr,l,mid-1,key);
        else
            return BSR(arr,mid+1,r,key);
    }
}
// Without Using Recursion
int BSWr(int arr[],int l,int r,int key)
{
    while(l<=r)
    {
        int mid = (l+r)/2;
        if( key == arr[mid] )
            return mid;
        else if( key < arr[mid] )
            r = mid-1;
        else
            l = mid+1;

    }
    return -1;
}
int main()
{
    int arr[] = {23,34,45,56,67,76,78,89};
    int n = sizeof(arr)/sizeof(int);
    int key = 90;
    int v = BSWr(arr,0,n-1,key);
    if(v==-1)
        cout<<"Element not found "<<v<<endl;
    else
        cout<<"Element found at "<<v+1<<endl;

    return 0;
}
