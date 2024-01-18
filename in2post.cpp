#include<iostream>
#include<stack>
#include<process.h>
#define max 5

using namespace std;
template <class Stype>
class stack1
{
    int top;
    Stype arr[max];
public:
    stack()
    {
        top=-1;
    }

    bool isFull();

    bool isEmpty();

    void push(Stype val);

    Stype pop();
    Stype top();

    void display();
    int prec(char ch)
    {
        if(ch=='^')
            return 3;
        else if(ch=='/' || ch=='*')
            return 2;
        else if(ch=='-' || ch=='+')
            return 1;
        else
            return -1;

    }
    int isOp(char ch)
    {
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
            return 1;
        else
            return -1;
    }
    string inToPost(string exp)
    {
        stack1<char> s;
        string res;

        for(int i=exp.size()-1;i>=0;i--)
        {
            if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z')
                res+=exp[i];
            else if(exp[i]==')')
                s.push(exp[i]);
            else if(exp[i]=='(')
            {
                while(s.stackTop()!=')')
                {
                    res=s.stackTop()+res;
                    s.pop();
                }
                s.pop();
            }
            else
            {
                while(!s.isEmpty() && prec(s.stackTop())>prec(exp[i]))
                {
                    res=s.stackTop()+res;
                    s.pop();
                }
                s.push(exp[i]);
            }


        }
        while(!s.isEmpty())
        {
            res=s.stackTop()+res;
            s.pop();
        }
        return res;
    }


};
    template <class Stype>
    bool stack1<Stype>::isFull()
    {
       if(top==max-1)
       {
           cout<<"Stack is FULL\n";
           return true;
       }
       else
       {
           return false;
       }
    }

    template <class Stype>
    bool stack1<Stype>::isEmpty()
    {
        if(top==-1)
        {
            cout<<"Stack is Empty\n";
            return true;
        }
        else
        {
            return false;
        }

    }

    template<class Stype>
    void stack1<Stype>::push(Stype val)
    {
        if(isFull())
        {
            cout<<"Stack Overflow \n";
            exit(0);
        }
        else
        {
            top++;
            arr[top]=val;
        }
    }

    template <class Stype>
    Stype stack1<Stype>::pop()
    {
        Stype temp;
        if(isEmpty())
        {
            cout<<"Stack Underflow ";
        }
        else
        {
            Stype temp = arr[top];
             cout<<"\nPopped value is : "<<temp;
            top--;
        }
        return temp;
    }

    template<class Stype>
    void stack1<Stype>::display()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty ";
        }
        else
        {
            cout<<"STACK Elements : ";
            for(int i=top;i>=0;i--)
            {
                cout<<arr[i]<<"\t";
            }
        }
    }

    template<class Stype>
    Stype stack1<Stype>::stackTop()
    {

            return arr[top];


    }
int main()
{

    stack1 <char>e;
    string s;
    cout<<"Enter string : ";
    cin>>s;
    string post=e.inToPost(s);
    cout<<post;


    return 0;
}
