/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

// Floyd's Cycle Finding Algorithm
function hasCycle(head: ListNode | null): boolean {
    let pointer1 = head || null;
    let pointer2 = head?.next || null;

    while (pointer1 && pointer2) {
        if (pointer1 === pointer2) return true;
        pointer1 = pointer1?.next || null;
        pointer2 = pointer2?.next?.next || null;
    }
    return false;
}
