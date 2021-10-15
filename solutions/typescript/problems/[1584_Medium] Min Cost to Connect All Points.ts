// @ts-ignore
class DisjointSet {
    private root: number[] = [];
    private rank: number[] = [];

    constructor(size: number) {
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
        }
    }

    connected(x: number, y: number): boolean {
        return this.find(x) === this.find(y);
    }
}

function minCostConnectPoints(points: number[][]): number {
    const costs: [number, number, number][] = [];
    for (let i = 0; i < points.length; i++) {
        for (let j = i + 1; j < points.length; j++) {
            const manhattanDistance = Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1] - points[j][1]);
            costs.push([i, j, manhattanDistance]);
        }
    }
    costs.sort((a, b) => a[2] - b[2]);

    const disjointSet = new DisjointSet(points.length);
    let numberOfEdges = 0;
    let totalCost = 0;

    while (numberOfEdges < points.length - 1) {
        for (const [node1, node2, cost] of costs) {
            if (!disjointSet.connected(node1, node2)) {
                disjointSet.union(node1, node2);
                totalCost += cost;
                numberOfEdges++;
            }
        }
    }
    return totalCost;
}
