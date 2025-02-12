#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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

class Solution {
public:
    unordered_map<Node*, Node*> oldMap;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if(oldMap.find(node) != oldMap.end()) {
            return oldMap[node];
        }

        Node* curr = new Node(node->val);
        oldMap[node] = curr;

        for(auto n : node->neighbors) {
            curr->neighbors.push_back(cloneGraph(n));
        }

        return curr;
    }
};

// Helper function to print the graph
void printGraph(Node* node, unordered_map<Node*, bool>& visited) {
    if (!node || visited[node]) return;
    visited[node] = true;
    cout << "Node " << node->val << " with neighbors: ";
    for (auto n : node->neighbors) {
        cout << n->val << " ";
    }
    cout << endl;
    for (auto n : node->neighbors) {
        printGraph(n, visited);
    }
}

int main() {
    // Create a sample graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Solution solution;
    Node* clonedGraph = solution.cloneGraph(node1);

    // Print the original graph
    cout << "Original graph:" << endl;
    unordered_map<Node*, bool> visited;
    printGraph(node1, visited);

    // Print the cloned graph
    cout << "Cloned graph:" << endl;
    visited.clear();
    printGraph(clonedGraph, visited);

    return 0;
}