
// User function Template for C++

// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
    private:
    int helper(Node *root, int can, map<pair<Node *, int>, int> &mp) {
        if(root == NULL) return 0;
        int ans = INT_MIN;
        
        if(mp.count({root, can}) != 0) return mp[{root, can}];
        
        if(can) ans = root -> data + helper(root -> left, 0, mp) + helper(root -> right, 0, mp);
        
        ans = max(ans, helper(root -> left, 1, mp) + helper(root -> right, 1, mp));
        
        return mp[{root, can}] = ans;
        
    }
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // code here
        map<pair<Node *, int>, int> mp;
        return helper(root, 1, mp);

    }
};

