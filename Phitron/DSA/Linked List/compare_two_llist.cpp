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

int isSimilar(Node* head1,Node *head2){
    
    int cnt1,cnt2;
    cnt1 = size(head1);
    cnt2 = size(head2);
    
    Node *currentNode1=head1;
    Node *currentNode2=head2;
    if(cnt1 == cnt2){
        while ((currentNode1 !=NULL)&&(currentNode2 !=NULL)) {
            if(currentNode1->val != currentNode2->val){
                return 0;
                break;
            }
            currentNode1=currentNode1->next;
            currentNode2=currentNode2->next;
        }
        return 1;
    }
    return 0;
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
        int res=isSimilar(head1, head2);
        cout << res << endl;
    }
      
    return 0;
}
