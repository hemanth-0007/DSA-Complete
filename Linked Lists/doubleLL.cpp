#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insertAtIndex(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Invalid index\n";
            return;
        }

        if (index == 0) {
            insertAtHead(value);
        } else if (index == size) {
            insertAtTail(value);
        } else {
            Node* newNode = new Node(value);
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            size++;
        }
    }

    void deleteAtHead() {
        if (!isEmpty()) {
            Node* temp = head;
            head = head->next;
            if (head) 
                head->prev = nullptr;
          else 
                tail = nullptr;
            
            delete temp;
            size--;
        }
    }

    void deleteAtTail() {
        if (!isEmpty()) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
            size--;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index\n";
            return;
        }

        if (index == 0) {
            deleteAtHead();
        } else if (index == size - 1) {
            deleteAtTail();
        } else {
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            size--;
        }
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout<<endl;
    }

     
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(5);
    dll.insertAtTail(10);
    dll.insertAtTail(15);
    dll.insertAtIndex(1, 7);

    dll.display(); // Output: 5 7 10 15

    dll.deleteAtHead();
    dll.deleteAtTail();
    dll.deleteAtIndex(1);

    dll.display(); // Output: 7

    return 0;
}
