// Definition for singly-linked list.
class ListNode {
    val: number;
    next: ListNode | null;
    constructor(val?: number, next?: ListNode | null) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
    }
}

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    if (l1 === null && l2 === null) {
        return null;
    }

    const sum = (l1?.val ?? 0) + (l2?.val ?? 0);
    if (sum >= 10) {
        if (l1?.next) {
            l1.next.val++;
            return new ListNode(sum - 10, addTwoNumbers(l1.next, l2?.next || null));
        } else {
            return new ListNode(sum - 10, addTwoNumbers(new ListNode(1, null), l2?.next || null));
        }
    } else {
        return new ListNode(sum, addTwoNumbers(l1?.next || null, l2?.next || null));
    }
}
