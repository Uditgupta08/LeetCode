/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, Node* clone, unordered_map<Node*,Node*>& m){
        for(Node* n : node->neighbors){
            if(m.find(n) == m.end()){
                Node* new_clone = new Node(n->val);
                m[n] = new_clone;
                clone->neighbors.push_back(new_clone);
                dfs(n,new_clone,m);
            }else{
                clone->neighbors.push_back(m[n]);
            }
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        Node* clone_node = new Node(node->val);
        unordered_map<Node*,Node*> m;
        m[node] = clone_node;
        dfs(node,clone_node,m);
        return clone_node;
    }
};