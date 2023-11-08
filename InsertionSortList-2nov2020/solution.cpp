struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* beforeHead = new ListNode(0, head);
        ListNode* temp;
        ListNode* iterator1 = beforeHead;
        ListNode* iterator2 = head;
        while (iterator2->next != nullptr) {
            while (iterator1 != iterator2) {
                if (iterator2->next->val <= iterator1->next->val){
                    temp = iterator2->next->next;
                    iterator2->next->next = iterator1->next;
                    if (iterator1->next == beforeHead->next)
                        beforeHead = iterator2->next;
                    iterator2->next = temp;
                    break;
                }
                iterator1 = iterator1->next;
            }
            iterator2 = iterator2->next;
            iterator1 = beforeHead->next;
        }
        return beforeHead->next;
    }
};
