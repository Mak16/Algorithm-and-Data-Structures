#include <iostream>

using namespace std;

void merge(int arr[],int l1,int r1,int l2,int r2)
{
    int i=l1,j=l2,k=0;
    int b[100];
    while(i<=r1 && j<=r2)
    {
        if(arr[i]<arr[j])
            b[k++]=arr[i++];
        else
            b[k++]=arr[j++];
    }
    while(i<=r1)
        b[k++]=arr[i++];
    while(j<=r2)
        b[k++]=arr[j++];

    for(int m=0;m<k;m++)
        arr[l1++]=b[m];
}

void mergesort(int arr[],int n,int l,int r)
{
    if(l==r)
        return;
    else
    {
        int mid=(l+r)/2;
        mergesort(arr,n,l,mid);
        mergesort(arr,n,mid+1,r);
        merge(arr,l,mid,mid+1,r);
    }
}
int main()
{
    int arr[]={23,45,56,34,2,23,12,4,6};
    int n = sizeof(arr)/sizeof(int);
    cout<<"Unsorted array : "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" , ";

    mergesort(arr,n,0,n-1);
    cout<<"\n\nSorted array : "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" , ";
    cout<<endl;
    return 0;
}
