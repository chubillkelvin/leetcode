function convert(s: string, numRows: number): string {
    if (numRows === 1) {
        return s;
    }
    const convertedRows = new Array(numRows).fill("");
    for (let i = 0; i < s.length; i++) {
        const index = i % (numRows * 2 - 2);
        convertedRows[index < numRows ? index : 2 * numRows - index - 2] += s[i];
    }
    return convertedRows.join("");
}
