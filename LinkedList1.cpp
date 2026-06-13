#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void create(int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        create(data);
    }

    struct Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    return 0;
}
