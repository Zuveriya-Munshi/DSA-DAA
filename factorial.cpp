#include<iostream>
#include<conio.h>
using namespace std;
static int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n>1)
    {
        return(n*fact(n-1));
    }
}
int main()
{
    static int n;
    int f;
    cout<<"\nEnter value of n : ";
    cin>>n;
    f=fact(n);
    cout<<"\nFactorial of "<<n<<" is : "<<f;

    return 0;
}
