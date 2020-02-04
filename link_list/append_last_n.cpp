#include<iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};



node* append_LinkedList(node* head,int n)
{
    node* temp = head;
    node* end = head;
    node* prev_head = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        end = temp;
        temp = temp->next;
    }
    
    int i = len - n;
    int count = 1;
    temp = head;
    while(temp != NULL){
        if(count == i){
            head = temp->next;
            temp->next = NULL;
            end->next = prev_head;
            break;
        }else{
            count++;
            temp = temp->next;
        }
    }
    return head;
}



node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}
