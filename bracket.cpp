#include<iostream>
using namespace std;
bool bracket(string infix)
{
    int b1=0,b2=0,b3=0;
    for(int i=0;i<infix.length();i++)
    {
        if(infix[i]=='(')
           b1++;
        else if(infix[i]==')')
            b1--;
        else if(infix[i]=='{')
            b2++;
        else if(infix[i]=='}')
            b2--;
        else if(infix[i]=='[')
            b3++;
        else if(infix[i]==']')
            b3--;
        if(b1<0 || b2<0 || b3<0)
            return false;
        else
            continue;
    }
    if(b1==0 && b2==0 && b3==0)
        return true;
    else
        return false;

}
int main()
{
    string exp;
    cout<<"\nEnter Expression : ";
    cin>>exp;
    if(bracket(exp))
        cout<<"\nBalanced\n";
    else
        cout<<"\nUnbalanced\n";
    return 0;
}
