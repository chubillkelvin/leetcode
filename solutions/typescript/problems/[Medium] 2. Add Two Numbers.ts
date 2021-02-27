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

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const head = new ListNode();
    let currentNode: ListNode = head;
    while (l1 || l2) {
        const sum: number = (l1?.val ?? 0) + (l2?.val ?? 0) + currentNode.val;
        currentNode.val = sum % 10;
        currentNode.next = new ListNode(sum >= 10 ? 1 : 0);
        l1 = l1?.next || null;
        l2 = l2?.next || null;
        if (l1 || l2) {
            currentNode = currentNode.next;
        } else if (currentNode.next.val === 0) {
            currentNode.next = null;
        }
    }
    return head;
}
