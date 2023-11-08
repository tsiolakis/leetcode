#include <iostream>
#include <vector>
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
private:
    vector<bool> visited;
    int graphSize = 0;
    Node** clonedGraph;
    bool* visited2;

    //remember that the maximum value is the size of the graph
    void determineGraphSize(Node* node);
    void helper(Node* node);
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            Node* temp;
            return temp;
        }
        this->visited.push_back(1);
        graphSize = 1;
        determineGraphSize(node);
        std::cout << "The size of the graph to be cloned is " << this->graphSize << '\n';

        clonedGraph = new Node*[graphSize];
        for (int i = 0; i < graphSize; i++){
            clonedGraph[i] = new Node;
            clonedGraph[i]->val = i + 1;
        }
        visited2 = new bool[graphSize]();
        visited2[0] = true;
        helper(node);
        return clonedGraph[0];
    }
};

void Solution::determineGraphSize(Node* node) {
    if (node->val == 0) {graphSize = 0; return;}
    if (node->neighbors.empty()) {return;}

    for (auto i = node->neighbors.begin(); i != node->neighbors.end(); i++) {
        if ((*i)->val > graphSize) {
            graphSize = (*i)->val;
            this->visited.resize(graphSize, 0);
        }
        if (!(this->visited[((*i)->val) - 1])) {
            this->visited[((*i)->val) - 1] = true;
            determineGraphSize(*i);
        }
    }
    return;
}
void Solution::helper(Node* node) {
    for (auto i = node->neighbors.begin(); i != node->neighbors.end(); i++) {
        clonedGraph[(node->val) - 1]->neighbors.push_back(clonedGraph[((*i)->val) - 1]);
        if (!(visited2[((*i)->val) - 1])) {
            visited2[((*i)->val) - 1] = true;
            helper(*i);
        }
    }
}

int main() {
    Node *n1, *n2, *n3, *n4;
/*    n1 = new Node(1);
    n2 = new Node(2);
    n3 = new Node(3);
    n4 = new Node(4);
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);
    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);*/
    Solution sol;
    Node* answer = sol.cloneGraph(n1);

    return 0;
}
