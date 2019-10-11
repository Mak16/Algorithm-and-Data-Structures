#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
    int temp = a;
    a= b;
    b = temp;
}
int partitionArray(int arr[],int l,int r)
{
    int pivot = l,i=l,j=l+1;
    while(j<=r)
    {
        if( arr[j]<=arr[pivot] )
        {
            i++;
            swap(arr[j],arr[i]);
        }
        j++;
    }
    swap(arr[pivot],arr[i]);
    return i;

}
void quicksort(int arr[],int l,int r )
{
    if(r-l<=0)
        return ;
    else
    {
        int m = partitionArray(arr,l,r);
        quicksort(arr,l,m-1);
        quicksort(arr,m+1,r);
    }
}
int main()
{
    int arr[]={53,5,32,2,1,34,4};
    int n = sizeof(arr)/sizeof(int);
    quicksort(arr,0,n-1);
    cout<<"sorted array : " <<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" , ";

    cout<<endl;
    return 0;
}
