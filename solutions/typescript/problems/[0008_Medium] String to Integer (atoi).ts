function myAtoi(s: string): number {
    const ans = parseInt(s);
    if (!ans) {
        return 0;
    }
    if (ans < -2147483648) {
        return -2147483648;
    }
    if (ans > 2147483647) {
        return 2147483647;
    }
    return ans;
}
