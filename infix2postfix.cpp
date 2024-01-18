#include<iostream>
#include<string.h>
#define max 30
using namespace std;
template<class T>
class stack
{
    T arr[max];
    int top;
public:
    stack()
    {
        top=-1;
    }
    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(top==max-1)
            return true;
        else
            return false;
    }
    T& Top()
    {
       if(isEmpty())
        cout<<"Stack is Empty";
       return arr[top];
    }
    void push(T val)
    {
        if(isFull())
            cout<<"\nStack Overflow";
        else
        {
            //cout<<endl<<val<<" is pushed";
           top++;
           arr[top]=val;
        }
    }
    T pop()
    {
        T t;
        if(isEmpty())
            cout<<"\nStack Underflow";
        else
        {
             t=arr[top];
            // cout<<endl<<t<<" is popped";
             top--;
        }
        return t;
    }
    int prec(T ch)
    {
        if(ch=='^')
            return 5;
        else if(ch=='/' || ch=='*')
            return 4;
        else if(ch=='-' || ch=='+')
            return 3;
        else
            return 2;
    }
     void In2Post(T exp[])
    {
        int len;
        static int index=0,pos=0;
        char s,t;
        T post[30];
        len=strlen(exp);
        push('#');
        while(index<len)
        {
            s=exp[index];
            switch(s)
            {
            case '(':
                push(s);
                break;
            case ')':
                t=pop();
                while(t!='(')
                {
                    post[pos]=t;
                    pos++;
                    t=pop();
                }
                break;
            case '^':
            case '+':
            case '-':
            case '*':
            case '/':

                        while(prec(arr[top])>=prec(s))
                        {
                            t=pop();
                            post[pos]=t;
                            pos++;
                        }
            push(s);
            break;
            default:
                    post[pos++]=s;
                    break;

            }
            index++;
        }
        while(top>0)
        {
            t=pop();
            post[pos++]=t;

        }
        post[pos++]='\0';
        cout<<"Postfix : ";
        puts(post);
        return;
    }



};
int main()
{
    stack<char>s1;
    char in[30];
    cout<<"Enter infix : ";
    gets(in);

    s1.In2Post(in);


    return 0;
}
