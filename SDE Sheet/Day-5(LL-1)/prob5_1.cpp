
 
// deleting the given node in O(1)
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
// node is never a tail node
Node* deleteNode(LinkedList* l1, Node* node){
     
     int value = node->next->val;
     node->val = value;
     Node* temp = node->next;
     node->next = node->next->next;

        return l1->head;

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

     
    l1->head = deleteNode(l1,l1->head->next);
    l1->printList();
 
return 0;
}