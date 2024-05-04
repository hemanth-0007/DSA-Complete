// Is palindrome or not
// Optimised solution
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node()
    {
        this->val = 0;
        this->next = NULL;
    }
    // parameterized one
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList() { head = NULL; }

    void insert(int data)
    {
        Node *new_node = new Node(data);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }

     
    void printList()
    {
        Node *temp = head;
        if (head == NULL)
            cout << "NULL";
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
    bool isPalindrome();
    Node* reverse(Node* ptr);
};

Node* LinkedList :: reverse(Node* ptr){
             
    Node* nex = NULL,* prev = NULL;
    while (ptr != NULL)
    {
        nex = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = nex;
        
    }
    return prev;

}
bool LinkedList ::isPalindrome()
{
    if (head == NULL || head->next == NULL)
        return true;
    
    Node* slow = head, *fast = head , *dummyHead = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    while (slow != NULL)
    {
        if(slow->val != dummyHead->val) return false;
        slow = slow->next;
        dummyHead = dummyHead->next;
    }
    return true;
    
}

int main()
{
    LinkedList *l1 = new LinkedList();
    l1->insert(2);
    l1->insert(3);
    l1->insert(4);

    l1->insert(3);
    l1->insert(2);

    l1->printList();
    cout<<l1->isPalindrome();
    return 0;
}