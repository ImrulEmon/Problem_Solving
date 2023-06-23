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

void insert_tail(Node *&head,Node *&tail,int val){
    
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

void insert_head(Node *&head,Node *&tail,int val){
   
    Node *newNode = new Node(val);
    
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    
 
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void insert_pos(Node *&head,int pos,int v){
    
    
    Node *newNode=new Node(v);
    Node *currentNode =head;
    for(int i=1;i<pos;i++){
        if(currentNode == NULL){
            cout << "Invalid";
            return;
        }
        currentNode=currentNode->next;
    }
    newNode->next=currentNode->next;
    currentNode->next->prev=newNode;
    
    newNode->prev=currentNode;
    currentNode->next=newNode;
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

void print_reverse(Node *head,Node *tail){
    
    Node* currentNode = tail;
    
    if(head==NULL){
        cout << "Empty List" << endl;
    }
    
    for(currentNode;currentNode!=NULL;currentNode=currentNode->prev){
        cout << currentNode->val << " ";
    }
    
    cout << endl;
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

int size(Node *head){
    int cnt=0;
    Node *currentNode=head;
    while(currentNode!=NULL){
        cnt++;
        currentNode=currentNode->next;
    }
    return cnt;
}

Node* sort(Node *head){
    Node *i=head;
    // Node *j=tail;
    
   for(i;i->next !=NULL;i=i->next){
       for(Node *j=i->next;j!=NULL;j=j->next){
           if(i->val > j->val){
               swap(i->val,j->val);
           }
       }
   }
   return head;
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
    
    int v,pos;
    
    
     while(true){
        
        cin >> v;
        if(v==-1){
            break;
        }
        insert_tail(head,tail,v);
     }
    
    
    /* int t;
    cin >> t;
    if(t==0){
        return 0;
    }
    while(t--){
        
        cin >> pos >> v;
        // if(v==-1){
        //     break;
        // }
        if(pos>size(head)){
            cout << "Invalid"<<endl;
        }
        else if(pos==0){
            
            insert_head(head,tail,v);
            print(head);
            print_reverse(head,tail);
            
        }else if(pos==size(head)){
      
        insert_tail(head,tail,v);
        print(head);
        print_reverse(head,tail);
        
        }
        else{
            insert_pos(head,pos,v);
            print(head);
            print_reverse(head,tail);
        }
    } */
    Node *sortedHead=sort(head);
    
    print(sortedHead);
    print(head);
    
    // palindrome(head,tail);

    return 0;
}
