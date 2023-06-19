/* 
https://www.hackerrank.com/challenges/compare-two-linked-lists/problem?isFullScreen=true&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
compare-two-linked-lists
*/


#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void insert(Node *&head,Node *&tail,int v){
    Node *newNode=new Node(v);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}

int size(Node *head){
    Node *currentNode=head;
    int cnt=0;
    while(currentNode!=NULL){
        cnt++;
        currentNode=currentNode->next;
    }
    return cnt;
}

void print(Node *head){
    Node *currentNode=head;
    if(currentNode==NULL) return;
    std::cout << currentNode->val << " ";
    print(currentNode->next);
}

Node* sort_list(Node *&head){
    Node* currentNode = head;
    
    for(Node *i=currentNode;i->next!=NULL;i=i->next){
        for(Node *j=i->next;j!=NULL;j=j->next){
            if(i->val > j->val){
                swap(i->val , j->val);
            }
        }
    }
    return head;
}

Node *mergeFunction(Node *&head1,Node *&head2){
    if((head1==NULL) && (head2==NULL))
    {
        return NULL;
    }
    else if((head1!=NULL) && (head2==NULL))
    {
        return head1;
    }
    else if((head1==NULL) && (head2!=NULL))
    {
        return head2;
    }
    else{
        Node *currentNode=head1;
        while(currentNode->next!=NULL){
            currentNode=currentNode->next;
        }
        currentNode->next=head2;
        return head1;
    }
}


int main() {
    int t;
    cin >> t;
    
    for(int c=0;c<t;c++){
        
        Node *head1=NULL;
        Node *head2=NULL;
        
        Node *tail1=NULL;
        Node *tail2=NULL;
        
        int s1,s2,v;
        cin >> s1;
        for(int i=0;i<s1;i++){
            cin>>v;
            insert(head1,tail1,v);
        }
        cin >> s2;
        for(int i=0;i<s2;i++){
            cin>>v;
            insert(head2,tail2,v);
        }
        
        Node *mergeHead=mergeFunction(head1,head2);
        
        Node *sortedhead=sort_list(mergeHead);
        
        
        print(sortedhead);
    }
    
    
      
    return 0;
}
