/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        Node* slow = head;
        Node* fast = head;
        
        for(int i =0;i<k;i++){
            if(fast == nullptr){
                return -1;
            }
            fast=fast->next;
        }
        
        while(fast!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow->data;
    
    }
};