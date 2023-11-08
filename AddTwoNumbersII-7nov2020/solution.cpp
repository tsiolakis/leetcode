class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        stack <ListNode*> s1, s2;
        while(l1) {
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2) {
            s2.push(l2);
            l2 = l2->next;
        }
        int sum = 0;
        while (!s1.empty() || !s2.empty()) {
            if(!s1.empty()) {
                sum += s1.top()->val;
                s1.pop();
            }
            if(!s2.empty()) {
                sum += s2.top()->val;
                s2.pop();
            }
            dummy->val = (sum%10);
            ListNode* newNode = new ListNode(sum/10);
            newNode->next = dummy;
            dummy = newNode;
            sum = sum / 10;
        }
        return dummy->val==0 ? dummy->next : dummy;
    }
};
