#define NEWCHIDLREN(i , c1, c2) n[i]->children.push_back(n[c1]); n[i]->children.push_back(n[c2]);

class Node { //a node represents a cup
public:
    double val;    //how full the cup is
    vector<Node*> children; //children are the cups directly below it
    Node() {
        val = 0;
        children = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        children = vector<Node*>();
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
    bool isFull() {
        if (this->val > 1)
            return true;
        return false;
    }
    void fillCups (int cupsPoured) {
        for (int i = 0; i < cupsPoured; i++) {
            this->pour(1.0);
        }
    }
    void pour(double amount) {
        if (this->val == 1) {
            for (Node* child : children){
                child->pour(amount/2);
            }
        }
        this->val += amount;
        if (this->isFull()) {
            amount = this->val - 1;
            this->val = 1;
            for (Node* child : children){
                child->pour(amount/2);
            }
        }
    }
};
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
    if (poured == 0) {
        return 0;
    }
    int lastFullRow = -1;
    for (int count = 1; poured >= count; count += (2<<lastFullRow)) {
        lastFullRow += 1;
    }
    if (query_row <= lastFullRow)
        return 1;
        // int numberOfGlasses is the number of glasses up untill the row we care about
        int numberOfGlasses = ((query_row + 1) * (query_row + 2))/2; //1+2+3+4+...+n = n(n+1)/2 and query_row is 0 indexed


        Node **n = new Node*[numberOfGlasses]; //create tree (pyramid of glasses)
        for (int i = 0; i < numberOfGlasses; i++) {
            n[i] = new Node(0);     //every glass is initially empty

        }
        int j = 1;
        for (int i = 0; i < (numberOfGlasses - (query_row+1)); i++) {
            if (i == j*(j+1)/2) //basically the same math as before
                j++;
            NEWCHIDLREN(i , i+j, i+j+1)
        }

        n[0]->fillCups(poured);
        int indexOfAnswerGlass = ((query_row * (query_row + 1)) / 2) + query_glass;
        std::cout << indexOfAnswerGlass << '\n';
        return n[indexOfAnswerGlass]->val;
    }
};
