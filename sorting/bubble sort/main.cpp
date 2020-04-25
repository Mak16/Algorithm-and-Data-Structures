#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool check=true;
        for(int j=0;j<n-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                check=false;
            }
        }
        if(check)
            return;
    }
}
int main()
{
    int arr[]={5,6,4,7,2,1,8};
    int n = sizeof(arr)/sizeof(int);
    bubblesort(arr,n);
    cout<<"Sorted array : \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" , ";
    cout<<endl;

    return 0;
}
