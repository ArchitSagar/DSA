#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL || node->next == NULL) {
            return; // Edge case: node is NULL or node is the last node
        }
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& vec) {
    if (vec.empty()) return NULL;
    ListNode* head = new ListNode(vec[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vec.size(); ++i) {
        current->next = new ListNode(vec[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    vector<int> vec(n);
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    ListNode* head = createList(vec);

    cout << "Original list: ";
    printList(head);

    int value;
    cout << "Enter the value of the node to delete: ";
    cin >> value;

    // Find the node with the given value
    ListNode* current = head;
    ListNode* prev = NULL;
    while (current != NULL && current->val != value) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            // If the node to be deleted is the head node
            ListNode* newHead = head->next;
            delete head;
            head = newHead;
        } else {
            Solution solution;
            solution.deleteNode(current);
        }

        cout << "List after deleting node with value " << value << ": ";
        printList(head);
    } else {
        cout << "Node with value " << value << " not found in the list." << endl;
    }

    // Free memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

