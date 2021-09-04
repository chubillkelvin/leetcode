function generateParenthesis(n: number): string[] {
    if (n === 1) {
        return ["()"];
    }
    if (n === 2) {
        return ["()()", "(())"];
    }
    const result = [];
    for (const entry of generateParenthesis(n - 1)) {
        for (let i = 0; i <= entry.length; i++) {
            result.push(entry.slice(0, i) + "()" + entry.slice(i));
        }
    }
    return [...new Set(result)];
}
