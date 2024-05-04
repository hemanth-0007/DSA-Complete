
 
// deleting the nth node from the last
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

Node* deleteNthFromEnd(LinkedList* l1, int n){
    Node* start = new Node();
    start->next = l1->head;
    Node* fast = start;
    Node* slow = start;
    // startting at the dummy node

    for (int i = 1; i <=n; i++)
        fast = fast->next;
    
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = slow->next->next;
    return start->next;

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

     
    l1->head = deleteNthFromEnd(l1,1);
    l1->printList();
 
return 0;
}