#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        data = 0;
        prev = NULL;
        next = NULL;
    };
    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class List
{
public:
    Node *head, *tail;
    int size;
    List(){
        size = 0;
        head = NULL;
        tail = NULL;
    }
    void insertBegin(Node* node);
    void insertEnd(Node* node);
    void traverse();
    void deleteBegin();
    void deleteEnd();
    void deleteNode(Node* node);
};

void List::insertBegin(Node* node)
{
    if (head == NULL) {
        head = node;
        tail = head;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    size++;
}

void List::insertEnd(Node* node)
{
    if (head == NULL) {
        head = node;
        tail = head;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    size++;
}

void List::traverse()
{
    Node* temp = head;
    if(temp == NULL) return;
    cout << "size is " << size << endl;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void List::deleteBegin()
{
    if (head == NULL) return; // Check if list is empty
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL; // If the list becomes empty
    }
    delete temp;
    size--;
}

void List::deleteEnd()
{
    if (tail == NULL) return; // Check if list is empty
    Node* temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL; // If the list becomes empty
    }
    delete temp;
    size--;
}

void List::deleteNode(Node* node)
{
    if(node == NULL) {
        cout << "Node is NULL" << endl;
        return;
    }
    if (node == head) {
        deleteBegin();
        return;
    }
    if (node == tail) {
        deleteEnd();
        return;
    }
    Node* prevNode = node->prev;
    Node* nextNode = node->next;
    if (prevNode != NULL) {
        prevNode->next = nextNode;
    }
    if (nextNode != NULL) {
        nextNode->prev = prevNode;
    }
    delete node;
    size--;
}

int pageFaults(int N, int C, int pages[])
{
    List* list = new List();
    unordered_map<int, Node*> mp;
    int ans = 0; // number of page faults
    for (int i = 0; i < N; i++)
    {
        if (mp.find(pages[i]) != mp.end()) {
            list->deleteNode(mp[pages[i]]);
            Node* node = new Node(pages[i]);
            list->insertBegin(node);
            mp[pages[i]] = node;
        } else {
            if (list->size == C) {
                int key = list->tail->data;
                list->deleteEnd();
                mp.erase(key);
            }
            Node* node = new Node(pages[i]);
            list->insertBegin(node);
            mp[pages[i]] = node;
            ans++;
        }
    }
    // Cleanup
    delete list;
    return ans;
}

int main()
{
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int N = sizeof(pages)/sizeof(pages[0]);
    int C = 3;
    cout << "Page Faults: " << pageFaults(N, C, pages) << endl;
    return 0;
}
