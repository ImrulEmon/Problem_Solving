#include <bits/stdc++.h>

using namespace std;

class Node{
  public:
    Node *prev;
    string val;
    Node *next;
    
    Node(string val){
        this->prev=NULL;
        this->val=val;
        this->next=NULL;
    }
};

void insert_tail(Node *&head,Node *&tail,string val){
    
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
   
    cout<< currentNode->val << " ";
    print(currentNode->next);
}

Node *visit(Node *head,Node *&uCurrent,string s){
    if(head==NULL){
        return uCurrent;
    }
    Node *currentNode=head;
    while(currentNode!=NULL){
        if(s==currentNode->val){
            cout << currentNode -> val <<endl;
            uCurrent=currentNode;
            return uCurrent;
        }
        currentNode=currentNode->next;
    }
    cout << "Not Available"<<endl;
    return uCurrent;
}

Node *next(Node *&uCurrent,Node *nxt){
   Node *currentNode=nxt; 
   if(currentNode->next!=NULL){
       cout<< currentNode->next->val<<endl;
       uCurrent=currentNode->next;
       return uCurrent;
   }
    cout << "Not Available"<<endl;
    return uCurrent;
}
Node *prev(Node *&uCurrent,Node *prv){
   Node *currentNode=prv; 
   if(currentNode->prev!=NULL){
       cout<< currentNode->prev->val<<endl;
       uCurrent=currentNode->prev;
       return uCurrent;
   }
    cout << "Not Available"<<endl;
    return uCurrent;
}

int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    Node *uCurrent=NULL;
    string str,cmd,param,end="end";
    while(true){
        cin >> str;
        if(end==str){
            break;
        }
        insert_tail(head,tail,str);
    }
    int t;
    cin >> t;
    cin >> cmd >> param;
    uCurrent=head;
    uCurrent=visit(head,uCurrent,param);
    t-=1;
     while (t--) {
        cin >> cmd;

        if (cmd == "visit") {
            cin >> param;
            uCurrent=visit(head,uCurrent,param);
        } else if (cmd == "next") {
            uCurrent= next(uCurrent,uCurrent);
        } else if (cmd == "prev") {
            uCurrent= prev(uCurrent,uCurrent);
        }
    }
    

    return 0;
}
