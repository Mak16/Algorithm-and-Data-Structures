#include <iostream>

using namespace std;

int merge(int arr[],int l,int m,int r)
{
    int i=l,j=m+1,c=0,k=0,b[100];
    while(i<= m && j<=r)
    {
        if(arr[i]>arr[j])
        {
            b[k++]=arr[j];
            c = c+m-i+1;
            j++;
        }
        else
        {
            b[k++]=arr[i++];
        }
    }
    while(i<=m)
        b[k++]=arr[i++];
    while(j<=r)
        b[k++]=arr[j++];
    for(i=0;i<k;i++)
        arr[l++]=b[i];

    return c;
}

int countingInversions(int arr[],int l,int r)
{
    if(l==r)
        return 0;
    else
    {
        int mid = (l+r)/2;
        return (countingInversions(arr,l,mid)+countingInversions(arr,mid+1,r)+merge(arr,l,mid,r));
    }
}
int main()
{
    int arr[]={50,20,10,5,30,40,3,4};
    int n = sizeof(arr)/sizeof(int);
    int inv = countingInversions(arr,0,n-1);
    cout<<"no of inversions  : "<<inv<<endl;
    return 0;
}
