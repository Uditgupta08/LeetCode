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
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        queue<Node*> q;
        int depth = 0;
        q.push(root);
        while (!q.empty()) {
            int curr = q.size();
            while (curr--) {
                Node* currNode = q.front();
                q.pop();
                for (auto it : currNode->children) {
                    q.push(it);
                }
            }
            depth++;
        }
        return depth;
    }
};