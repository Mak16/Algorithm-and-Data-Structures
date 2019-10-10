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

void partitionArray(int arr[][10],int n,int k,int op[],int l,int r)
{
    if(l==r)
    {
        for(int i=0;i<n;i++)
            op[l*n+i] = arr[l][i];
        return ;
    }
    else
    {
        int mid = (l+r)/2;
        partitionArray(arr,n,k,op,l,mid);
        partitionArray(arr,n,k,op,mid+1,r);
        merge(op,l*n,(mid+1)*n-1,(mid+1)*n,(r+1)*n-1);
    }
}
int main()
{
    int arr[10][10]={
    {23,55,66,97,98},
    {32,54,66,88,99},
    {23,34,45,56,76}
    };
    int n=5,k=3;
    int *op = new int[n*k];
    partitionArray(arr,n,k,op,0,k-1);
    cout<<"Sorted array : "<<endl;
    for(int i=0;i<n*k;i++)
        cout<<op[i]<<" , ";
    cout<<endl;
    return 0;
}
