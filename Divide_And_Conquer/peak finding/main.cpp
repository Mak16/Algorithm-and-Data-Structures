#include <iostream>

using namespace std;

int main()
{
    int arr[]={1,3,20,4,1,0};
    int n = sizeof(arr)/sizeof(int);
    int l=0,r=n-1;
    int mid=0;
    while(l<=r)
    {
        mid =(l+r)/2;
        if((mid==0 && arr[mid]>=arr[mid+1]) ||
           (mid==n-1 && arr[mid]>=arr[mid-1]) ||
           ( mid>0 && mid<n-1 && arr[mid]>=arr[mid-1] && arr[mid]>= arr[mid+1])  )
                break;
        if(mid>0 && arr[mid-1]>arr[mid])
            r=mid-1;
        if(mid<n-1 && arr[mid+1]>arr[mid])
            l = mid+1;
    }
    cout<<"peak element index : "<<mid<<endl;
    return 0;
}
