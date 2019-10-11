#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partitionArray(int arr[],int l,int r)
{
    int pivot = l,i=l,j=l+1;
    while(j<=r)
    {
        if( arr[j]>=arr[pivot] )
        {
            i++;
            swap(arr[j],arr[i]);
        }
        j++;
    }
    swap(arr[pivot],arr[i]);
    return i;

}
int quicksort(int arr[],int l,int r ,int k )
{
    if(r==l)
        return arr[r];
    else
    {
        int m = partitionArray(arr,l,r);
        if( m==k )
            return arr[m];
        if( k<m )
            return quicksort(arr,l,m-1,k);
        if( k>m )
            return quicksort(arr,m+1,r,k);
    }
}
int main()
{
    int arr[]={53,5,32,2,1,34,4};
    int n = sizeof(arr)/sizeof(int);
    int k = 8;
    if(k <= n && k>=1)
    {
        int e = quicksort(arr,0,n-1,k-1);
        cout<<"kth largest element is  : "<<e<<endl;
    }
    else{
        cout<<"invalid value of k "<<endl;
    }
    cout<<endl;
    return 0;
}
