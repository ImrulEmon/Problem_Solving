#include<bits/stdc++.h>
#include <iostream>

using namespace std;

class Node{
  public:
    Node *prev;
    int val;
    Node *next;
    
    Node(int val){
        this->prev=NULL;
        this->val=val;
        this->next=NULL;
    }
};

void insert(Node *&head,Node *&tail,int val){
    
    Node *newNode = new Node(val);
    
    if(head ==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}

void print(Node *head){
     Node *currentNode =head;
    if(currentNode==NULL){
        cout << endl;
        return;
    }
   
    cout << currentNode->val << " ";
    print(currentNode->next);
}

void palindrome(Node *head,Node *tail){
    
    Node *i=head;
    Node *j=tail;
    
    if(head==NULL){
        cout << "NO"<<endl;
            return;
    }
    
    while((i!=j) && (i->prev!=j)){
        if(i->val != j->val){
            cout << "NO"<<endl;
            return;
        }
        cout << i->val << " " << j->val <<endl;
        i=i->next;
        j=j->prev;
    }
     cout << "YES" << endl;
}


// void palindrome(Node *head, Node *tail) {
//     if (head == NULL) {
//         cout << "NO" << endl;  // Empty list is not a palindrome
//         return;
//     }

//     while (head != tail && head->prev != tail) {
//         if (head->val != tail->val) {
//             cout << "NO" << endl;
//             return;
//         }
//         head = head->next;
//         tail = tail->prev;
//     }

//     cout << "YES" << endl;
// }


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
    //print(head);
    
    palindrome(head,tail);

    return 0;
}
