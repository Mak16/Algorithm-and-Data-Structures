#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void selectionsort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if( arr[j] < arr[min] )
                min=j;
        }
        swap(arr[i],arr[min]);
    }
}
int main()
{
    int arr[]={5,6,4,7,2,1,8};
    int n = sizeof(arr)/sizeof(int);
    selectionsort(arr,n);
    cout<<"Sorted array : \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" , ";
    cout<<endl;

    return 0;
}
