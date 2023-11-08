//never made it work..
//
//
//
//
//
//
//
//
//
//
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
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
    void fillCups (double cupsPoured) {
        std::cout << "cupsPoured - (int)cupsPoured" <<  cupsPoured - (int)cupsPoured << '\n';
        this->pour(cupsPoured - (int)cupsPoured);
        for (int i = 0; i < (int)cupsPoured; i++) {
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
    int binomialCoefficients(int n, int k) {
        int C[k+1];
        memset(C, 0, sizeof(C));
        C[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
        }
        return C[k];
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0) {
            return 0;
        }
        std::cout << "poured = " << poured << '\n';
        std::cout << "query_row = " << query_row << '\n';
        std::cout << "query_glass = " << query_glass << '\n';
        int lastFullRow = -1;
        for (int count = 1; poured >= count; count += (2<<lastFullRow)) {
            lastFullRow += 1;
        }
        std::cout << "lastFullRow = "<< lastFullRow << '\n';
        if (query_row <= lastFullRow)
            return 1;
        int indexOfAnswerGlass = lastFullRow + query_glass + 1;
        std::cout <<"indexOfAnswerGlass = " << indexOfAnswerGlass << '\n';

        poured -= ((lastFullRow+2)*(lastFullRow+3))/2;
        std::cout << "corrected poured = " << poured << '\n';
        // int numberOfGlasses is the number of glasses starting from lastFullRow up untill the row we care about
        //1+2+3+4+...+n = n(n+1)/2, query_row is 0 indexed, discard all the glasses that are full
        int numberOfGlasses = ((query_row + 1) * (query_row + 2))/2 - ((lastFullRow + 1)*(lastFullRow))/2;
        std::cout << "numberOfGlasses = "<< numberOfGlasses << '\n';

        //we allocate space only for the subpyramid necessary to our calculations
        Node **n = new Node*[numberOfGlasses]; //create tree (subpyramid of glasses)
        int i = 0;
        for ( ;i <= lastFullRow; i++) {
            n[i] = new Node(1);     //every glass is initially empty
        }
        for (; i < numberOfGlasses; i++) {
            n[i] = new Node(0);
        }

        int j = lastFullRow + 1;
        for (int i = 0; i < (numberOfGlasses - (query_row+1)); i++) {
            if (i == j*(j+1)/2) //basically the same math as before
                j++;
            NEWCHIDLREN(i , i+j, i+j+1)
        }
        //create coefficients which are equal to binomial coefficients over 2^lastFullRow
        double* coefficients = new double[lastFullRow+1];
        for (i = 0; i <= lastFullRow/2; i++) {
            coefficients[i] = (double)(binomialCoefficients(lastFullRow, i))/(2<<lastFullRow-1) ;
            std::cout << coefficients[i] << "\t";
        }
        while (i < lastFullRow+1) {
            coefficients[i] = coefficients[lastFullRow - i];
            std::cout << coefficients[i] << '\t';
            i++;

        }

        for (int times = 0; times < lastFullRow+1; times++) {
            std::cout << "\n(double)poured*coefficients[times]" << (double)poured*coefficients[times];
            n[times]->fillCups((double)poured*coefficients[times]);
        }
        return n[indexOfAnswerGlass]->val;
    }
};
int main(int argc, char const *argv[]) {
    Solution* sol = new Solution();
    double ans = sol->champagneTower(31,50,0);
    std::cout <<"\nans = " << ans;


    return 0;
}
