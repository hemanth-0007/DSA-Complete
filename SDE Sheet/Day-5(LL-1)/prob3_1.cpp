
 
// merging two sorted arrays
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
 
LinkedList* merge(LinkedList* l1, LinkedList* l2){

    if(l1->head == NULL) return l2;
    if(l2->head == NULL) return l1;
    Node* ptr1 = l1->head , *ptr2 = l2->head;
    LinkedList* l = new LinkedList();

    while (ptr1 != NULL && ptr2 != NULL)
    {
         if(ptr1->val >= ptr2->val){
            l->insert(ptr2->val);
            ptr2 = ptr2->next;
         }
         else{
            l->insert(ptr1->val);
            ptr1 = ptr1->next;
         }
    }
    while (ptr1 != NULL)
    {
        l->insert(ptr1->val);
        ptr1 = ptr1->next;
    }
     while (ptr2 != NULL)
    {
        l->insert(ptr2->val);
        ptr2 = ptr2->next;
    }
    
    return l;
}

int main()
{
    LinkedList *l1 = new LinkedList() ;
    l1->insert(1);
    l1->insert(2);
    l1->insert(7);
    l1->insert(8);
 
    LinkedList *l2 = new LinkedList() ;
    l2->insert(4);
    l2->insert(5);

    LinkedList *res = merge(l1,l2);
    res->printList();
 
 
return 0;
}