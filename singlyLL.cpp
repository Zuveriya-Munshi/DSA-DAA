#include<iostream>
using namespace std;
class Node
{
    public:
    int info;
    Node* next;

    Node()
    {
        info=0;
        next=NULL;
    }
    Node(int data)
    {
        info=data;
        next=NULL;
    }

    void append(Node* newNode)
    {
        Node* tp=this;
        while(tp->next!=NULL)
        {
            tp=tp->next;
        }
        tp->next=newNode;
    }
    void ins(int d,Node* &newNode)
    {
        Node* tp = this;
        while(tp!=NULL)
        {
            if(d==tp->info)
            {
                newNode->next=tp->next;
                tp->next=newNode;
                break;
            }
            tp=tp->next;

        }

    }


};
void traverse(Node* &head)
    {
        Node* tp=head;
        while(tp!=NULL)
        {
            cout<<tp->info<<" ";
            tp=tp->next;
        }
        cout<<endl;
    }



int main()
{

    Node* first= new Node(5);
    Node* third=new Node(54);
    Node* head=first;
    Node* second = new Node(10);
    first->append(second);
    Node* fourth= new Node(55);
    first->append(fourth);
    traverse(head);
    cout<<"\nInserting at specific data : ";
    first->ins(10,third);
    traverse(head);
    return 0;
}
