/*

143. Reorder List


Medium
Topics
Companies
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]




*/




#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int x,ListNode *next) : val(x), next(next) {}
};

class LinkedList {
public:
    ListNode* traverse(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }

    static ListNode* reverseList(ListNode* mid) {
        ListNode* prev = mid;
        ListNode* current = mid->next;
        ListNode* next = NULL;

        prev->next = nullptr;

        while (current != NULL) {
            next = current->next;  // Store next node
            current->next = prev;  // Reverse current node's pointer
            prev = current;        // Move prev to this node
            current = next;        // Move to next node
        }
        return prev;
    }

    void merge(ListNode* head, ListNode* end){
        ListNode* temp1 = head;
        ListNode* temp2 = end;
        ListNode* n1 = nullptr;
        ListNode* n2 = nullptr;

        while(temp2){
            n1 = temp1->next;
            temp1->next = temp2;
            n2 = temp2->next;
            temp2->next = n1;
            temp1 = n1;
            temp2 = n2;
        }

    }

    // void reorderList(ListNode* head) {
    //     ListNode* end = head;
    //     ListNode* endA = head;
        
    // }

    static void printList(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Creating a linked list 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6,NULL))))));
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    LinkedList::printList(head);


    LinkedList l;

    ListNode* mid1 = NULL;
    ListNode* end = NULL;

    ListNode* mid = l.traverse(head);
    mid1 = mid->next;
    mid->next = nullptr;

    cout << mid->val << endl;

    end = l.reverseList(mid1);

    cout << "Reversed list: ";
    LinkedList::printList(head);
    LinkedList::printList(end);

    cout << "merge: ";
    l.merge(head,end);

    LinkedList::printList(head);



    return 0;
}
