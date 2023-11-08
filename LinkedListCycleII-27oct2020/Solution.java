

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode caller = head;
        ListNode curr = caller;
        int callerCount = 0;
        int currCount = 0;
        while (caller != null) {
            while (curr != caller) {
                curr = curr.next;
                currCount += 1;
            }
            if (callerCount != currCount)
                break;

            callerCount += 1;
            currCount = 0;
            caller = caller.next;
            curr = head;

        }
        return caller;
    }
}
