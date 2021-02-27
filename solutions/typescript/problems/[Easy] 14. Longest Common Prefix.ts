function longestCommonPrefix(strs: string[]): string {
    if (strs.length === 0) {
        return "";
    }

    let result = "";

    const firstStr = strs[0];
    for (let i = 0; i < firstStr.length; i++) {
        const char = firstStr[i];
        if (strs.every((_) => _[i] === char)) {
            result += char;
        } else {
            return result;
        }
    }

    return result;
}
