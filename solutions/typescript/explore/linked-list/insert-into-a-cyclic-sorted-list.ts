/**
 * Definition for node.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: Node) {
 *         this.val = (val===undefined ? 0 : val);
 *         this.next = (next===undefined ? null : next);
 *     }
 * }
 */

function insert(head: ListNode | null, insertVal: number): ListNode | null {
    const newNode = new ListNode(insertVal);

    if (head === null) {
        newNode.next = newNode;
        return newNode;
    }

    let curr: ListNode = head;
    let next: ListNode = head.next!;
    // eslint-disable-next-line no-constant-condition
    while (true) {
        const canInsertInMiddle = insertVal >= curr.val && insertVal <= next.val;
        const isEndOfList = curr.val > next.val && next.val < next.next!.val;
        const canInsertAtEnd = insertVal >= curr.val && isEndOfList;
        const canInsertAtFront = insertVal <= next.val && isEndOfList;
        const hasCompletedCycle = next === head;
        if (canInsertInMiddle || canInsertAtEnd || canInsertAtFront || hasCompletedCycle) {
            newNode.next = next;
            curr.next = newNode;
            break;
        }
        curr = next;
        next = next.next!;
    }
    return head;
}
