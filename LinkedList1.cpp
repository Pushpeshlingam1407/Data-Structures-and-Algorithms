#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void create(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
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
