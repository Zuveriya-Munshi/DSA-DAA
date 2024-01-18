#include<iostream>
#define max 5
using namespace std;template <class T>
class bracket
{
    T arr[max];
    int top;
public:
    bracket()
    {
        top=-1;
    }

    bool isFull()
    {
        if(top==max-1)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {

        if(top==-1)
            return true;
        else
            return false;
    }
    void push(T data)
    {
        if(isFull())
        {
             cout<<"Stack overflow";
             return;
        }
           //
         top++;
        arr[top]=data;
    }

    T pop()
    {
        if(isEmpty())
        {
            cout<<"\nStack Underflow\n";
            return -1;
        }
            return arr[top--];

    }
    T peep()
    {
        if(top==-1)
        {
                cout<<"\nStack Empty\n";
                return -2;
        }
        else
            return(arr[top]);
    }
    void Chkorder(T ch,string & od)
    {
        int od1=0,od2=0,od3=0;
        if(ch=='(' && od1==0)
        {
                od+='(';
                od1++;
        }
        else if(ch=='{' && od2==0)
        {
                od+='{';
                od2++;
        }
        else if(ch=='[' && od3==0)
        {
                od+='[';
                od3++;
        }
    }

     bool Chknumber(string infix)
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
        {
            return true;
        }
    else
    {
         return false;
    }

}
    bool pairChk(string exp)
    {
        char ch,temp;
        string order;
        int c1=0,c2=0,c3=0;
        for(int i=0;i<exp.length();i++)
        {
            ch=exp[i];
            if(ch==' ')
                continue;
            else if(ch=='(' || ch=='{' || ch=='[')
            {
                push(ch);
                Chkorder(ch,order);
                continue;
            }
            else if(ch==')' || ch=='}' || ch==']')
            {
                if(isEmpty())
                {
                    cout<<"\nNo Opening bracket.. Incorrect Expression\n";

                    return false;
                }
                switch(ch)
                {
                case ')':
                    temp = peep();
                    temp=pop();
                    if(temp=='{' || temp=='[')
                        return false;
                    else
                        c1++;
                    break;
                case '}':
                    temp=peep();
                    temp=pop();
                    if(temp=='(' || temp=='[')
                        return false;
                    else
                        c2++;
                    break;
                case ']':
                    temp = peep();
                    temp=pop();
                    if(temp=='(' || temp=='{')
                        return false;
                    else
                        c3++;
                    break;
                default:
                    continue;
                }
            }
        }

        cout<<"\n No. of () : "<<c1<<endl;
        cout<<"\n No. of {} : "<<c2<<endl;
        cout<<"\n No. of [] : "<<c3<<endl;
        cout<<"\n order : "<<order<<endl;
    }


};

int main()
{
    string exp;
    bracket<char> ob;
    cout<<"\nEnter Expression : ";
    cin>>exp;
    if(ob.Chknumber(exp))
        cout<<"\nCorrect Number of brackets";
    else
        cout<<"\nIncorrect number of brackets";
    if(ob.pairChk(exp))
        cout<<"\nCorrect order of brackets";
    else
        cout<<"\nIncorrect order of brackets";
    return 0;
}
