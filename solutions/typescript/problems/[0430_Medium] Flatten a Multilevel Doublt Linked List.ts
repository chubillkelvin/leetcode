// @ts-ignore
class MyMultilevelNode {
    val: number;
    prev: MyMultilevelNode | null;
    next: MyMultilevelNode | null;
    child: MyMultilevelNode | null;
    constructor(val?: number, prev?: MyMultilevelNode | null, next?: MyMultilevelNode | null, child?: MyMultilevelNode | null) {
        this.val = val === undefined ? 0 : val;
        this.prev = prev === undefined ? null : prev;
        this.next = next === undefined ? null : next;
        this.child = child === undefined ? null : child;
    }
}

function flatten(head: MyMultilevelNode | null): MyMultilevelNode | null {
    const headPointer = new MyMultilevelNode(0, null, head);
    let curr = head;

    while (curr) {
        if (curr.child) {
            const next = curr.next;
            curr.next = flatten(curr.child);
            curr.child.prev = curr;
            curr.child = null;
            while (curr.next) {
                curr = curr.next;
            }
            if (next) {
                curr.next = next;
                next.prev = curr;
            }
        }
        curr = curr.next;
    }

    return headPointer.next;
}
