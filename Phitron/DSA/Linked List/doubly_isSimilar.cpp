/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    Node *prev;
    int val;
    Node *next;
    
    Node(int val){
        this -> val = val;
    }
};

void insert(Node *&head,Node *&tail,int v){
    
    Node *newNode = new Node(v);
    
    // Node *currentNode= head;
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}

void print(Node *head){
    Node *currentNode=head;
    
    while(currentNode!=NULL){
        cout << currentNode->val << " ";
        currentNode=currentNode->next;
    }
    cout << endl;
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

void isSimilar(Node *head1,Node *head2){
    int len1=size(head1);
    int len2=size(head2);
    
    Node *currentNode1=head1;
    Node *currentNode2=head2;
    
    if(len1==len2){
        while(currentNode1!=NULL && currentNode2!=NULL){
            if(currentNode1->val != currentNode2->val){
                cout << "NO"<<endl;
                return;
                break;
            }
            currentNode1=currentNode1->next;
            currentNode2=currentNode2->next;
        }
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
}

int main()
{
    
    Node *head1=NULL;
    Node *head2=NULL;
    
    Node *tail1=NULL;
    Node *tail2=NULL;
    
    int v;
    
    while(true){
        cin >> v;
        if(v==-1){
            break;
            
        }
        insert(head1,tail1,v);
    }
   
    
     while(true){
        cin >> v;
        if(v==-1){
            break;
            
        }
        insert(head2,tail2,v);
    }
    cout << "List 1 : ";
    print(head1);
    cout << "List 2 : ";
    print(head2);
    
    cout<<"Size 1 : "<<size(head1);
    cout<<endl;
    cout<<"Size 2 : "<<size(head2);
    cout<<endl;
    isSimilar(head1,head2);

    return 0;
}