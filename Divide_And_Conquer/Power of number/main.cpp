#include <iostream>

using namespace std;

int findPower(int n,int p)
{
    if(p==1)
        return n;
    else
    {
        int m  = findPower(n,p/2);
        if(p%2 == 0 )
            return m*m;
        else
            return m*m*n;
    }
}
int main()
{
    int num=51,pow=5;
    cout<<findPower(num,pow);
    return 0;
}
