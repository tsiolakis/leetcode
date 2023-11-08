#include <iostream>
#include <vector>
using namespace std;
#define NEWCHIDLREN(i , c1, c2) n[i-1]->children.push_back(n[c1-1]); n[i-1]->children.push_back(n[c2-1]);

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
int main() {
    Node **n = new Node*[36];
    for (int i = 0; i < 36; i++) {
        n[i] = new Node(0);
    }
    {
    NEWCHIDLREN(1 , 2, 3)
    NEWCHIDLREN(2 , 4, 5)
    NEWCHIDLREN(3 , 5, 6)
    NEWCHIDLREN(4 , 7, 8)
    NEWCHIDLREN(5 , 8, 9)
    NEWCHIDLREN(6 , 9, 10)
    NEWCHIDLREN(7 , 11, 12)
    NEWCHIDLREN(8 , 12, 13)
    NEWCHIDLREN(9 , 13, 14)
    NEWCHIDLREN(10 , 14, 15)
    NEWCHIDLREN(11 , 16, 17)
    NEWCHIDLREN(12 , 17, 18)
    NEWCHIDLREN(13 , 18, 19)
    NEWCHIDLREN(14 , 19, 20)
    NEWCHIDLREN(15 , 20, 21)
    NEWCHIDLREN(16 , 22, 23)
    NEWCHIDLREN(17 , 23, 24)
    NEWCHIDLREN(18 , 24, 25)
    NEWCHIDLREN(19 , 25, 26)
    NEWCHIDLREN(20 , 26, 27)
    NEWCHIDLREN(21 , 27, 28)
    NEWCHIDLREN(22 , 29, 30)
    NEWCHIDLREN(23 , 30, 31)
    NEWCHIDLREN(24 , 31, 32)
    NEWCHIDLREN(25 , 32, 33)
    NEWCHIDLREN(26 , 33, 34)
    NEWCHIDLREN(27 , 34, 35)
    NEWCHIDLREN(28 , 35, 36)}

//    for (int ep = 1; ep < 20; ep++) {
    int ep = 15;
        std::cout << "ep " << ep << "\n\n";
        n[0]->fillCups(ep);
        int j = 0;
        int cupsPerRow = 1;
        for (int i = 0; i < 36; i++) {
            j++;
            if (j == cupsPerRow) {
                std::cout << "Row: " << cupsPerRow-1 << '\n';
                j = 1;
                cupsPerRow += 1;
            }
            std::cout <<"cup "<< i <<" = " << n[i]->val << '\n';
        }
        std::cout  << "\n\n";
//    }


    return 0;
}
