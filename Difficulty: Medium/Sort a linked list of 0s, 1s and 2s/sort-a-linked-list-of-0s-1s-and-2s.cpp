/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
  Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next; 
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* merge(Node* l1, Node* l2) {
        Node* dummy = new Node(0);
        Node* curr = dummy;

        while (l1 && l2) {
            if (l1->data < l2->data) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1) curr->next = l1;
        else curr->next = l2;

        return dummy->next; 
    }
    Node* segregate(Node* head) {
        // code here
         if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* mid = findMiddle(head);
        Node* rightHead = mid->next;
        mid->next = nullptr; 

        Node* left = segregate(head);
        Node* right = segregate(rightHead);

        return merge(left, right);
    }
};