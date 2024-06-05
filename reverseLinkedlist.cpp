#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList {
public:
    static ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;

        while (current != NULL) {
            next = current->next;  // Store next node
            current->next = prev;  // Reverse current node's pointer
            prev = current;        // Move prev to this node
            current = next;        // Move to next node
        }
        head = prev;  // Update head to new front of list
        return head;
    }

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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    LinkedList::printList(head);

    head = LinkedList::reverseList(head);

    cout << "Reversed list: ";
    LinkedList::printList(head);

    return 0;
}
