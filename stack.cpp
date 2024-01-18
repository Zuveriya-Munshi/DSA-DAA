#include<iostream>
#include<stdlib.h>
#include<process.h>
#define size 10
using namespace std;
class stack
{
private:
    //int size=10;
   int top;
   int arr[size];
   int val;

public:
    stack()
    {
        top = -1;
    }
    void push(int val)
    {


        if(top==size-1)
        {
            cout<<"Stack is overflow. Can't push an element "<<endl;
            exit(0);

        }
        else
        {

            top++;
            arr[top]=val;

        }

    }
    int pop()
    {
        int temp ;
        if(top==-1)
        {
            cout<<"Stack Underflow. Push some values! \n";
            exit(0);

        }
        else
        {
            temp = arr[top];
             cout<<endl<<temp<<" is popped \n";
                         top--;


        }

        return temp;

    }
    void disp()
    {
       // cout<<"Stack : ";
        if(top==-1)
        {
            cout<<"Stack is Empty \n";
            exit(0);

        }
        else
        {
            cout<<"Elements of the Stack : ";
            for(int i=top;i>=0;i--)
            {
            cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }



    }

};
int main()
{
    stack s;
    int ch,val;
            cout<<"\n1) Push \n2) Pop \n3) Display \n4) Quit \n\n";


    do
    {
        cout<<"Enter your choice : ";
    cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"Enter the value to be pushed : ";
        cin>>val;

            s.push(val);

            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.disp();
            break;
        case 4:
            cout<<"Exit"<<endl;
            break;
        default:
            cout<<"\nInvalid choice\n";
        }
    }while(ch<5);


    return 0;
}
