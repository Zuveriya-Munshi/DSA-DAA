#include<iostream>
#include<process.h>
#define max 5
using namespace std;
class stack
{
    int top,arr[max];
public:
    stack()
    {
        top=-1;


    }
    bool isFull()
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
    bool isEmpty()
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
    void push(int val)
    {
        if(isFull())
        {
            cout<<"Stack Overflow \n";
            //exit(0);
        }
        else
        {
            top++;
            arr[top]=val;
        }
    }
    int pop()
    {
        int temp;
        if(isEmpty())
        {
            cout<<"Stack Underflow ";
        }
        else
        {
            int temp = arr[top];
             cout<<"\nPopped value is : "<<temp;
            top--;
        }
        return temp;
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty ";
        }
        cout<<"STACK Elements : ";
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<"\t";
        }
    }
};
int main()
{
    stack s;
    int ch,val,temp;
    cout<<"\n 1) PUSH \n 2) POP \n 3) Display \n 4) isFull \n 5) isEmpty \n 6) QUIT \n";
    do
    {
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
       case 1:
           cout<<"Enter Value : ";
           cin>>val;
           s.push(val);
           break;
       case 2:
            s.pop();

            break;
       case 3:
        s.display();
        break;
       case 4:
           s.isFull();
           break;
       case 5:
        s.isEmpty();
        break;
       case 6:
        break;
       default :
        cout<<"Invalid choice";


        }
    }while(ch<7);

    return 0;
}
