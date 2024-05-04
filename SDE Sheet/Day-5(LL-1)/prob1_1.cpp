
// Reversing a linked list 

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
        void reverse(){
             
            Node* ptr = head,* nex = NULL,* prev = NULL;
            while (ptr != NULL)
            {
               nex = ptr->next;
               ptr->next = prev;
               prev = ptr;
               ptr = nex;
                
            }
            head = prev;

        }
        
        void printList(){
            Node* temp = head;
            if(head == NULL) cout<<"NULL";
            while (temp != NULL)
            {
                cout<<temp->val<<" ";
                temp = temp->next;
            }
            cout<<endl;
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
    l1->printList();
    l1->reverse();
    l1->printList();

return 0;
}