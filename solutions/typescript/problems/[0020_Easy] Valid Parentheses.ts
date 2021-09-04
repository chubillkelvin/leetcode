function isValid(s: string): boolean {
    const IS_OPEN_BRACKET = {
        "(": true,
        ")": false,
        "{": true,
        "}": false,
        "[": true,
        "]": false,
    };

    const CLOSE_BRACKET_MAP = {
        "(": ")",
        "{": "}",
        "[": "]",
    };

    const currentOpenBrackets = [];

    for (const char of s) {
        if (IS_OPEN_BRACKET[char]) {
            currentOpenBrackets.push(char);
        } else if (currentOpenBrackets.length > 0 && char === CLOSE_BRACKET_MAP[currentOpenBrackets[currentOpenBrackets.length - 1]]) {
            currentOpenBrackets.pop();
        } else {
            return false;
        }
    }
    return currentOpenBrackets.length === 0;
}
