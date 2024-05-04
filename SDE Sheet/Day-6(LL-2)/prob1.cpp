
//finding the intersection
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
        
        void insert(Node* node){
             
            if(head == NULL){
                head = node;
                return;
            }     
            Node* temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = node;
        
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
 
int intersect(LinkedList *l1,LinkedList *l2){
    if(l1->head == NULL){
        cout<<"l1 head Nullptr"<<endl;
        return -1;
    }
    if(l2->head == NULL){
        cout<<"l2 head Nullptr"<<endl;
        return -1;
    }
    Node* ptr1 = l1->head;
    Node* ptr2 = l2->head;
    unordered_set<Node*> st;
    //O(m + n)
    while (ptr1 != NULL)
    {
        st.insert(ptr1);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        if(st.count(ptr2)) return ptr2->val;
        ptr2 = ptr2->next;
    }
    
    
    return -1;
}

int main()
{
    LinkedList *l1 = new LinkedList() ;
    Node* n1 = new Node(1), *n2 = new Node(2), *n3 = new Node(3), *n4 = new Node(4), *n5 = new Node(5);
    l1->insert(n1);
    l1->insert(n2);
    l1->insert(n3);
    l1->insert(n4);
 
    LinkedList *l2 = new LinkedList() ;
    l2->insert(n5);
    l2->insert(n3);
 
    cout<<intersect(l1,l2);
    
 
 
return 0;
}