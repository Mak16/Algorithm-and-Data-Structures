#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
//minheapify the almost complete binary tree from position i
void minheapify(int arr[],int n,int i)
{
    int left_child = 2*i+1;
    int right_child = 2*i+2;
    int smallest_child = i;
    if(left_child < n && arr[left_child] < arr[smallest_child] )
        smallest_child = left_child;
    if(right_child < n && arr[right_child] < arr[smallest_child])
        smallest_child = right_child;
    if(smallest_child != i)
    {
        swap(arr[i],arr[smallest_child]);
        minheapify(arr,n,smallest_child);
    }
}

//insert element into minheap
void insetIntoMinheap(int arr[],int& n,int key)
{
    arr[n] = key;
    n++;
    int parent = (n-2)/2,child=n-1;
    while(parent >= 0 && arr[parent] > arr[child])
    {
        swap(arr[parent],arr[child]);
        child=parent;
        parent = (parent-1)/2;
    }
}

//delete element form minheap
void deleteFromMinheap(int arr[],int &n)
{
    swap(arr[0],arr[n-1]);
    n--;
    minheapify(arr,n,0);
}

//create minheap from the given array
void buildHeap(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        minheapify(arr,n,i);
    }
}

//apply heapsort algorithm on minheap
void heapsort(int arr[],int n)
{
    while(n!=0)
        deleteFromMinheap(arr,n);
}

int main()
{
    int arr[100]={23,2,1,34,2,4,32,44};
    //int n = sizeof(arr)/sizeof(int);
    int n = 8;

    buildHeap(arr,n);
    cout<<"minheap : ";
    for(int i=0;i<n;i++)
        cout<<arr[i] <<" , ";

    cout<<"\ninsert 5 : ";
    insetIntoMinheap(arr,n,5);
    for(int i=0;i<n;i++)
        cout<<arr[i] <<" , ";

    cout<<"\ninsert 1 : ";
    insetIntoMinheap(arr,n,1);
    for(int i=0;i<n;i++)
        cout<<arr[i] <<" , ";

    cout<<"\ninsert 9 : ";
    insetIntoMinheap(arr,n,9);
    for(int i=0;i<n;i++)
        cout<<arr[i] <<" , ";

    cout<<"\ndelete : ";
    deleteFromMinheap(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i] <<" , ";

    cout<<"\nheapsort  : ";
    heapsort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i] <<" , ";
    cout<<endl;

    return 0;
}
