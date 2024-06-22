#include<bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* reverseLinkedList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
 
ListNode* doubleIt(ListNode* head) {
    head = reverseLinkedList(head);
    ListNode* temp = head;
    int carry = 0;
    while(temp != NULL){
        int num = temp->val;
        num = num*2 + carry;
        carry = num/10;
        int value = num%10;
        temp->val = value;
        temp = temp->next;
    }
    temp = head;
    while(temp->next != NULL)  temp = temp->next;
    if(carry != 0){
        ListNode* newNode = new ListNode(carry);
        temp->next = newNode;
    }
    return reverseLinkedList(head);
}
int main()
{

return 0;
}