
// Reversing a linked list 

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* bottom;
        Node(){
        this->val = 0;
        this->bottom = NULL;
        this->next = NULL;
       }
       // parameterized one
        Node(int data){
        this->val = data;
        this->next = NULL;
        this->bottom = NULL;
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
            while (temp->bottom != NULL) temp = temp->bottom;
            temp->bottom = new_node;
        
        }
        
        void printList(){
            Node* temp = head;
            if(head == NULL) cout<<"NULL";
            while (temp != NULL)
            {
                cout<<temp->val<<" ";
                temp = temp->bottom;
            }
            cout<<endl;
            return;
        }


};
 LinkedList* merge(LinkedList* l1, LinkedList* l2){

    if(l1->head == NULL) return l2;
    if(l2->head == NULL) return l1;
    Node* ptr1 = l1->head , *ptr2 = l2->head;
    LinkedList* l = new LinkedList();

    while (ptr1 != NULL && ptr2 != NULL)
    {
         if(ptr1->val >= ptr2->val){
            l->insert(ptr2->val);
            ptr2 = ptr2->bottom;
         }
         else{
            l->insert(ptr1->val);
            ptr1 = ptr1->bottom;
         }
    }
    while (ptr1 != NULL)
    {
        l->insert(ptr1->val);
        ptr1 = ptr1->bottom;
    }
     while (ptr2 != NULL)
    {
        l->insert(ptr2->val);
        ptr2 = ptr2->bottom;
    }
    
    return l;
}

int main()
{
    LinkedList* l1 = new LinkedList();
    l1->insert(1);l1->insert(2);l1->insert(5);l1->insert(6);
    LinkedList* l2 = new LinkedList();
    l2->insert(4);l2->insert(7); 
    LinkedList* l3 = new LinkedList();
    l3->insert(9);l3->insert(10);
    l1->head->next = l2->head;
    l2->head->next = l3->head;
    
    l1 = merge(l1,l2);
    l1 = merge(l1,l3);
    l1->printList();

return 0;
}