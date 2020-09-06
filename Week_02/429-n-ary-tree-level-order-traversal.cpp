/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<Node*> currentLevel;
        queue<Node*> nextLevel;
        currentLevel.push(root);
        vector<int> levelResult;

        do {
            Node* node = currentLevel.front();
            currentLevel.pop();
            levelResult.push_back(node->val);

            for (Node* child : node->children) {
                if (child) nextLevel.push(child);
            }
            
            if (currentLevel.empty()) {
                result.push_back(levelResult);
                levelResult.clear();
                currentLevel = nextLevel;
                nextLevel = queue<Node*>();
            }
        } while(!currentLevel.empty());

        return result;        
    }
};
