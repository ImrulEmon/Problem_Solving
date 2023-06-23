#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void insert(Node *&head,Node *&tail,int v){
    Node *newNode = new Node(v);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}

void sort(Node *&head){
    Node *temp=head;
    for(Node *i=temp;i->next!=NULL;i=i->next){
        for(Node *j=i->next;j!=NULL;j=j->next){
            if(i->val > j->val){
                swap(i->val,j->val);
            }
        }
    }
}

void del(Node *&head){
    Node *temp=head;
    while(temp!=NULL && temp->next !=NULL){
        if(temp->val == temp->next->val){
            Node *dlt=temp->next;
            temp->next=dlt->next;
            delete dlt;
        }
        else{
            temp=temp->next;
        }
    }
}
    

    
void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    int v;
    while(true){
        cin >> v;
        if(v==-1){
            break;
        }
        
        insert(head,tail,v);
    }
    sort(head);
    del(head);
    print(head);
    return 0;
}