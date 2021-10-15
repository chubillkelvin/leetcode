class DisjointSetWithCount {
    private root: number[] = [];
    private rank: number[] = [];
    private count: number;

    constructor(size: number) {
        this.count = size;
        for (let i = 0; i < size; i++) {
            this.root[i] = i;
            this.rank[i] = 1;
        }
    }

    find(x: number): number {
        if (x === this.root[x]) {
            return x;
        }
        return (this.root[x] = this.find(this.root[x]));
    }

    union(x: number, y: number): void {
        const rootX = this.find(x);
        const rootY = this.find(y);
        if (rootX !== rootY) {
            if (this.rank[x] > this.rank[y]) {
                this.root[rootY] = rootX;
            } else if (this.rank[x] < this.rank[y]) {
                this.root[rootX] = rootY;
            } else {
                this.root[rootY] = rootX;
                this.rank[rootX]++;
            }
            this.count--;
        }
    }

    connected(x: number, y: number): boolean {
        return this.find(x) === this.find(y);
    }

    totalCounts(): number {
        return this.count;
    }
}

function earliestAcq(logs: number[][], n: number): number {
    logs.sort((a, b) => a[0] - b[0]);
    const disjointSet = new DisjointSetWithCount(n);

    for (const [time, x, y] of logs) {
        disjointSet.union(x, y);
        if (disjointSet.totalCounts() === 1) {
            return time;
        }
    }
    return -1;
}
