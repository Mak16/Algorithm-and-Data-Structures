#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void insertionsort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i;
        while( j>0 && arr[j-1]>arr[j] )
        {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
int main()
{
    int arr[]={5,6,4,7,2,1,8,9,0};
    int n = sizeof(arr)/sizeof(int);
    insertionsort(arr,n);
    cout<<"Sorted array : \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" , ";
    cout<<endl;

    return 0;
}
