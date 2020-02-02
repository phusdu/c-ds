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


node* eliminate_duplicate(node* head)
{
    if(head != NULL){
        node* t1 = head;
        node* t2 = head->next;
        while(t2 != NULL){
            if(t1->data == t2->data){
                node* tmp = t2;
                t2 = t2->next;
                delete tmp;
            }else{
                t1->next = t2;
                t1 = t2;
                t2 = t2->next;
            }
        }
        t1->next = t2;
        return head;
    }else{
        return head;
    }
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
int main(){
    node* head=takeinput();
    head=eliminate_duplicate(head);
    print(head);
    return 0;
}

