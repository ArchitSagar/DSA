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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false; // A list with no nodes or just one node cannot have a cycle
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle
    }
};

// Helper function to create a linked list with a cycle for testing purposes
ListNode* createListWithCycle(const vector<int>& vec, int pos) {
    if (vec.empty()) return NULL;
    
    ListNode* head = new ListNode(vec[0]);
    ListNode* current = head;
    ListNode* cycleEntry = NULL;

    for (size_t i = 1; i < vec.size(); ++i) {
        current->next = new ListNode(vec[i]);
        current = current->next;
        if (i == pos) {
            cycleEntry = current;
        }
    }

    if (cycleEntry != NULL) {
        current->next = cycleEntry;
    }

    return head;
}

int main() {
    // Create a linked list [3, 2, 0, -4] with a cycle at position 1 (0-indexed)
    vector<int> vec = {3, 2, 0, -4};
    int pos = 1; // Indicates that the tail connects to the node at position 1
    ListNode* head = createListWithCycle(vec, pos);

    Solution solution;
    bool hasCycle = solution.hasCycle(head);
    if (hasCycle) {
        cout << "The list has a cycle." << endl;
    } else {
        cout << "The list does not have a cycle." << endl;
    }

    // Note: Normally, you should free the allocated memory. However, since the list has a cycle,
    // freeing the memory is complex and is omitted here for simplicity.

    return 0;
}
