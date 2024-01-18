#include<iostream>
using namespace std;
int fib(int n)
{

     if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    if(n>1)
    {

        return(fib(n-1)+fib(n-2));
    }
}
int main()
{
    int n;
    int f;
    cout<<"\nEnter the number : ";
    cin>>n;
    f=fib(n);
    cout<<"\nFibonacci sequence : "<<f;

    return 0;
}
