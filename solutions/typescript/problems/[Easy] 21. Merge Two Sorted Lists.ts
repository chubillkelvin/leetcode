// Definition for singly-linked list.
// eslint-disable-next-line @typescript-eslint/ban-ts-comment
// @ts-ignore
class ListNode {
    val: number;
    next: ListNode | null;
    constructor(val?: number, next?: ListNode | null) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
    }
}

function mergeTwoLists(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const pointerToHead = new ListNode();
    let currentNode = pointerToHead;
    while (l1 || l2) {
        if (l1 && l2) {
            if (l1.val <= l2.val) {
                currentNode.next = l1;
                currentNode = currentNode.next;
                l1 = l1.next;
            } else {
                currentNode.next = l2;
                currentNode = currentNode.next;
                l2 = l2.next;
            }
        } else if (l1) {
            currentNode.next = l1;
            currentNode = currentNode.next;
            l1 = l1.next;
        } else if (l2) {
            currentNode.next = l2;
            currentNode = currentNode.next;
            l2 = l2.next;
        }
    }
    return pointerToHead.next;
}
