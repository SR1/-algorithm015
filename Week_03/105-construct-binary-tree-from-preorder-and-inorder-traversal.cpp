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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeInternal(preorder, inorder);
    }
private:
    TreeNode* buildTreeInternal(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        int root = preorder[0]; // 得到根节点
        TreeNode* node = new TreeNode(root);

        // 查找根节点在中序遍历的索引
        int rootIdx = -1;
        for(int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root) {
                rootIdx = i;
                break;
            }
        }

        if (rootIdx >= 0) {
            int leftSize = rootIdx - 0;
            int rightSize = inorder.size() - 1 - rootIdx;

            {
                // left tree
                vector<int> leftPreorder;
                for (int i = 0; i < leftSize; i++) {
                    leftPreorder.push_back(preorder[i + 1]);
                }
                vector<int> leftInorder;
                for (int i = 0; i < leftSize; i++) {
                    leftInorder.push_back(inorder[i]);
                }
                
                node->left = buildTreeInternal(leftPreorder, leftInorder);
            }

            {
                // right tree
                vector<int> rightPreorder;
                for (int i = 0; i < rightSize; i++) {
                    rightPreorder.push_back(preorder[leftSize + i + 1]);
                }
                vector<int> rightInorder;
                for (int i = 0; i < rightSize; i++) {
                    rightInorder.push_back(inorder[rootIdx + 1 + i]);
                }

                node->right = buildTreeInternal(rightPreorder, rightInorder);
            }
        }

        return node;
    }
};
