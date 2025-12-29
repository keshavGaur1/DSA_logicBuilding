/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
          deque<int> result;

        queue<pair<Node*, int> > q;

        q.push(pair<Node*, int>(root, 0));

        int leftmin=0; int rightmax=0;

        result.push_back(root->data);

        while(!q.empty()) {
            pair<Node*, int> qp = q.front();
            q.pop();

            if(leftmin > qp.second)
                result.push_front(qp.first->data);
            if(rightmax < qp.second)
                result.push_back(qp.first->data);

            leftmin = min(leftmin, qp.second);
            rightmax = max(rightmax, qp.second);

            if(qp.first->left)  q.push(pair<Node*, int>((qp.first)->left, qp.second-1));
            if(qp.first->right)  q.push(pair<Node*, int>((qp.first)->right, qp.second+1));
        }

        vector<int> resv(result.begin(), result.end());
        return resv;
    }
};