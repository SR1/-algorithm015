/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
private:
    void traversal(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        result.push_back(node->val);
        if (node->left) traversal(node->left, result);
        if (node->right) traversal(node->right, result);
    }
};
