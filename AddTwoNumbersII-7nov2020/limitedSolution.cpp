//works but is limited by unsigned __int128 bounds
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    unsigned __int128 listDigitsToNumber(ListNode *iter) {
        unsigned __int128 sum = 0;
        while (iter != nullptr) {
            sum = sum*10 + iter->val;
            iter = iter->next;
        }
        return sum;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned __int128 value = listDigitsToNumber(l1) + listDigitsToNumber(l2);
        ListNode* l = new ListNode(value%10);
        value = value/10;
        ListNode* ltemp1 = l;
        ListNode* ltemp2 = l;
        while (value != 0) {
            ltemp2 = new ListNode(value%10);
            ltemp2->next = ltemp1;
            ltemp1 = ltemp2;
            value = value/10;
        }
        return ltemp2;
    }
};
