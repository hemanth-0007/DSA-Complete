// Is palindrome or not

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

    int getLen()
    {
        if (head == NULL)
            return 0;
        Node *slow = head, *fast = head;
        int cnt = 1;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            cnt++;
        }
        if (fast == NULL)
            return (2 * cnt - 2);
        if (fast->next == NULL)
            return (2 * cnt - 1);
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
    void isPalindrome();
};

void LinkedList ::isPalindrome()
{
    if (head == NULL)
    {
        cout << "head is NULL" << endl;
        return;
    }
    Node *ptr = head;
    vector<int> vec;
    while (ptr != NULL)
    {
        vec.push_back(ptr->val);
        ptr = ptr->next;
    }
    int n = vec.size();
    for(int i = 0 ; i < n/2 ; i++) {
        if(vec[i] != vec[n - i -1]){
            cout<<"Not a palindrome"<<endl;
            return;
        }
    }
    
    cout << "it is a palindrome" << endl;
    return;
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
    l1->isPalindrome();
    return 0;
}