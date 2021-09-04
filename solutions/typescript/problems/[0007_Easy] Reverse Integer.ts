function reverse(x: number): number {
    const MAX_INTEGER = 2147483647;
    const MIN_INTEGER = -2147483648;
    const result = parseInt(x.toString().split("").reverse().join("")) * (x < 0 ? -1 : 1) || 0;
    return result <= MAX_INTEGER && result >= MIN_INTEGER ? result : 0;
}
