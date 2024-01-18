#include<iostream>
using namespace std;
class Node
{


    int data;
    Node *next;
    Node *prev;
    Node *front=NULL;
    Node *rear=NULL;

 public:
    Node()
    {
        data=0;
        next=prev=NULL;
    }
       Node(int data)
       {
           this->data=data;
           next=prev=NULL;
       }
       //Adding an item at the rear end of queue
       void enQueue(Node* &front, Node* &rear,Node* NewNode)
       {
           if(front== NULL && rear==NULL)
           {
               front=NewNode;
               rear=NewNode;
           }
           else
           {
               rear->next = NewNode;
               NewNode->prev = rear;
               rear = NewNode;
           }
       }
       //Adding an items at the front end of the queue
       void enQueueFront(Node* &front, Node* &rear,Node* NewNode)
       {
            if(front== NULL && rear==NULL)
           {
               front=NewNode;
               rear=NewNode;
           }
           else
           {
               NewNode->next=front;
               front->prev=NewNode;
               front=NewNode;
           }
       }

    void traverse(Node* &front, Node* &rear)
    {
        Node* tp=this;

        if(front==NULL && rear==NULL)
        {
            cout<<"\nQueue is Empty\n";
        }
        cout<<"Linked List   : ";
            while(tp!=NULL)
            {

                cout<<tp->data<<" ";
                tp=tp->next;
            }
        cout<<"\n";
    }
    //Deleting an item from the front end of the queue
    Node* deQueue(Node* &front)
    {
        if(this==NULL)
        {
            cout<<"\nUnderflow\n";
            return this;
        }
        Node * tp=this->next;
        if(tp==NULL)
            rear=NULL;
        else{
                 cout<<"Deleted item  : "<<tp->prev->data<<endl;

            tp->prev=NULL;
             front=tp;
        }

        return tp;

    }
    //Deleting an item from the rear end of the queue
    Node * deQueueRear(Node* &rear)
    {
        if(this==NULL)
        {
            cout<<"\nUnderflow\n";
            return this;
        }
        Node * tp=rear->prev;
        if(tp==NULL)
        {
            front=NULL;
        }
        else{

             cout<<"Deleted item  : "<<tp->next->data<<endl;
             tp->next=NULL;
             rear=tp;
        }

         return tp;
    }


};

int main()
{
    Node* front=new Node();
    Node* rear=new Node();
    Node* head= new Node(10);


    front=rear=head;
    cout<<"\nHead Node\n";
    front->traverse(front,rear);
    cout<<"\nAdding An items at the rear end of the QUEUE\n";
    Node* newNode1= new Node(20);
    rear->enQueue(front,rear,newNode1);
    front->traverse(front,rear);
    Node* newNode2= new Node(30);
    rear->enQueue(front,rear,newNode2);
    front->traverse(front,rear);
    cout<<"\nDeleting An items from the front end of the QUEUE\n";
    front=front->deQueue(front);
    front->traverse(front,rear);
    front=front->deQueue(front);
    front->traverse(front,rear);

    cout<<"\nAdding An item at the front end of the QUEUE\n";
    Node* newNode3 = new Node(100);
    front->enQueueFront(front,rear,newNode3);
    front->traverse(front,rear);
    Node* newNode4= new Node(200);
    front->enQueueFront(front,rear,newNode4);
    front->traverse(front,rear);
    cout<<"\nDeleting An items from the rear end of the QUEUE\n";
    rear=rear->deQueueRear(rear);
    front->traverse(front,rear);
    rear=rear->deQueueRear(rear);
    front->traverse(front,rear);

    return 0;

}
