class RanNode {
    val: number;
    next: RanNode | null;
    random: RanNode | null;
    constructor(val?: number, next?: RanNode, random?: RanNode) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
        this.random = random === undefined ? null : random;
    }
}

function copyRandomList(head: RanNode | null): RanNode | null {
    if (head === null) return null;

    let curr: RanNode | null = head;
    // First pass - create duplicate nodes
    while (curr) {
        const next = curr.next;
        curr.next = new RanNode(curr.val, next, curr.random);
        curr = next;
    }
    // Second pass - update random pointers of the duplicate nodes
    curr = head.next;
    while (curr) {
        curr.random = curr.random?.next || null;
        curr = curr.next?.next || null;
    }
    // Third pass - remove original nodes
    const newHead = head.next;
    curr = head;
    while (curr) {
        const next = curr.next;
        curr.next = next?.next || null;
        curr = next;
    }
    return newHead;
}
