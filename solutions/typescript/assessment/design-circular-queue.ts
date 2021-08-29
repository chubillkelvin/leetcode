class CircularQueueListNode {
    value: number;
    prev: CircularQueueListNode | null = null;
    next: CircularQueueListNode | null = null;

    constructor(value: number) {
        this.value = value;
    }

    getValue() {
        return this.value;
    }

    getPrev() {
        return this.prev;
    }

    setPrev(prev: CircularQueueListNode | null) {
        this.prev = prev;
    }

    getNext() {
        return this.next;
    }

    setNext(next: CircularQueueListNode | null) {
        this.next = next;
    }
}

class MyCircularQueue {
    maxSize: number;
    currSize: number = 0;
    head: CircularQueueListNode | null = null;
    tail: CircularQueueListNode | null = null;

    constructor(k: number) {
        this.maxSize = k;
    }

    enQueue(value: number): boolean {
        if (this.currSize === this.maxSize) {
            return false;
        } else {
            const node = new CircularQueueListNode(value);
            if (!this.head) {
                this.head = node;
            }
            node.setNext(this.head);

            if (this.tail) {
                this.tail.setNext(node);
                node.setPrev(this.tail);
            } else {
                node.setPrev(node);
            }
            this.tail = node;
            this.currSize++;
            return true;
        }
    }

    deQueue(): boolean {
        if (this.currSize === 0) {
            return false;
        } else {
            if (this.currSize === 1) {
                this.head = null;
                this.tail = null;
            } else {
                this.head = this.head!.getNext();
                this.tail!.setNext(this.head);
            }
            this.currSize--;
            return true;
        }
    }

    Front(): number {
        return this.head?.getValue() ?? -1;
    }

    Rear(): number {
        return this.tail?.getValue() ?? -1;
    }

    isEmpty(): boolean {
        return this.head === null;
    }

    isFull(): boolean {
        return this.currSize === this.maxSize;
    }
}
