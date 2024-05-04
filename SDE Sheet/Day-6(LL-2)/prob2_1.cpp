
 // detecting a cycle
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
 
int isCycle(LinkedList *l1){
    if(l1->head == NULL){
        cout<<"noCycle exits"<<endl;
        return -1;
    }
    
    Node* ptr1 = l1->head;
     unordered_set<Node*> st;
    while (ptr1!= NULL)
    {
        auto itr = st.find(ptr1);
        if(itr != st.end()){
            return 1;
        }
        else{
            st.insert(ptr1);
        }
        
         
        ptr1 = ptr1->next;
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
    n4->next = n3;
 
    LinkedList *l2 = new LinkedList() ;
    l2->insert(n5);
    
    cout<<isCycle(l2);
    
 
 
return 0;
}