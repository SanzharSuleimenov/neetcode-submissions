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
    map<int, Node*> nodes;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        int current = node->val;
        if (nodes.contains(current)) {
            return nodes[current];
        }
        nodes[current] = new Node(current);
        
        for (Node* next: node->neighbors) {
            nodes[current]->neighbors.push_back(cloneGraph(next));
        }

        return nodes[current];
    }

};
