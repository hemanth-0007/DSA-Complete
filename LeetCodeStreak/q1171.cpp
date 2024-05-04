#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void removeZeroSumArray(vector<int> &nums)
{
   
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == 0){
                cout<<i<<" "<<j<<endl;
                nums.erase(nums.begin() + i, nums.begin() + j + 1);
            }
        }
    }
}

ListNode *insertNode(ListNode *head, int key)
{
    ListNode *newNode = new ListNode(key);
    if (head == NULL){
        head = newNode;
        return head;
    }
    ListNode  *tempHead = head;
    while (tempHead->next != NULL) tempHead = tempHead->next;
    tempHead->next = newNode;
    return head;
}

ListNode *removeZeroSumSublists(ListNode *head)
{
    vector<int> arr = {};
    ListNode *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->val);
        temp = temp->next;
    }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    removeZeroSumArray(arr);
    // for (int i = 0; i < arr.size(); i++)
    //     cout<<arr[i]<<" ";
    ListNode *ansHead = NULL;
    for (auto num : arr)
        ansHead = insertNode(ansHead, num);
    
    return ansHead;
}

int main()
{
    ListNode *head = new ListNode(0);
    head->next = new ListNode(0);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(-3);
    // head->next->next->next->next = new ListNode(-2);
    ListNode *temp = removeZeroSumSublists(head);
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}