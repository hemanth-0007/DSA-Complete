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
 
int findCycleBegin(LinkedList *l1){
    if(l1->head == NULL){
        cout<<"noCycle exits"<<endl;
        return -1;
    }
    
    Node* ptr1 = l1->head;
     map<Node*, int> mpp;
     int cnt = 0;
    while (ptr1!= NULL)
    {
        auto itr = mpp.find(ptr1);
        if(itr != mpp.end()){
            return itr->second;
        }
        else{
            mpp.insert({ptr1, cnt});
        }
        
         
        ptr1 = ptr1->next;
        cnt++;
    }
    cout<<"NULL"<<endl;
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
    n4->next = n2;
    cout<<findCycleBegin(l1);
    
 
    
 
 
return 0;
}