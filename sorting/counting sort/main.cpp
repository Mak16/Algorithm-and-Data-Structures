#include <iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<cstring>
using namespace std;

void countingsort(int arr[],int n)
{
    int min = *min_element(arr,arr+n),max = *max_element(arr,arr+n) ;
    int r = 1+max-min;
    vector<int>count(r,0);  //array stores the count of element
    vector<int>op(n);   // arrays stroes the o/p
    //count the element
    for(int i=0;i<n;i++)
        count[arr[i]-min]++;
    //add the element
    for(int i=1;i<r;i++)
        count[i] = count[i]+count[i-1];
    //insert into op array
    for(int i=0;i<n;i++)
    {
        op[count[arr[i]-min]-1]=arr[i];
        count[arr[i]-min]--;
    }
    //copy the op array to arr
    for(int i=0;i<n;i++)
        arr[i]=op[i];
}
int main()
{
    int arr[]={1,2,-1,3,5,-3,2,6,4,5,8};
    int n = sizeof(arr)/sizeof(int);
    countingsort(arr,n);
    cout<<"After sorting : "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" , ";
    return 0;
}
