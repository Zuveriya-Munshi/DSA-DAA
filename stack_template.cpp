#include<iostream>
#include<process.h>
#define max 5

using namespace std;
template <class Stype>
class stack
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

    void display();

};
    template <class Stype>
    bool stack<Stype>::isFull()
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
    bool stack<Stype>::isEmpty()
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
    void stack<Stype>::push(Stype val)
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

    template <class Stype>
    Stype stack<Stype>::pop()
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
    void stack<Stype>::display()
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
int main()
{
    stack <string>s;
    string val,temp;
    int ch;

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
           exit(0);
        break;
       default :
        cout<<"Invalid choice";


        }
    }while(ch!=0);

    return 0;
}
