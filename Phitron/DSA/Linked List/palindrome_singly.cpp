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



Node* reverse(Node* head) {
  
    Node* reversedHead = NULL;
    
    while (head != NULL) {
        Node* newNode = new Node(head->val);
        newNode->next = reversedHead;
        reversedHead = newNode;
        head = head->next;
    }
    
    return reversedHead;
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
    Node *temp=head;
   Node *revHead = reverse(temp);
//   print(head);
//   print(revHead);
    if (revHead == NULL) {
    cout << "YES" << endl;
    } else {
    Node *temp = head;
    Node *temp2 = revHead;
    bool flag = true;
    while (temp2 != NULL) {
        if (temp->val != temp2->val) {
            cout << "NO" << endl;
            flag = false;
            break;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }
    if (flag == true) {
        cout << "YES" << endl;
    }
}

    return 0;
}