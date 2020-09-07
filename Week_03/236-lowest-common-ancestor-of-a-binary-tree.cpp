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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
        return lowestCommonAncestorInternal(root, p, q);
    }
private:
    TreeNode* lowestCommonAncestorInternal(TreeNode* root,  TreeNode* p, TreeNode* q) {
        if (contain(root, p) && contain(root, q)) {
            // 如果当前节点同时包含两个节点，继续往下尝试查找更深的节点
            TreeNode* lowest = lowestCommonAncestorInternal(root->left, p, q);
            if (!lowest) {
                lowest = lowestCommonAncestorInternal(root->right, p, q);
            }
            if (!lowest) lowest = root;
            return lowest;
        } else {
            return nullptr;
        }
    }

    /**
     * 树是否包含指定节点 node
     */
    bool contain(TreeNode* root, TreeNode* node) {
        if (root == nullptr) return false;
        if (root == node) return true;
        return contain(root->left, node) || contain(root->right, node);
    }
};
