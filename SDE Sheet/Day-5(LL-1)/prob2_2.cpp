
// Finding Out the middle element 
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(){
        this->val = 0;
        this->next = NULL;
       }
       // parameterized one
        Node(int data){
        this->val = data;
        this->next = NULL;
        }
};


class LinkedList {
    public:
        Node* head;
        LinkedList(){ head = NULL;}
        
        void insert(int data){
            Node* new_node = new Node(data);
            if(head == NULL){
                head = new_node;
                return;
            }     
            Node* temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = new_node;
        
        }
       
       
        int midElem(){
            
            Node* slowPtr = head ,* fastPtr = head;
            while(fastPtr != NULL && fastPtr->next != NULL)
            {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next->next;
            }
            return slowPtr->val;
        }
        
        void printList(){
            Node* temp = head;
            if(head == NULL) cout<<"NULL";
            while (temp != NULL)
            {
                cout<<temp->val<<" ";
                temp = temp->next;
            }
            return;
        }
};
 

int main()
{
    LinkedList *l1 = new LinkedList() ;
    l1->insert(2);
    l1->insert(3);
    l1->insert(4);
    l1->insert(1);
    l1->insert(5);
    // O(n) + O(n/2)
    cout<< l1->midElem();
return 0;
}