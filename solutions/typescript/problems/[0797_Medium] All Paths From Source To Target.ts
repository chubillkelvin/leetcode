function allPathsSourceTarget(graph: number[][]): number[][] {
    const possiblePaths: number[][] = [];

    function dfs(path: number[]): void {
        const curr = path[path.length - 1];
        if (curr === graph.length - 1) {
            possiblePaths.push(path);
        } else {
            for (const possibleNode of graph[curr]) {
                if (!path.includes(possibleNode)) {
                    dfs([...path, possibleNode]);
                }
            }
        }
    }

    dfs([0]);

    return possiblePaths;
}
