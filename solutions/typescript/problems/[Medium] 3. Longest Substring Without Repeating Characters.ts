function lengthOfLongestSubstring(s: string): number {
    const usedChar: Record<string, number> = {};
    let startIndex = 0;
    let maxLengthSoFar = 0;
    for (let i = 0; i < s.length; i++) {
        const currChar = s[i];
        if (usedChar[currChar] !== undefined) {
            maxLengthSoFar = Math.max(maxLengthSoFar, i - startIndex);
            startIndex = usedChar[currChar] + 1;
            Object.keys(usedChar).forEach((_) => {
                if (usedChar[_] < startIndex) {
                    delete usedChar[_];
                }
            });
        }
        usedChar[currChar] = i;
    }
    maxLengthSoFar = Math.max(maxLengthSoFar, s.length - startIndex);
    return maxLengthSoFar;
}
