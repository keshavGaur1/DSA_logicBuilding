/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
         Node * temp=head;
        while (temp){
            Node * node = temp->next;
            temp->next = temp->prev;
            temp->prev = node;
            if(!node) break;
            temp = node;
        }
        
        return temp;
    }
};