#include <iostream>
using namespace std;
//creation of linked list Node
class Node
{
    public:
    int data;
    Node *next;
};
//craetion of list class implemeting node class and other functions
class List
{
    private:
    Node *head;
    public:
    List()
    {
        head=NULL;
    }
    List(int a[],int n);
    void display();
    void insert_at_beg(int x);
    void insert_at_last(int x);
    void insert_at_pos(int x,int index);
    int length();
    ~List();
};
/* parameterized constructor used to make 
linked list using array*/ 
List::List(int a[],int n)
{
    Node *last,*t;
    head = new Node;
    head->data=a[0];
    head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
//display function for displaying linked list
void List::display()
{
    Node *p=head;
    while(p)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
}
//length function for linked list
int List::length()
{
    int x=0;
    Node *p=head;
    while(p)
    {
        x++;
        p=p->next;
    }
    return(x);
}
//insertion at the beginning of a linked List
void List::insert_at_beg(int x)
{
    Node *t;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(head == NULL)
    {
        head = t;
    }
    else
    {
        t->next=head;
        head = t; 
    }
}
//insertion at the end of a linked List
void List::insert_at_last(int x)
{
    Node *t,*p=NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(head == NULL)
    {
        head = t;
    }
    else
    {
        p = head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}
//insertion at a specific position of a linked List
void List::insert_at_pos(int x,int index)
{
    Node *t,*p=NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(index == 0)
    {
        insert_at_beg(x);
    }
    else
    {
        p = head;
        for(int i=0;i<index-1;i++)
        {
            if(p)
            {
                p=p->next;
            }
            else
            {
                cout<<"Insertion not possible"<<endl;
                cout<<"error";
            }
        }
        t->next=p->next;
        p->next=t;
    }
}
//destructor for adeletion of a linked list
List::~List()
{
    Node *p=head;
    while(head)
    {
        head=head->next;
        delete p;
        p=head;
    }
}
//Main driver function
int main()
{
    int i,n,a[10];
    cout<<"Enter the no of elements you want to enter in your linked list:"<<endl;
    cin>>n;
    cout<<"Enter "<<n<<" elements "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    List obj(a,n);
    obj.display();
    cout<<endl;
    obj.insert_at_beg(0);
    obj.insert_at_last(12);
    obj.insert_at_pos(33,3);
    obj.display();
    return 0;
}
