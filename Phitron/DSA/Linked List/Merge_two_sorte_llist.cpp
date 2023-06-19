#include <iostream>

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

void insertNodeAtTail(SinglyLinkedListNode* &head, int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    SinglyLinkedListNode* currentNode = head;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* headA, SinglyLinkedListNode* headB) {
    if (headA == nullptr) {
        return headB;
    }
    if (headB == nullptr) {
        return headA;
    }
    
    SinglyLinkedListNode *mergedHead=NULL;
    SinglyLinkedListNode *tail=NULL;
    //  Assign head Node
    if(headA->data<headB->data){
        mergedHead=headA;
        headA=headA->next;
    }
    else{
        mergedHead=headB;
        headB=headB->next;
    }
    tail=mergedHead;
    // Now truverse all the list
    while(headB!=NULL && headA!=NULL){
        if(headA->data < headB->data){
            tail->next=headA;
            headA=headA->next;
        }
        else{
            tail->next=headB;
            headB=headB->next;
        }
        tail=tail->next;
    }
    // Connect rest of the nodes end of the tail
    if(headB==NULL){
        tail->next=headA;
        
    }else{
        tail->next=headB;
    }
    
    return mergedHead;
   
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        SinglyLinkedListNode* headA = nullptr;
        SinglyLinkedListNode* headB = nullptr;

        int m, n, data;
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> data;
            insertNodeAtTail(headA, data);
        }

        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> data;
            insertNodeAtTail(headB, data);
        }

        SinglyLinkedListNode* mergedList = mergeLists(headA, headB);
        printLinkedList(mergedList);
    }

    return 0;
}
 