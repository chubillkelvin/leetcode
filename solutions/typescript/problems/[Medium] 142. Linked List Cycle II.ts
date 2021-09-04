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

function detectCycle(head: ListNode | null): ListNode | null {
    const visited: Set<ListNode> = new Set();
    let pointer = head;
    while (pointer) {
        if (visited.has(pointer)) {
            return pointer;
        } else {
            visited.add(pointer);
            pointer = pointer.next;
        }
    }
    return null;
}
