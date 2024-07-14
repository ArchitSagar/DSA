//  Merge Two Sorted Lists

// Easy
// Topics
// Companies
// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

 

// Example 1:


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]


#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0),next(nullptr) {}
    ListNode(int x,ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* n = new ListNode();
        ListNode* temp = n;
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;

            }
        }
        if(l1) temp->next = l1;
        else temp->next = l2;
        return n->next;
    }
};

int main(){
    ListNode* list1 = new ListNode(1,new ListNode(3,new ListNode(5,NULL)));
    ListNode* list2 = new ListNode(2,new ListNode(4,new ListNode(6,NULL)));

    Solution sol;

    ListNode* merge = sol.mergeTwoLists(list1,list2);

    while(merge){
        cout << merge->val<< " ";
        merge = merge->next;
    }
    cout << endl;
    return 0;

}